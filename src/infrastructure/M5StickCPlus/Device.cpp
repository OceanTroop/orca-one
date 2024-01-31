#ifdef M5STICKCPLUS

#include "Device.h"
#include "DisplayInterface.h"
#include "ButtonsInterface.h"

#if defined(M5STICKCPLUS1_1)
#include "PowerManagementInterface.h"
#define std ::make_shared<PowerManagementInterface>()
#elif defined(M5STICKCPLUS2)
#define POWER_MANAGEMENT_INTERFACE nullptr
#endif

using namespace Infrastructure::M5StickCPlus;

Device::Device() : DeviceBase({std::make_shared<DisplayInterface>(),
                               std::make_shared<ButtonsInterface>(),
                               POWER_MANAGEMENT_INTERFACE})
{
}

String Device::getName()
{
#if defined(M5STICKCPLUS1_1)
    return "M5StickC PLUS 1.1";
#elif defined(M5STICKCPLUS2)
    return "M5StickC PLUS2";
#endif
}

void Infrastructure::M5StickCPlus::Device::begin()
{
    Domain::Entities::DeviceBase::begin();
}

void Infrastructure::M5StickCPlus::Device::loop()
{
    Domain::Entities::DeviceBase::loop();
}

#endif