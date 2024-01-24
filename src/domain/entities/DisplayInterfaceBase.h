#pragma once

#include <TFT_eSPI.h>
#include <memory>

#include "IInterface.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Domain::Entities
    {
        class DisplayInterfaceBase : public IInterface
        {
        public:
            DisplayInterfaceBase();

            InterfaceType getType();
            virtual void begin();
            virtual void loop();
            virtual const std::shared_ptr<TFT_eSPI> getTFT();

        protected:
            std::shared_ptr<TFT_eSPI> _tft;
        };
    }
#ifdef __cplusplus
}
#endif