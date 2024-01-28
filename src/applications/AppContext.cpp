#include "AppContext.h"

using namespace Applications;

std::shared_ptr<AppContext> AppContext::newAppContext()
{
    auto context = std::make_shared<AppContext>();

    context->setDevice(DeviceBase::getCurrent());
    context->setScreeManager(ScreenManager::getCurrent());

    return context;
}

void AppContext::setDevice(DeviceBase *device)
{
    this->_device = device;
}

DeviceBase *AppContext::getDevice()
{
    return this->_device;
}

void AppContext::setScreeManager(ScreenManager *screenManager)
{
    this->_screenManager = screenManager;
}

ScreenManager *AppContext::getScreeManager()
{
    return this->_screenManager;
}
