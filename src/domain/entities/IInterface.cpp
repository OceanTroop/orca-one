#include "IInterface.h"

using namespace Domain::Entities;

void IInterface::enable()
{
    this->_active = true;
}

void IInterface::disable()
{
    this->_active = false;
}
