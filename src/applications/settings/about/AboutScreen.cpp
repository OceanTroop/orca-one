#include "AboutScreen.h"
#include "../../services/gui/ScreenManager.h"
#include "../../../domain/entities/DeviceBase.h"

using namespace Applications::Settings::About;
using namespace Applications::Services::GUI;
using namespace Domain::Entities;

void AboutScreen::render(std::shared_ptr<TFT_eSPI> tft)
{
    auto device = DeviceBase::getCurrent();
    auto deviceName = device->getName();

    tft->setTextColor(TFT_GREEN);
    tft->setTextDatum(TL_DATUM);

    tft->setCursor(5, 0);

    tft->setTextSize(3);
    tft->println("  Orca One");

    tft->setTextSize(1);
    tft->println("");
    tft->println(" Device: " + deviceName);
    tft->println("");
    tft->println(" Contributors:");
    tft->println("   @cyberjulio");
    tft->println("   @marivaaldo");
    tft->println("");
    tft->println(" Join http://bit.ly/hackingtroop");
}

void AboutScreen::buttonSelectPressed()
{
    ScreenManager::setToPreviousScreen();
}

void AboutScreen::buttonNextPressed()
{
    ScreenManager::setToPreviousScreen();
}

void AboutScreen::buttonPreviousPressed()
{
    ScreenManager::setToPreviousScreen();
}
