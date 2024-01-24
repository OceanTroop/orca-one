#include "WifiInterfaceBase.h"

using namespace Domain::Entities;

InterfaceType WifiInterfaceBase::getType()
{
    return InterfaceType::Wifi;
}
