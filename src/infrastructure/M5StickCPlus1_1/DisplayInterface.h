#pragma once

#include <memory>

#include "../../domain/entities/DisplayInterfaceBase.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Infrastructure::M5StickCPlus1_1
    {
        class DisplayInterface : public Domain::Entities::DisplayInterfaceBase
        {
        public:
            DisplayInterface() : Domain::Entities::DisplayInterfaceBase(){};

            void begin();
        };
    }
#ifdef __cplusplus
}
#endif