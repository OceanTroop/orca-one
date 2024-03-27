#ifdef M5CARDPUTER

#include "I2CInterface.h"

using namespace Infrastructure::M5Cardputer;

I2CInterface::I2CInterface() : I2CInterfaceBase()
{
}

void I2CInterface::begin()
{
    _wire.begin(SDA_PIN, SCL_PIN);
}

void I2CInterface::begin(int sda_pin, int scl_pin)
{
    _wire.begin(sda_pin, scl_pin);
}

void I2CInterface::loop()
{
}

void I2CInterface::end()
{
    _wire.end();
}

#endif