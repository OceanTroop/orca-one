#include "InfraredInterfaceBase.h"

using namespace Domain::Entities;

InfraredInterfaceBase::InfraredInterfaceBase(int infraredPin, bool inverted)
{
    this->_irSend = new IRsend(infraredPin, inverted);
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
    this->_irSend->begin();
}

void InfraredInterfaceBase::disable()
{
    digitalWrite(this->_infraredPin, this->_inverted ? LOW : HIGH);
}

void InfraredInterfaceBase::enable()
{
    digitalWrite(this->_infraredPin, this->_inverted ? HIGH : LOW);
}
