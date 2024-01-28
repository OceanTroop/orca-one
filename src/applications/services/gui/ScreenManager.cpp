#include "ScreenManager.h"
#include "../../../domain/entities/DeviceBase.h"

using namespace Applications::Services::GUI;
using namespace Domain::Entities;

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

    auto buttonsInterface = DeviceBase::getCurrent()->getInterfaces().buttonsInterface;

    auto menuScreen = this;

    if (buttonsInterface != nullptr)
    {
        buttonsInterface->registerOnClickNext([this]()
                                              { _currentScreen->buttonNextPressed(); });

        buttonsInterface->registerOnClickPrevious([this]()
                                                  { _currentScreen->buttonPreviousPressed(); });

        buttonsInterface->registerOnClickSelect([this]()
                                                { _currentScreen->buttonSelectPressed(); });

        buttonsInterface->registerOnClickBack([this]()
                                              { _currentScreen->buttonBackPressed(); });
    }
}

void ScreenManager::render(std::shared_ptr<TFT_eSPI> tft)
{
    tft->fillScreen(TFT_BLACK);
    this->_currentScreen->render(tft);
}

ScreenManager *ScreenManager::getCurrent()
{
    return ScreenManager::_current;
}

void ScreenManager::render()
{
    this->render(this->_tft);
}

void ScreenManager::setCurrentScreen(Screen *currentScreen)
{
    currentScreen->setPreviousScreen(ScreenManager::getCurrent()->_currentScreen);
    ScreenManager::getCurrent()->_currentScreen = currentScreen;
    ScreenManager::getCurrent()->render();
}

void ScreenManager::setToPreviousScreen()
{
    if (ScreenManager::getCurrent()->_currentScreen->getPreviousScreen() != nullptr)
        ScreenManager::setCurrentScreen(ScreenManager::getCurrent()->_currentScreen->getPreviousScreen());
}

Screen *ScreenManager::getCurrentScreen()
{
    return ScreenManager::getCurrent()->_currentScreen;
}
