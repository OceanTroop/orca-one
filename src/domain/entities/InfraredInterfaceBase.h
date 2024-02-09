#pragma once

#include <IRsend.h>

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
        private:
            IRsend *_irSend;
            int _infraredPin;
            bool _inverted;

        public:
            InfraredInterfaceBase(int infraredPin, bool inverted);
            InterfaceType getType();
            IRsend *getIRSend();
            virtual void begin();
            virtual void loop();
            virtual void enable();
            virtual void disable();
            virtual bool isInverted();
        };
    }
#ifdef __cplusplus
}
#endif
