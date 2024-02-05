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
            Screen *_previousScreen = nullptr;

        public:
            Screen(std::shared_ptr<TFT_eSPI> tft);

            virtual void render(std::shared_ptr<TFT_eSPI> tft) = 0;
            virtual void render();
            virtual void setPreviousScreen(Screen *previous);
            virtual Screen *getPreviousScreen();

            virtual void buttonNextPressed();
            virtual void buttonPreviousPressed();
            virtual void buttonBackPressed();
            virtual void buttonSelectPressed();
        };
    }

#ifdef __cplusplus
}
#endif