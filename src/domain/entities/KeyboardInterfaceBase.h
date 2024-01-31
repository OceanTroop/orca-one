#pragma once

#include <cstdint>

#include "IInterface.h"
#include "InterfaceType.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Domain::Entities
    {
        class KeyboardInterfaceBase : public IInterface
        {
        public:
            InterfaceType getType();
            
            virtual uint8_t isPressed() = 0;
            virtual bool isChange() = 0;
            virtual bool isKeyPressed(char c) = 0;
            virtual bool capslocked() = 0;
        };
    }
#ifdef __cplusplus
}
#endif
