#pragma once

#include <Arduino.h>
#include "InterfaceType.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Domain::Entities
    {
        class IInterface
        {
        protected:
            bool _active = true;

        public:
            virtual InterfaceType getType() = 0;
            virtual void begin() = 0;
            virtual void loop() = 0;

            virtual void enable();
            virtual void disable();
            virtual bool isActive();
        };
    }
#ifdef __cplusplus
}
#endif