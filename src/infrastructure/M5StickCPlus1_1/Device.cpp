#include "Device.h"
#include "DisplayInterface.h"
#include "PowerManagementInterface.h"
#include "ButtonsInterface.h"

using namespace Infrastructure::M5StickCPlus1_1;

Device::Device() : DeviceBase({std::make_shared<DisplayInterface>(),
                               std::make_shared<PowerManagementInterface>(),
                               std::make_shared<ButtonsInterface>()})
{
}

String Device::getName()
{
    return "M5StickC Plus 1.1";
}

void Infrastructure::M5StickCPlus1_1::Device::begin()
{
    Domain::Entities::DeviceBase::begin();
}

void Infrastructure::M5StickCPlus1_1::Device::loop()
{
    Domain::Entities::DeviceBase::loop();
}
