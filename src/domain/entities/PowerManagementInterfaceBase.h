#pragma once

#include "IInterface.h"
#include "InterfaceType.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Domain::Entities
    {
        class PowerManagementInterfaceBase : public IInterface
        {
        public:
            InterfaceType getType();
        };
    }
#ifdef __cplusplus
}
#endif