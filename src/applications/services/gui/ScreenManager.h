#pragma once

#include <WString.h>
#include <TFT_eSPI.h>

#include "AbstractGuiModule.h"
#include "Screen.h"

namespace Applications::Services::GUI
{
    class ScreenManager : public AbstractGuiModule
    {
    private:
        static ScreenManager *_instance;
        static bool _initialized;

    protected:
        std::shared_ptr<TFT_eSPI> _tft;
        Screen *_currentScreen = nullptr;

    public:
        ScreenManager(std::shared_ptr<TFT_eSPI> tft);

        static ScreenManager *getInstance();
        static void setCurrentScreen(Screen *newScreen);
        static void setToPreviousScreen();

        template <typename T>
        static void setCurrentScreen()
        {
            auto tft = ScreenManager::getInstance()->_tft;
            auto screen = new T(tft);
            ScreenManager::setCurrentScreen(screen);
        }

        static Screen *getCurrentScreen();

        virtual void render(std::shared_ptr<TFT_eSPI> tft);
        virtual void render();
    };
}
