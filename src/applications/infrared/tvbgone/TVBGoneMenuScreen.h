#pragma once

#include "../../services/gui/MenuScreen.h"

using namespace Applications::Services::GUI;

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Applications::Infrared::TVBGone
    {
        class TVBGoneMenuScreen : public MenuScreen
        {
        public:
            TVBGoneMenuScreen(std::shared_ptr<TFT_eSPI> tft);
        };
    }

#ifdef __cplusplus
}
#endif