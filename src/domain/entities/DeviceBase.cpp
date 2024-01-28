#include "DeviceBase.h"

using namespace Domain::Entities;

DeviceBase *DeviceBase::_current = nullptr;
bool DeviceBase::_initialized = false;

DeviceBase::DeviceBase(Interfaces interfaces)
{
    if (DeviceBase::_initialized)
    {
        throw std::runtime_error("Device previous initialized. Please, define Device only time. Use: DeviceBase::getCurrent()");
    }

    this->interfaces = interfaces;

    DeviceBase::_initialized = true;
    DeviceBase::_current = this;
}

DeviceBase *DeviceBase::getCurrent()
{
    return DeviceBase::_current;
}

void DeviceBase::begin()
{
    Serial.begin(115200);

    if (this->interfaces.displayInterface != nullptr)
        this->interfaces.displayInterface->begin();

    if (this->interfaces.powerManagement != nullptr)
        this->interfaces.powerManagement->begin();

    if (this->interfaces.batteryInterface != nullptr)
        this->interfaces.batteryInterface->begin();

    if (this->interfaces.wifiInterface != nullptr)
        this->interfaces.wifiInterface->begin();

    if (this->interfaces.bluetoothInterface != nullptr)
        this->interfaces.bluetoothInterface->begin();

    if (this->interfaces.ledInterface != nullptr)
        this->interfaces.ledInterface->begin();

    if (this->interfaces.sdCardInterface != nullptr)
        this->interfaces.sdCardInterface->begin();

    if (this->interfaces.gpsInterface != nullptr)
        this->interfaces.gpsInterface->begin();

    if (this->interfaces.keyboardInterface != nullptr)
        this->interfaces.keyboardInterface->begin();

    if (this->interfaces.buttonsInterface != nullptr)
        this->interfaces.buttonsInterface->begin();

    if (this->interfaces.infraredInterface != nullptr)
        this->interfaces.infraredInterface->begin();

    delay(100);
}

void DeviceBase::loop()
{
    if (this->interfaces.displayInterface != nullptr)
        this->interfaces.displayInterface->loop();

    if (this->interfaces.powerManagement != nullptr)
        this->interfaces.powerManagement->loop();

    if (this->interfaces.batteryInterface != nullptr)
        this->interfaces.batteryInterface->loop();

    if (this->interfaces.wifiInterface != nullptr)
        this->interfaces.wifiInterface->loop();

    if (this->interfaces.bluetoothInterface != nullptr)
        this->interfaces.bluetoothInterface->loop();

    if (this->interfaces.ledInterface != nullptr)
        this->interfaces.ledInterface->loop();

    if (this->interfaces.sdCardInterface != nullptr)
        this->interfaces.sdCardInterface->loop();

    if (this->interfaces.gpsInterface != nullptr)
        this->interfaces.gpsInterface->loop();

    if (this->interfaces.keyboardInterface != nullptr)
        this->interfaces.keyboardInterface->loop();

    if (this->interfaces.buttonsInterface != nullptr)
        this->interfaces.buttonsInterface->loop();

    if (this->interfaces.infraredInterface != nullptr)
        this->interfaces.infraredInterface->loop();

    delay(150);
}

bool DeviceBase::hasInterface(InterfaceType type)
{
    switch (type)
    {
    case InterfaceType::Display:
        return this->interfaces.displayInterface != nullptr;
    case InterfaceType::PowerManagement:
        return this->interfaces.powerManagement != nullptr;
    case InterfaceType::Battery:
        return this->interfaces.batteryInterface != nullptr;
    case InterfaceType::Wifi:
        return this->interfaces.wifiInterface != nullptr;
    case InterfaceType::Bluetooth:
        return this->interfaces.bluetoothInterface != nullptr;
    case InterfaceType::Led:
        return this->interfaces.ledInterface != nullptr;
    case InterfaceType::SdCard:
        return this->interfaces.sdCardInterface != nullptr;
    case InterfaceType::Gps:
        return this->interfaces.gpsInterface != nullptr;
    case InterfaceType::Keyboard:
        return this->interfaces.keyboardInterface != nullptr;
    case InterfaceType::Buttons:
        return this->interfaces.buttonsInterface != nullptr;
    case InterfaceType::Infrared:
        return this->interfaces.infraredInterface != nullptr;
    default:
        return false;
    }
}

Interfaces Domain::Entities::DeviceBase::getInterfaces()
{
    return this->interfaces;
}
