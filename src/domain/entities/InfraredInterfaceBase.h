#pragma once

#include "IInterface.h"
#include "InterfaceType.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Domain::Entities
    {
        class InfraredInterfaceBase : public IInterface
        {
        public:
            InterfaceType getType();
            IRSend *getIRSend();

        protected:
            IRsend *_irSend;
        };
    }
#ifdef __cplusplus
}
#endif
