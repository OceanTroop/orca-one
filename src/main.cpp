#include <TFT_eSPI.h>

#include "applications\services\gui\ScreenManager.h"
#include "applications\services\gui\MenuScreen.h"
using namespace Applications::Services::GUI;

#include "domain\entities\InterfaceType.h"
using namespace Domain::Entities;

#include "infrastructure\M5StickCPlus1_1\Device.h"
using namespace Infrastructure::M5StickCPlus1_1;

Device device = Device();

std::shared_ptr<TFT_eSPI> tft;

// void drawScrollBar(int scrollPosition)
// {
//   // Desenha a barra de rolagem na lateral direita
//   tft->fillRect(TFT_HEIGHT - 6, 0, 2, TFT_WIDTH, TFT_GREEN);

//   // Calcula a posição da "cabeça" da barra de rolagem
//   int barHeight = TFT_WIDTH * TFT_HEIGHT / 800; // Ajuste conforme necessário
//   int barY = map(scrollPosition, 0, TFT_WIDTH - barHeight, 0, TFT_WIDTH - barHeight);

//   // Desenha a "cabeça" da barra de rolagem
//   tft->fillRect(TFT_HEIGHT - 10, barY, 10, barHeight, TFT_GREEN);
// }

void printlnCharByChar(const char *text)
{
  tft->setTextColor(TFT_GREEN);
  tft->setTextSize(2);
  tft->setCursor(0, 0);

  size_t textSize = strlen(text);

  for (int i = 0; i < textSize; i++)
  {
    char c = text[i];
    tft->print(c);
    delay(60);
  }
}

void drawSplash()
{
  tft->fillScreen(TFT_BLACK);
  printlnCharByChar("Wake up, Neo...");
  delay(2 * 1000);

  tft->fillScreen(TFT_BLACK);
  printlnCharByChar("Follow the white rabbit.");
  delay(2 * 1000);

  tft->fillScreen(TFT_BLACK);
  printlnCharByChar("Knock, knock, Neo.");
  delay(2 * 1000);
}

void setup()
{
  device.begin();

  auto displayInterface = device.getInterfaces().displayInterface;
  tft = displayInterface->getTFT();

  // drawSplash();

  tft->fillScreen(TFT_BLACK);

  ScreenManager *screenManager = new ScreenManager(tft);

  std::shared_ptr<MenuScreen> mainMenuScreen = std::make_shared<MenuScreen>(tft);

  MenuItem wifiMainMenuItem = MenuItem("wifiMainMenuItem", "Wifi", nullptr);
  MenuItem bluetoothMainMenuItem = MenuItem("bluetoothMainMenuItem", "Bluetooth", nullptr);
  MenuItem applicationsMainMenuItem = MenuItem("applicationsMainMenuItem", "Applications", nullptr);
  MenuItem settingsMainMenuItem = MenuItem("settingsMainMenuItem", "Settings", nullptr);

  mainMenuScreen->addItem(wifiMainMenuItem);
  mainMenuScreen->addItem(bluetoothMainMenuItem);
  mainMenuScreen->addItem(applicationsMainMenuItem);
  // mainMenuScreen->addItem(settingsMainMenuItem);

  screenManager->setCurrentScreen(mainMenuScreen);

  // drawScrollBar(30);
}

void loop()
{
  device.loop();
}