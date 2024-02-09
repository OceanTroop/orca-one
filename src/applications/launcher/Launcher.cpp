#include "Launcher.h"
#include "../../domain/entities/DeviceBase.h"
#include "../services/gui/MainMenuScreen.h"

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

    this->_screenManager = new ScreenManager(tft);
    this->_screenManager->setCurrentScreen(new MainMenuScreen(tft));
}

void Launcher::loop()
{
}
