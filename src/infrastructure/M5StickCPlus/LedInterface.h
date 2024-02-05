#ifdef M5STICKCPLUS

#pragma once

#include <memory>

#if defined(M5STICKCPLUS1_1)
#define LED_PIN 10
#define LED_ON LOW
#define LED_OFF HIGH
#elif defined(M5STICKCPLUS2)
#define LED_PIN 19
#define LED_ON HIGH
#define LED_OFF LOW
#endif

#include "../../domain/entities/LedInterfaceBase.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Infrastructure::M5StickCPlus
    {
        class LedInterface : public Domain::Entities::LedInterfaceBase
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