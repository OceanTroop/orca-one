#include "DisplayInterfaceBase.h"

using namespace Domain::Entities;

DisplayInterfaceBase::DisplayInterfaceBase()
{
}

InterfaceType DisplayInterfaceBase::getType()
{
    return InterfaceType::Display;
}

void DisplayInterfaceBase::begin()
{
    _tft = std::make_shared<TFT_eSPI>();
    _tft->begin();
    _tft->setFreeFont(nullptr);
}

void DisplayInterfaceBase::loop()
{
}

const std::shared_ptr<TFT_eSPI> Domain::Entities::DisplayInterfaceBase::getTFT()
{
    return this->_tft;
}
