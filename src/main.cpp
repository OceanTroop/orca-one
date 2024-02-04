#if defined(M5CARDPUTER)

#include "infrastructure/M5Cardputer/Device.h"
using namespace Infrastructure::M5Cardputer;

#elif defined(M5STICKCPLUS)

#include "infrastructure/M5StickCPlus/Device.h"
#include "infrastructure/M5StickCPlus/M5StickCPlus2.h"
using namespace Infrastructure::M5StickCPlus;

#endif

#include "applications/services/gui/MainMenuScreen.h"
using namespace Applications::Services::GUI;

Device device = Device();

void setup()
{
  device.begin();

  auto displayInterface = device.getInterfaces().displayInterface;
  auto tft = displayInterface->getTFT();

  ScreenManager *screenManager = new ScreenManager(tft);
  MainMenuScreen *mainMenuScreen = new MainMenuScreen(tft);

  screenManager->setCurrentScreen(mainMenuScreen);
}

void loop()
{
  device.loop();
}