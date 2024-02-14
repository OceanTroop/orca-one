#include "MainMenuScreen.h"
#include "../../AppUtils.h"
#include "../../settings/about/AboutApp.h"
#include "../../infrared/tvbgone/TVBGoneApp.h"

using namespace Applications::Services::GUI;
using namespace Applications;

MainMenuScreen::MainMenuScreen(std::shared_ptr<TFT_eSPI> tft) : MenuScreen(tft, false)
{
    this->addItem(newAppsMainMenuItem());
    this->addItem(newWifiMainMenuItem());
    this->addItem(newBluetoothMainMenuItem());
    this->addItem(newSubGhzMainMenuItem());
    this->addItem(newNfcMainMenuItem());
    this->addItem(newInfraredMainMenuItem());
    this->addItem(newBadUsbMainMenuItem());
    this->addItem(newSettingsMainMenuItem());
}

MenuItem MainMenuScreen::newAppsMainMenuItem()
{
    MenuItem appsMenuItem("appsMenuItem", "Apps");
    return appsMenuItem;
}

MenuItem MainMenuScreen::newWifiMainMenuItem()
{
    MenuItem wifiMenuItem("wifiMenuItem", "Wifi");
    return wifiMenuItem;
}

MenuItem MainMenuScreen::newBluetoothMainMenuItem()
{
    MenuItem bluetoothMenuItem("bluetoothMenuItem", "Bluetooth");
    return bluetoothMenuItem;
}

MenuItem MainMenuScreen::newSubGhzMainMenuItem()
{
    MenuItem subGhzMenuItem("subGhzMenuItem", "Sub-GHz");
    return subGhzMenuItem;
}

MenuItem MainMenuScreen::newNfcMainMenuItem()
{
    MenuItem nfcMenuItem("nfcMenuItem", "NFC");
    return nfcMenuItem;
}

MenuItem MainMenuScreen::newInfraredMainMenuItem()
{
    MenuItem infraredMenuItem("infraredMenuItem", "Infrared");

    //  TV-B-Gone
    MenuItem infraredTVBGoneSubMenuItem("infraredTVBGoneSubMenuItem", "TV-B-Gone");
    infraredTVBGoneSubMenuItem.setOnClick([]()
                                          { AppUtils::runApplication<Applications::Infrared::TVBGone::TVBGoneApp>(); });
    infraredMenuItem.addItem(infraredTVBGoneSubMenuItem);

    return infraredMenuItem;
}

MenuItem MainMenuScreen::newBadUsbMainMenuItem()
{
    MenuItem badUsbMenuItem("badUsbMenuItem", "Bad USB");
    return badUsbMenuItem;
}

MenuItem MainMenuScreen::newSettingsMainMenuItem()
{
    MenuItem settingsMenuItem("settingsMenuItem", "Settings");

    // Language
    MenuItem settingsLanguageSubMenuItem("settingsLanguageSubMenuItem", "Language");
    MenuItem settingsLanguageEnglishSubMenuItem("settingsLanguageEnglishSubMenuItem", "English");
    MenuItem settingsLanguagePortuguesBrasilSubMenuItem("settingsLanguagePortuguesBrasilSubMenuItem", "Português (BR)");
    settingsLanguageSubMenuItem.addItem(settingsLanguageEnglishSubMenuItem);
    settingsLanguageSubMenuItem.addItem(settingsLanguagePortuguesBrasilSubMenuItem);
    settingsMenuItem.addItem(settingsLanguageSubMenuItem);

    // About
    MenuItem settingsAboutSubMenuItem("settingsAboutSubMenuItem", "About");
    settingsAboutSubMenuItem.setOnClick([]()
                                        { AppUtils::runApplication<Applications::Settings::About::AboutApp>(); });
    settingsMenuItem.addItem(settingsAboutSubMenuItem);

    // Web UI
    MenuItem settingsWebUISubMenuItem("settingsWebUISubMenuItem", "Web UI");
    settingsMenuItem.addItem(settingsWebUISubMenuItem);

    return settingsMenuItem;
}