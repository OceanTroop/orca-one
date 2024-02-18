#include "Launcher.h"
#include "../../domain/entities/DeviceBase.h"
#include "../services/gui/MainMenuScreen.h"
#include "../services/gui/SplashScreen.h"

using namespace Applications;
using namespace Applications::Services::GUI;
using namespace Domain::Entities;

Launcher *Launcher::_instance = nullptr;
bool Launcher::_initialized = false;

Launcher::Launcher()
{
    if (Launcher::_initialized)
    {
        throw std::runtime_error("Launcher previous initialized. Please, define Launcher only time. Use: Launcher::getInstance()");
    }

    Launcher::_initialized = true;
    Launcher::_instance = this;
}

Launcher *Launcher::getInstance()
{
    return Launcher::_instance;
}

void Launcher::begin()
{
    auto tft = DeviceBase::getInstance()->getInterfaces().displayInterface->getTFT();
    auto settings = DeviceBase::getInstance()->getSettings();
    auto language = settings->getLanguage();

    this->_translate = Translate::fromFile(language, SPIFFS_STORAGE, String("/translate/" + languageToString(language) + ".json").c_str());
    this->_screenManager = new ScreenManager(tft);
    this->_screenManager->setCurrentScreen(new SplashScreen(tft));
    this->_screenManager->setCurrentScreen(new MainMenuScreen(tft));
}

void Launcher::loop()
{
}

const Translate *Applications::Launcher::getTranslate()
{
    return this->_translate;
}
