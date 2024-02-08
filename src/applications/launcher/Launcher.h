#pragma once

#include "../services/gui/ScreenManager.h"

using ScreenManager = Applications::Services::GUI::ScreenManager;

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Applications
    {
        class Launcher
        {
        private:
            static Launcher *_instance;
            static bool _initialized;
            ScreenManager *_screenManager;

        public:
            Launcher();

            static Launcher *getInstance();

            void begin();
            void loop();
        };
    }

#ifdef __cplusplus
}
#endif