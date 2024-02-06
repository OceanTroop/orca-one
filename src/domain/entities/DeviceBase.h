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
        virtual bool hasInterface(InterfaceType type);
        virtual Interfaces getInterfaces();

    private:
        static DeviceBase *_current;
        static bool _initialized;

    protected:
        Interfaces _interfaces;
    };
}
