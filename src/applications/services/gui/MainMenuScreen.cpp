#include "MainMenuScreen.h"
#include "../../AppUtils.h"
#include "../../settings/about/AboutApp.h"

using namespace Applications::Services::GUI;
using namespace Applications;

MainMenuScreen::MainMenuScreen(std::shared_ptr<TFT_eSPI> tft) : MenuScreen(tft)
{
    MenuItem appsMenuItem("appsMenuItem", "Apps");

    MenuItem wifiMenuItem("wifiMenuItem", "Wifi");
    MenuItem wifiScanAPsSubMenuItem("wifiScanAPsSubMenuItem", "Scan APs");
    MenuItem wifiSpamSubMenuItem("wifiSpamSubMenuItem", "SPAM APs");
    MenuItem wifiDeautherSubMenuItem("wifiDeautherSubMenuItem", "Deauther APs");
    MenuItem wifiEvilPortalSubMenuItem("wifiEvilPortalSubMenuItem", "Evil Portal");
    wifiMenuItem.addItem(wifiScanAPsSubMenuItem);
    wifiMenuItem.addItem(wifiSpamSubMenuItem);
    wifiMenuItem.addItem(wifiDeautherSubMenuItem);
    wifiMenuItem.addItem(wifiEvilPortalSubMenuItem);

    MenuItem bluetoothMenuItem("bluetoothMenuItem", "Bluetooth");

    MenuItem subGhzMenuItem("subGhzMenuItem", "Sub-GHz");

    MenuItem nfcMenuItem("nfcMenuItem", "NFC");

    MenuItem infraredMenuItem("infraredMenuItem", "Infrared");

    MenuItem badUsbMenuItem("badUsbMenuItem", "Bad USB");

    MenuItem settingsMenuItem("settingsMenuItem", "Settings");

    MenuItem settingsLanguageSubMenuItem("settingsLanguageSubMenuItem", "Language");
    MenuItem settingsLanguageEnglishSubMenuItem("settingsLanguageEnglishSubMenuItem", "English");
    MenuItem settingsLanguagePortuguesBrasilSubMenuItem("settingsLanguagePortuguesBrasilSubMenuItem", "Português (BR)");
    settingsLanguageSubMenuItem.addItem(settingsLanguageEnglishSubMenuItem);
    settingsLanguageSubMenuItem.addItem(settingsLanguagePortuguesBrasilSubMenuItem);
    settingsMenuItem.addItem(settingsLanguageSubMenuItem);

    MenuItem settingsAboutSubMenuItem("settingsAboutSubMenuItem", "About");
    settingsAboutSubMenuItem.setOnClick([]()
                                        { AppUtils::runApplication<Applications::Settings::About::AboutApp>(); });
    settingsMenuItem.addItem(settingsAboutSubMenuItem);

    this->addItem(appsMenuItem);
    this->addItem(wifiMenuItem);
    this->addItem(bluetoothMenuItem);
    this->addItem(subGhzMenuItem);
    this->addItem(nfcMenuItem);
    this->addItem(infraredMenuItem);
    this->addItem(badUsbMenuItem);
    this->addItem(settingsMenuItem);
}