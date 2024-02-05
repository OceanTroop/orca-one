#pragma once

#include <TFT_eSPI.h>
#include "Screen.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Applications::Services::GUI
    {
        class ComingSoonScreen : public Screen
        {
        public:
            ComingSoonScreen(std::shared_ptr<TFT_eSPI> tft) : Screen(tft) {}

            void render(std::shared_ptr<TFT_eSPI> tft);

            void buttonNextPressed();
            void buttonPreviousPressed();
            void buttonSelectPressed();
        };
    }

#ifdef __cplusplus
}
#endif