#include "FileUtility.h"

#define minimum(a, b) (((a) < (b)) ? (a) : (b))

using namespace Utility;

// void FileUtility::listDir(fs::FS &fs, const char *dirname, uint8_t levels)
// {
//     Serial.printf("Listing directory: %s\n", dirname);

//     File root = fs.open(dirname);
//     if (!root)
//     {
//         Serial.println("Failed to open directory");
//         return;
//     }
//     if (!root.isDirectory())
//     {
//         Serial.println("Not a directory");
//         return;
//     }

//     File file = root.openNextFile();
//     while (file)
//     {
//         if (file.isDirectory())
//         {
//             Serial.print("  DIR : ");
//             Serial.println(file.name());
//             if (levels)
//             {
//                 listDir(fs, file.path(), levels - 1);
//             }
//         }
//         else
//         {
//             Serial.print("  FILE: ");
//             Serial.print(file.name());
//             Serial.print("  SIZE: ");
//             Serial.println(file.size());
//         }
//         file = root.openNextFile();
//     }
// }

// void FileUtility::createDir(fs::FS &fs, const char *path)
// {
//     Serial.printf("Creating Dir: %s\n", path);
//     if (fs.mkdir(path))
//     {
//         Serial.println("Dir created");
//     }
//     else
//     {
//         Serial.println("mkdir failed");
//     }
// }

// void FileUtility::removeDir(fs::FS &fs, const char *path)
// {
//     Serial.printf("Removing Dir: %s\n", path);
//     if (fs.rmdir(path))
//     {
//         Serial.println("Dir removed");
//     }
//     else
//     {
//         Serial.println("rmdir failed");
//     }
// }

String FileUtility::readFile(fs::FS &fs, const char *path)
{
    // Serial.printf("Reading file: %s\n", path);

    File file = fs.open(path);

    if (!file)
    {
        // Serial.println("Failed to open file for reading");
        return "";
    }

    auto contents = file.readString();

    file.close();

    return contents;
}

void FileUtility::writeFile(fs::FS &fs, const char *path, const char *message)
{
    Serial.printf("Writing file: %s\n", path);

    File file = fs.open(path, FILE_WRITE);

    if (!file)
    {
        Serial.println("Failed to open file for writing");
        return;
    }

    if (file.print(message))
    {
        Serial.println("File written");
    }
    else
    {
        Serial.println("Write failed");
    }

    file.close();
}

// void FileUtility::appendFile(fs::FS &fs, const char *path, const char *message)
// {
//     Serial.printf("Appending to file: %s\n", path);

//     File file = fs.open(path, FILE_APPEND);
//     if (!file)
//     {
//         Serial.println("Failed to open file for appending");
//         return;
//     }
//     if (file.print(message))
//     {
//         Serial.println("Message appended");
//     }
//     else
//     {
//         Serial.println("Append failed");
//     }
//     file.close();
// }

// void FileUtility::renameFile(fs::FS &fs, const char *path1, const char *path2)
// {
//     Serial.printf("Renaming file %s to %s\n", path1, path2);
//     if (fs.rename(path1, path2))
//     {
//         Serial.println("File renamed");
//     }
//     else
//     {
//         Serial.println("Rename failed");
//     }
// }

// void FileUtility::deleteFile(fs::FS &fs, const char *path)
// {
//     Serial.printf("Deleting file: %s\n", path);
//     if (fs.remove(path))
//     {
//         Serial.println("File deleted");
//     }
//     else
//     {
//         Serial.println("Delete failed");
//     }
// }

void jpegRender(std::shared_ptr<TFT_eSPI> tft, int xpos, int ypos, int displayWidth, int displayHeight);

