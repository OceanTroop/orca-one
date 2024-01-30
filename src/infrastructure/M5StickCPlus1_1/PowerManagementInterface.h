#ifdef M5STICKCPLUS1_1

#pragma once

#include <memory>
#include "utility/AXP192.h"

#include "../../domain/entities/PowerManagementInterfaceBase.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Infrastructure::M5StickCPlus1_1
    {
        class PowerManagementInterface : public Domain::Entities::PowerManagementInterfaceBase
        {
        public:
            void begin();
            void loop();

        protected:
            AXP192 _axp = AXP192();
        };
    }
#ifdef __cplusplus
}
#endif
#endif