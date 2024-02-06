#include "AbstractGuiModule.h"
#include "../../../domain/entities/DeviceBase.h"

using namespace Applications::Services::GUI;
using namespace Domain::Entities;

void AbstractGuiModule::setId(String id)
{
    this->_id = id;
}

const String AbstractGuiModule::getId()
{
    return this->_id;
}

void AbstractGuiModule::setTextSizeBig(std::shared_ptr<TFT_eSPI> tft)
{
    auto displayInterface = DeviceBase::getCurrent()->getInterfaces().displayInterface;
    tft->setTextSize(displayInterface->getTextSizeBig());
}

void AbstractGuiModule::setTextSizeMedium(std::shared_ptr<TFT_eSPI> tft)
{
    auto displayInterface = DeviceBase::getCurrent()->getInterfaces().displayInterface;
    tft->setTextSize(displayInterface->getTextSizeMedium());
}

void AbstractGuiModule::setTextSizeSmall(std::shared_ptr<TFT_eSPI> tft)
{
    auto displayInterface = DeviceBase::getCurrent()->getInterfaces().displayInterface;
    tft->setTextSize(displayInterface->getTextSizeSmall());
}

void AbstractGuiModule::setTextSizeTiny(std::shared_ptr<TFT_eSPI> tft)
{
    auto displayInterface = DeviceBase::getCurrent()->getInterfaces().displayInterface;
    tft->setTextSize(displayInterface->getTextSizeTiny());
}
