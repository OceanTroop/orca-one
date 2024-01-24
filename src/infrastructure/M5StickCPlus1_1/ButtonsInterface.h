#pragma once

#include <memory>

#include "../../domain/entities/ButtonsInterfaceBase.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Infrastructure::M5StickCPlus1_1
    {
        class ButtonsInterface : public Domain::Entities::ButtonsInterfaceBase
        {
        public:
            void begin();
            void loop();
        };
    }
#ifdef __cplusplus
}
#endif