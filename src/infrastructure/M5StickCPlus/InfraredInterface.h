#ifdef M5STICKCPLUS

#pragma once

#include <memory>
#include <IRsend.h>

#if defined(M5STICKCPLUS1_1)
#define INFRARED_PIN 9
#define INFRARED_ON LOW
#define INFRARED_OFF HIGH
#elif defined(M5STICKCPLUS2)
#define INFRARED_PIN 19
#define INFRARED_ON HIGH
#define INFRARED_OFF LOW
#endif

#include "../../domain/entities/InfraredInterfaceBase.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Infrastructure::M5StickCPlus
    {
        class InfraredInterface : public Domain::Entities::InfraredInterfaceBase
        {
        public:
            void begin();
            void loop();
            void enable();
            void disable();
        };
    }
#ifdef __cplusplus
}
#endif
#endif