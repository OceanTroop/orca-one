#ifdef M5CARDPUTER

#include "Device.h"
#include "DisplayInterface.h"
#include "ButtonsInterface.h"

using namespace Infrastructure::M5Cardputer;

Device::Device() : DeviceBase({std::make_shared<DisplayInterface>(),
                               std::make_shared<ButtonsInterface>()})
{
}

String Device::getName()
{
    return "M5Cardputer";
}

void Infrastructure::M5Cardputer::Device::begin()
{
    Domain::Entities::DeviceBase::begin();
}

void Infrastructure::M5Cardputer::Device::loop()
{
    Domain::Entities::DeviceBase::loop();
}

#endif