#pragma once

#include <WString.h>
#include <TFT_eSPI.h>

#include "AbstractGuiModule.h"
#include "Screen.h"

// #ifdef __cplusplus
// extern "C"
// {
// #endif
    namespace Applications::Services::GUI
    {
        class ScreenManager : public AbstractGuiModule
        {
        private:
            static ScreenManager *_current;
            static bool _initialized;

        protected:
            std::shared_ptr<TFT_eSPI> _tft;
            Screen *_currentScreen = nullptr;

        public:
            ScreenManager(std::shared_ptr<TFT_eSPI> tft);

            static ScreenManager *getCurrent();
            static void setCurrentScreen(Screen *currentScreen);
            static void setToPreviousScreen();

            template <typename T>
            static void setCurrentScreenByType()
            {
                auto tft = ScreenManager::getCurrent()->_tft;
                auto screen = new T(tft);
                ScreenManager::setCurrentScreen(screen);
            }

            static Screen *getCurrentScreen();

            virtual void render(std::shared_ptr<TFT_eSPI> tft);
            virtual void render();
        };
    }

// #ifdef __cplusplus
// }
// #endif