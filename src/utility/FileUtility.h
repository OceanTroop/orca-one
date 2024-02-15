#pragma once

#include <FS.h>
#include <TFT_eSPI.h>
#include <JPEGDecoder.h>
#include <SD.h>

namespace Utility
{
    class FileUtility
    {
    public:
        // static void listDir(fs::FS &fs, const char *dirname, uint8_t levels);
        // static void createDir(fs::FS &fs, const char *path);
        // static void removeDir(fs::FS &fs, const char *path);
        static String readFile(fs::FS &fs, const char *path);
        static void writeFile(fs::FS &fs, const char *path, const char *message);
        // static void appendFile(fs::FS &fs, const char *path, const char *message);
        // static void renameFile(fs::FS &fs, const char *path1, const char *path2);
        // static void deleteFile(fs::FS &fs, const char *path);

        static void drawJpeg(fs::FS &fs, std::shared_ptr<TFT_eSPI>tft, const char *path, int x, int y, int displayWidth, int displayHeight);
    };
}
