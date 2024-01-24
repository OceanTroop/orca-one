#pragma once

#include "InterfaceType.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Domain::Entities
    {
        class IInterface
        {
        public:
            virtual InterfaceType getType() = 0;
            virtual void begin() = 0;
            virtual void loop() = 0;
        };
    }
#ifdef __cplusplus
}
#endif