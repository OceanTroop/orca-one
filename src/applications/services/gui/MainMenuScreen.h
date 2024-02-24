#pragma once

#include <TFT_eSPI.h>
#include "MenuScreen.h"
#include "MenuItem.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Applications::Services::GUI
    {
        class MainMenuScreen : public MenuScreen
        {
        private:
            MenuItem newAppsMainMenuItem();
            MenuItem newWifiMainMenuItem();
            MenuItem newBluetoothMainMenuItem();
            MenuItem newSubGhzMainMenuItem();
            MenuItem newNfcMainMenuItem();
            MenuItem newInfraredMainMenuItem();
            MenuItem newBadUsbMainMenuItem();
            MenuItem newSettingsMainMenuItem();
            MenuItem newSettingsColorSubMenuItem();

        public:
            MainMenuScreen(std::shared_ptr<TFT_eSPI> tft);
        };
    }

#ifdef __cplusplus
}
#endif