void FileUtility::drawJpeg(fs::FS &fs, std::shared_ptr<TFT_eSPI> tft, const char *path, int x, int y, int displayWidth, int displayHeight)
{
    // Serial.println("===========================");
    // Serial.print("Drawing file: ");
    // Serial.println(filename);
    // Serial.println("===========================");

    // Open the named file (the Jpeg decoder library will close it after rendering image)
    // fs::File jpegFile = SPIFFS.open(filename, "r"); // File handle reference for SPIFFS
    File jpegFile = fs.open(path, FILE_READ); // or, file handle reference for SD library

    // ESP32 always seems to return 1 for jpegFile so this null trap does not work
    // if (!jpegFile)
    // {
    //     Serial.print("ERROR: File \"");
    //     Serial.print(path);
    //     Serial.println("\" not found!");
    //     return;
    // }

    // Use one of the three following methods to initialise the decoder,
    // the filename can be a String or character array type:

    // boolean decoded = JpegDec.decodeFsFile(jpegFile); // Pass a SPIFFS file handle to the decoder,
    // boolean decoded = JpegDec.decodeSdFile(jpegFile); // or pass the SD file handle to the decoder,
    boolean decoded = JpegDec.decodeFsFile(path); // or pass the filename (leading / distinguishes SPIFFS files)

    if (decoded)
    {
        // print information about the image to the serial port
        // jpegInfo();

        // render the image onto the screen at given coordinates
        jpegRender(tft, x, y, displayWidth, displayHeight);
    }
    // else
    // {
    //     Serial.println("Jpeg file format not supported!");
    // }
}

void jpegRender(std::shared_ptr<TFT_eSPI> tft, int xpos, int ypos, int displayWidth, int displayHeight)
{
    // retrieve infomration about the image
    uint16_t *pImg;
    int16_t mcu_w = JpegDec.MCUWidth;
    int16_t mcu_h = JpegDec.MCUHeight;
    int32_t max_x = JpegDec.width;
    int32_t max_y = JpegDec.height;

    // Jpeg images are draw as a set of image block (tiles) called Minimum Coding Units (MCUs)
    // Typically these MCUs are 16x16 pixel blocks
    // Determine the width and height of the right and bottom edge image blocks
    int32_t min_w = minimum(mcu_w, max_x % mcu_w);
    int32_t min_h = minimum(mcu_h, max_y % mcu_h);

    // save the current image block size
    int32_t win_w = mcu_w;
    int32_t win_h = mcu_h;

    // record the current time so we can measure how long it takes to draw an image
    uint32_t drawTime = millis();

    // save the coordinate of the right and bottom edges to assist image cropping
    // to the screen size
    max_x += xpos;
    max_y += ypos;

    // read each MCU block until there are no more
    while (JpegDec.readSwappedBytes())
    { // Swapped byte order read

        // save a pointer to the image block
        pImg = JpegDec.pImage;

        // calculate where the image block should be drawn on the screen
        int mcu_x = JpegDec.MCUx * mcu_w + xpos; // Calculate coordinates of top left corner of current MCU
        int mcu_y = JpegDec.MCUy * mcu_h + ypos;

        // check if the image block size needs to be changed for the right edge
        if (mcu_x + mcu_w <= max_x)
            win_w = mcu_w;
        else
            win_w = min_w;

        // check if the image block size needs to be changed for the bottom edge
        if (mcu_y + mcu_h <= max_y)
            win_h = mcu_h;
        else
            win_h = min_h;

        // copy pixels into a contiguous block
        if (win_w != mcu_w)
        {
            for (int h = 1; h < win_h - 1; h++)
            {
                memcpy(pImg + h * win_w, pImg + (h + 1) * mcu_w, win_w << 1);
            }
        }

        // draw image MCU block only if it will fit on the screen
        if (mcu_x < displayWidth && mcu_y < displayHeight)
        {
            // Now push the image block to the screen
            tft->pushImage(mcu_x, mcu_y, win_w, win_h, pImg);
        }

        else if ((mcu_y + win_h) >= displayHeight)
            JpegDec.abort();
    }

    // calculate how long it took to draw the image
    drawTime = millis() - drawTime; // Calculate the time it took

    // print the results to the serial port
    // Serial.print("Total render time was    : ");
    // Serial.print(drawTime);
    // Serial.println(" ms");
    // Serial.println("=====================================");
}
