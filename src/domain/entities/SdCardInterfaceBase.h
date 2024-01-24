#pragma once

#include "IInterface.h"
#include "InterfaceType.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Domain::Entities
    {
        class SdCardInterfaceBase : public IInterface
        {
        public:
            InterfaceType getType();
        };
    }
#ifdef __cplusplus
}
#endif
