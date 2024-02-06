#include "AboutScreen.h"
#include "../../services/gui/ScreenManager.h"
#include "../../../domain/entities/DeviceBase.h"

using namespace Applications::Settings::About;
using namespace Applications::Services::GUI;
using namespace Domain::Entities;

void AboutScreen::render(std::shared_ptr<TFT_eSPI> tft)
{
    auto device = DeviceBase::getCurrent();
    auto displayInterface = device->getInterfaces().displayInterface;
    auto deviceName = device->getName();

    tft->setTextColor(DEFAULT_PRIMARY_COLOR);
    tft->setTextDatum(TL_DATUM);

    tft->setCursor(5, 0);

    tft->setTextSize(displayInterface->getTextSizeBig());
    tft->println("  Orca One");

    tft->setTextSize(displayInterface->getTextSizeTiny());
    tft->println("");
    tft->println(" Device: " + deviceName);
    tft->println(" Version: " + String(BUILD_NUMBER));
    tft->println("");
    tft->println(" Contributors:");
    tft->println("   @cyberjulio");
    tft->println("   @marivaaldo");
    tft->println("");
    tft->println(" Join https://bit.ly/hackingtroop");
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
