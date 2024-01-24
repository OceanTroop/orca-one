#pragma once

#include "../../domain/entities/DeviceBase.h"

using namespace Domain::Entities;

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Infrastructure::M5StickCPlus1_1
    {
        class Device : public DeviceBase
        {
        public:
            Device();

            String getName();
            void begin();
            void loop();
        };
    }
#ifdef __cplusplus
}
#endif