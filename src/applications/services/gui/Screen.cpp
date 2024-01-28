#include "Screen.h"
#include "ScreenManager.h"

using namespace Applications::Services::GUI;

Screen::Screen(std::shared_ptr<TFT_eSPI> tft)
{
    this->_tft = tft;
}

void Screen::render()
{
    this->render(this->_tft);
}

void Screen::setPreviousScreen(Screen *previous)
{
    this->_previousScreen = previous;
}

Screen *Screen::getPreviousScreen()
{
    return this->_previousScreen;
}

void Screen::buttonPreviousPressed()
{
}

void Screen::buttonBackPressed()
{
    if (this->_previousScreen != nullptr)
        ScreenManager::setCurrentScreen(this->_previousScreen);
}

void Screen::buttonSelectPressed()
{
}

void Screen::buttonNextPressed()
{
}
