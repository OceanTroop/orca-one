#pragma once

#include <WString.h>
#include <TFT_eSPI.h>

#include "AbstractGuiModule.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Applications::Services::GUI
    {
        class Screen : public AbstractGuiModule
        {
        protected:
            std::shared_ptr<TFT_eSPI> _tft;
            std::shared_ptr<Screen> _previous = nullptr;

        public:
            Screen(std::shared_ptr<TFT_eSPI> tft);

            virtual void render(std::shared_ptr<TFT_eSPI> tft) = 0;
            virtual void render();
            virtual void setPrevious(std::shared_ptr<Screen> previous);
            virtual std::shared_ptr<Screen> getPrevious();
        };
    }

#ifdef __cplusplus
}
#endif