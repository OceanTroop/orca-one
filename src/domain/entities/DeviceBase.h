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

        void saveSettings();

    private:
        static DeviceBase *_instance;
        static bool _initialized;

    protected:
        Interfaces _interfaces;
        Settings *_settings;
    };
}
