#include "SdCardInterfaceBase.h"

using namespace Domain::Entities;

SdCardInterfaceBase::SdCardInterfaceBase()
{
    this->_spi = new SPIClass(SDCARD_SPI_BUS);
}

InterfaceType SdCardInterfaceBase::getType()
{
    return InterfaceType::SdCard;
}

void SdCardInterfaceBase::loop()
{
}

void SdCardInterfaceBase::begin()
{
    this->_initialized = SD.begin(SDCARD_CS, *(this->_spi));

    if (this-_initialized)
    {
        Serial.println("SDCard Initialized.");
    }
    else
    {
        Serial.println("Error while initialize SDCard!");
    }
}
