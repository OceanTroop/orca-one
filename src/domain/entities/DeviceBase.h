#pragma once

#include <WString.h>
#include <stdexcept>
#include <vector>
#include <memory>
#include <FS.h>

#include "Interfaces.h"
#include "InterfaceType.h"
#include "IInterface.h"
#include "Settings.h"

namespace Domain::Entities
{
    class DeviceBase
    {
    public:
        DeviceBase(Interfaces _interfaces);

        static DeviceBase *getInstance();

        virtual String getName() = 0;
        virtual void begin();
        virtual void loop();
        virtual bool hasInterface(InterfaceType type);
        virtual Interfaces getInterfaces();
        esp_chip_info_t getChipInfo();

        Settings *getSettings();
        void saveSettings();
        void saveSettingsAndReboot();

    private:
        static DeviceBase *_instance;
        static bool _initialized;
        esp_chip_info_t _chip_info;

    protected:
        Interfaces _interfaces;
        Settings *_settings;
    };
}
