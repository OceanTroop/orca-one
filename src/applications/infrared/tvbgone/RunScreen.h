#pragma once

#include "TVBGoneRegion.h"
#include "TVBGoneType.h"
#include "../../services/gui/Screen.h"
#include "../../services/gui/ProgressBar.h"
#include "../../taskmanager/TaskManager.h"

using namespace Applications;
using namespace Applications::Services::GUI;

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Applications::Infrared::TVBGone
    {
        class RunScreen : public Screen
        {
        private:
            bool _isRunning = false;
            bool _stopping = false;
            TVBGoneRegion _region;
            TVBGoneType _type;
            ProgressBar _progressBar;

        public:
            RunScreen(TVBGoneRegion region, TVBGoneType type, std::shared_ptr<TFT_eSPI> tft) : Screen(tft)
            {
                this->_region = region;
                this->_type = type;
            }

            void render(std::shared_ptr<TFT_eSPI> tft);
            void buttonSelectPressed();
            void buttonNextPressed();
            void buttonPreviousPressed();
            void buttonBackPressed();

            void stop();
            void start();

            void __execute__();
        };
    }

#ifdef __cplusplus
}
#endif