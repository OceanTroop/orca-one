#pragma once

#include "Screen.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Applications::Services::GUI
    {
        class SplashScreen : public Screen
        {
        public:
            SplashScreen(std::shared_ptr<TFT_eSPI> tft);

            void render(std::shared_ptr<TFT_eSPI> tft);
            void buttonNextPressed();
            void buttonPreviousPressed();
            void buttonBackPressed();
            void buttonSelectPressed();
        };
    }

#ifdef __cplusplus
}
#endif