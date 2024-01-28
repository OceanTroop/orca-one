#pragma once

#include "..\..\services\gui\Screen.h"

using namespace Applications::Services::GUI;

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Applications::Settings::About
    {
        class AboutScreen : public Screen
        {
        public:
            AboutScreen(std::shared_ptr<TFT_eSPI> tft) : Screen(tft) {}
            void render(std::shared_ptr<TFT_eSPI> tft);
            void buttonSelectPressed();
            void buttonNextPressed();
            void buttonPreviousPressed();
        };
    }

#ifdef __cplusplus
}
#endif