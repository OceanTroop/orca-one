#ifdef M5CARDPUTER

#pragma once

#include <memory>

#define INFRARED_PIN 44
#define INFRARED_INVERTED true

#include "../../domain/entities/InfraredInterfaceBase.h"

using namespace Domain::Entities;

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Infrastructure::M5Cardputer
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