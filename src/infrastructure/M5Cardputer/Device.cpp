#ifdef M5CARDPUTER

#include "Device.h"
#include "DisplayInterface.h"
#include "KeyboardInterface.h"
#include "ButtonsInterface.h"
#include "InfraredInterface.h"
#include "../../domain/entities/SdCardInterfaceBase.h"

using namespace Infrastructure::M5Cardputer;

Device::Device() : DeviceBase({std::make_shared<DisplayInterface>(),
                               std::make_shared<ButtonsInterface>(),
                               nullptr,
                               std::make_shared<KeyboardInterface>(),
                               std::make_shared<InfraredInterface>(),
                               nullptr,
                               nullptr,
                               nullptr,
                               nullptr,
                               std::make_shared<SdCardInterfaceBase>()})
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