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
        DeviceBase(Interfaces _interfaces);

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
                return static_cast<T>(this->_interfaces.displayInterface);
            case InterfaceType::PowerManagement:
                return static_cast<T>(this->_interfaces.powerManagementInterface);
            case InterfaceType::Battery:
                return static_cast<T>(this->_interfaces.batteryInterface);
            case InterfaceType::Wifi:
                return static_cast<T>(this->_interfaces.wifiInterface);
            case InterfaceType::Bluetooth:
                return static_cast<T>(this->_interfaces.bluetoothInterface);
            case InterfaceType::Led:
                return static_cast<T>(this->_interfaces.ledInterface);
            case InterfaceType::SdCard:
                return static_cast<T>(this->_interfaces.sdCardInterface);
            case InterfaceType::Gps:
                return static_cast<T>(this->_interfaces.gpsInterface);
            case InterfaceType::Keyboard:
                return static_cast<T>(this->_interfaces.keyboardInterface);
            case InterfaceType::Buttons:
                return static_cast<T>(this->_interfaces.buttonsInterface);
            case InterfaceType::Infrared:
                return static_cast<T>(this->_interfaces.infraredInterface);
            default:
                return nullptr;
            }
        }

        virtual Interfaces getInterfaces();

    private:
        static DeviceBase *_current;
        static bool _initialized;

    protected:
        Interfaces _interfaces;
    };
}
