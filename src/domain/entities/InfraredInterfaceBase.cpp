#include "InfraredInterfaceBase.h"

using namespace Domain::Entities;

InfraredInterfaceBase::InfraredInterfaceBase(int infraredPin, bool inverted)
{
    this->_infraredPin = infraredPin;
    this->_inverted = inverted;
}

InterfaceType InfraredInterfaceBase::getType()
{
    return InterfaceType::Infrared;
}

IRsend *InfraredInterfaceBase::getIRSend()
{
    return this->_irSend;
}

void InfraredInterfaceBase::begin()
{
    pinMode(this->_infraredPin, OUTPUT);

    this->_irSend = new IRsend(this->_infraredPin, this->_inverted);
    this->_irSend->begin();

    this->disable();
}

void InfraredInterfaceBase::loop()
{
}

void InfraredInterfaceBase::enable()
{
    digitalWrite(this->_infraredPin, this->_inverted ? LOW : HIGH);
}

void InfraredInterfaceBase::disable()
{
    digitalWrite(this->_infraredPin, this->_inverted ? HIGH : LOW);
}

bool InfraredInterfaceBase::isInverted()
{
    return this->_inverted;
}
