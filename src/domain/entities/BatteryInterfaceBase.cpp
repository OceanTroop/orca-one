#include "BatteryInterfaceBase.h"

using namespace Domain::Entities;

InterfaceType BatteryInterfaceBase::getType()
{
    return InterfaceType::Battery;
}
