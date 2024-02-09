#ifdef M5STICKCPLUS

#pragma once

#include <memory>

#if defined(M5STICKCPLUS1_1)
#define INFRARED_PIN 9
#define INFRARED_INVERTED true
#elif defined(M5STICKCPLUS2)
#define INFRARED_PIN 19
#define INFRARED_INVERTED false
#endif

#include "../../domain/entities/InfraredInterfaceBase.h"

using namespace Domain::Entities;

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Infrastructure::M5StickCPlus
    {
        class InfraredInterface : public InfraredInterfaceBase
        {
        public:
            InfraredInterface() : InfraredInterfaceBase(INFRARED_PIN, INFRARED_INVERTED) {}
            
        };
    }
#ifdef __cplusplus
}
#endif
#endif