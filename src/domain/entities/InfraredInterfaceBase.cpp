#include "InfraredInterfaceBase.h"

using namespace Domain::Entities;

InterfaceType InfraredInterfaceBase::getType()
{
    return InterfaceType::Infrared;
}

IRSend *InfraredInterfaceBase::getIRSend()
{
    return this->_irSend;
}
