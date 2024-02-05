#ifdef M5STICKCPLUS

#include "LedInterface.h"

using namespace Infrastructure::M5StickCPlus;

void LedInterface::begin()
{
    pinMode(LED_PIN, OUTPUT);
    this->disable();
}

void LedInterface::loop()
{
}

void LedInterface::enable()
{
    LedInterfaceBase::enable();
    digitalWrite(LED_PIN, LED_ON);
}

void LedInterface::disable()
{
    LedInterfaceBase::disable();
    digitalWrite(LED_PIN, LED_OFF);
}

#endif