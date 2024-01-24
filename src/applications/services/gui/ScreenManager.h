#pragma once

#include <WString.h>
#include <TFT_eSPI.h>

#include "AbstractGuiModule.h"
#include "Screen.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Applications::Services::GUI
    {
        class ScreenManager : public AbstractGuiModule
        {
        private:
            static ScreenManager *_current;
            static bool _initialized;

        protected:
            std::shared_ptr<TFT_eSPI> _tft;
            std::shared_ptr<Screen> _currentScreen = nullptr;

        public:
            ScreenManager(std::shared_ptr<TFT_eSPI> tft);

            static const ScreenManager *getCurrent();

            virtual void render(std::shared_ptr<TFT_eSPI> tft);
            virtual void render();
            virtual void setCurrentScreen(std::shared_ptr<Screen> currentScreen);
            virtual std::shared_ptr<Screen> getCurrentScreen();
        };
    }

#ifdef __cplusplus
}
#endif