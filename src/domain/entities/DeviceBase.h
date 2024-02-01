#pragma once

#include <WString.h>
#include <stdexcept>
#include <vector>
#include <memory>

#include "Interfaces.h"
#include "InterfaceType.h"
#include "IInterface.h"

namespace Domain::Entities
{
    class DeviceBase
    {
    public:
        DeviceBase(Interfaces interfaces);

        static DeviceBase *getCurrent();

        virtual String getName() = 0;
        virtual void begin();
        virtual void loop();

        bool hasInterface(InterfaceType type);

        template <typename T>
        T getInterface(InterfaceType type)
        {
            switch (type)
            {
            case InterfaceType::Display:
                return static_cast<T>(this->interfaces.displayInterface);
            case InterfaceType::PowerManagement:
                return static_cast<T>(this->interfaces.powerManagementInterface);
            case InterfaceType::Battery:
                return static_cast<T>(this->interfaces.batteryInterface);
            case InterfaceType::Wifi:
                return static_cast<T>(this->interfaces.wifiInterface);
            case InterfaceType::Bluetooth:
                return static_cast<T>(this->interfaces.bluetoothInterface);
            case InterfaceType::Led:
                return static_cast<T>(this->interfaces.ledInterface);
            case InterfaceType::SdCard:
                return static_cast<T>(this->interfaces.sdCardInterface);
            case InterfaceType::Gps:
                return static_cast<T>(this->interfaces.gpsInterface);
            case InterfaceType::Keyboard:
                return static_cast<T>(this->interfaces.keyboardInterface);
            case InterfaceType::Buttons:
                return static_cast<T>(this->interfaces.buttonsInterface);
            case InterfaceType::Infrared:
                return static_cast<T>(this->interfaces.infraredInterface);
            default:
                return nullptr;
            }
        }

        virtual Interfaces getInterfaces();

    private:
        static DeviceBase *_current;
        static bool _initialized;

    protected:
        Interfaces interfaces;
    };
}
