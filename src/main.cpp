#include <TFT_eSPI.h>

#include "applications\AppUtils.h"
using namespace Applications;

#include "applications\settings\about\AboutApp.h"

#include "applications\services\gui\ScreenManager.h"
#include "applications\services\gui\MenuScreen.h"
using namespace Applications::Services::GUI;

#include "domain\entities\InterfaceType.h"
using namespace Domain::Entities;

#if defined(M5CARDPUTER)

#include "infrastructure\M5Cardputer\Device.h"
using namespace Infrastructure::M5Cardputer;

#elif defined(M5STICKCPLUS)

#include "infrastructure\M5StickCPlus\Device.h"
using namespace Infrastructure::M5StickCPlus;

#endif

Device device = Device();

std::shared_ptr<TFT_eSPI> tft;

void setup()
{
  device.begin();

  auto displayInterface = device.getInterfaces().displayInterface;
  tft = displayInterface->getTFT();

  ScreenManager *screenManager = new ScreenManager(tft);

  MenuScreen *mainMenuScreen = new MenuScreen(tft);

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

  mainMenuScreen->addItem(appsMenuItem);
  mainMenuScreen->addItem(wifiMenuItem);
  mainMenuScreen->addItem(bluetoothMenuItem);
  mainMenuScreen->addItem(subGhzMenuItem);
  mainMenuScreen->addItem(nfcMenuItem);
  mainMenuScreen->addItem(infraredMenuItem);
  mainMenuScreen->addItem(badUsbMenuItem);
  mainMenuScreen->addItem(settingsMenuItem);

  screenManager->setCurrentScreen(mainMenuScreen);
}

void loop()
{
  device.loop();
}