#include "BluetoothInterfaceBase.h"

using namespace Domain::Entities;

InterfaceType BluetoothInterfaceBase::getType()
{
    return InterfaceType::Bluetooth;
}

void BluetoothInterfaceBase::loop()
{
}

void BluetoothInterfaceBase::begin()
{
}
