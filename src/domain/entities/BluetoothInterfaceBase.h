#pragma once

#include "IInterface.h"
#include "InterfaceType.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Domain::Entities
    {
        class BluetoothInterfaceBase : public IInterface
        {
        public:
            InterfaceType getType();
            virtual void begin();
            virtual void loop();
        };
    }
#ifdef __cplusplus
}
#endif
