#include "RunScreen.h"

using namespace Applications::Infrared::TVBGone;

void RunScreen::stop()
{
    if (this->_isRunning)
        this->_stopping = true;

    while (this->_stopping || this->_isRunning)
    {
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void RunScreen::_execute()
{
    this->_isRunning = true;
    this->_stopping = false;

    for (int i = 1; i <= 100; i++)
    {
        if (this->_stopping)
            break;

        this->_progressBar.setProgress(i);
        this->_progressBar.render(this->_tft);

        // delay(500);
        vTaskDelay(pdMS_TO_TICKS(100));

        // TODO
    }

    this->_isRunning = false;
    this->_stopping = false;
}

void taskDoExecute(void *screenPointer)
{
    auto screen = (RunScreen *)screenPointer;
    screen->_execute();

    vTaskDelete(nullptr);
}

void RunScreen::start()
{
    if (this->_isRunning)
        return;

    xTaskCreatePinnedToCore(taskDoExecute, "taskDoExecute", configMINIMAL_STACK_SIZE + 1024, this, 1, nullptr, portNUM_PROCESSORS - 1);
}

void RunScreen::render(std::shared_ptr<TFT_eSPI> tft)
{
    auto displayInterface = DeviceBase::getInstance()->getInterfaces().displayInterface;
    auto displaySettings = displayInterface->getSettings();
    int margin = 10;
    int height = 25;

    this->setTextSizeSmall(tft);

    String title;

    if (this->_type == TVBGoneType::AmericasAsia)
        title = "Americas / Asia";
    else
        title = "EU/MidEast/Africa";

    auto titleX = (displaySettings.width - tft->textWidth(title)) / 2;

    if (titleX < 0)
        titleX = 0;

    tft->drawString(title, titleX, 5);
    tft->setCursor(0, displaySettings.height - 35);
    tft->println("Press any button to stop");

    this->setTextSizeSmall(tft);
    this->_progressBar.setPosition(margin, (displaySettings.height - height) / 2);
    this->_progressBar.setSize(displaySettings.width - (margin * 2), height);
    this->_progressBar.setProgress(0);
    this->_progressBar.render(tft);
}

void RunScreen::buttonSelectPressed()
{
    this->stop();
    Screen::buttonBackPressed();
}

void RunScreen::buttonNextPressed()
{
    this->stop();
    Screen::buttonBackPressed();
}

void RunScreen::buttonPreviousPressed()
{
    this->stop();
    Screen::buttonBackPressed();
}

void RunScreen::buttonBackPressed()
{
    this->stop();
    Screen::buttonBackPressed();
}
