#pragma once

#include <TFT_eSPI.h>
#include <memory>

#include "IInterface.h"
#include "DisplaySettings.h"

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
            virtual DisplaySettings getSettings() = 0;

        protected:
            std::shared_ptr<TFT_eSPI> _tft;
        };
    }
#ifdef __cplusplus
}
#endif