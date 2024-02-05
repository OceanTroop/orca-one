#ifdef M5STICKCPLUS

#include "InfraredInterface.h"

using namespace Infrastructure::M5StickCPlus;

void InfraredInterface::begin()
{
    pinMode(INFRARED_PIN, OUTPUT);
    this->_irSend = new IRsend(INFRARED_PIN);
    this->disable();
}

void InfraredInterface::loop()
{
}

void InfraredInterface::enable()
{
    InfraredInterfaceBase::enable();
    digitalWrite(INFRARED_PIN, INFRARED_ON);
}

void InfraredInterface::disable()
{
    InfraredInterfaceBase::disable();
    digitalWrite(INFRARED_PIN, INFRARED_OFF);
}

#endif
