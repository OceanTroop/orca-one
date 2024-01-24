#include "ScreenManager.h"

using namespace Applications::Services::GUI;

ScreenManager *ScreenManager::_current = nullptr;
bool ScreenManager::_initialized = false;

ScreenManager::ScreenManager(std::shared_ptr<TFT_eSPI> tft)
{
    this->_tft = tft;

    if (ScreenManager::_initialized)
    {
        throw std::runtime_error("ScreenManager previous initialized. Please, define ScreenManager only time. Use: ScreenManager::getCurrent()");
    }

    ScreenManager::_initialized = true;
    ScreenManager::_current = this;
}

void ScreenManager::render(std::shared_ptr<TFT_eSPI> tft)
{
    this->_currentScreen->render(tft);
}

const ScreenManager *ScreenManager::getCurrent()
{
    return ScreenManager::_current;
}

void ScreenManager::render()
{
    this->render(this->_tft);
}

void ScreenManager::setCurrentScreen(std::shared_ptr<Screen> currentScreen)
{
    currentScreen->setPrevious(this->_currentScreen);
    this->_currentScreen = currentScreen;
    this->render();
}

std::shared_ptr<Screen> ScreenManager::getCurrentScreen()
{
    return this->_currentScreen;
}
