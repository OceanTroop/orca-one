#pragma once

#include "../services/gui/ScreenManager.h"
#include "../Translate.h"

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
            Translate *_translate;

        public:
            Launcher();

            static Launcher *getInstance();

            void begin();
            void loop();

            const Translate *getTranslate();
        };
    }

#ifdef __cplusplus
}
#endif