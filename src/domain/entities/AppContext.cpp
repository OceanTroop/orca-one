#include "AppContext.h"

using namespace Domain::Entities;

void AppContext::setDevice(std::shared_ptr<DeviceBase> device)
{
    this->_device = device;
}

std::shared_ptr<DeviceBase> AppContext::getDevice()
{
    return this->_device;
}
