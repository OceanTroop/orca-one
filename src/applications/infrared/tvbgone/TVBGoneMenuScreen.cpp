#include "TVBGoneMenuScreen.h"
#include "RunScreen.h"
#include "../../services/gui/ScreenManager.h"

using namespace Applications::Infrared::TVBGone;
using namespace Applications::Services::GUI;

TVBGoneMenuScreen::TVBGoneMenuScreen(std::shared_ptr<TFT_eSPI> tft) : MenuScreen(tft)
{
    MenuItem regionAmericasAsia("regionAmericasAsia", "Americas / Asia");
    regionAmericasAsia.setOnClick([tft]()
                                  { auto screen = new RunScreen(TVBGoneType::AmericasAsia, tft);
                                  ScreenManager::setCurrentScreen(screen);
                                  screen->start(); });

    MenuItem regionEMEA("regionEMEA", "EU/MidEast/Africa");
    regionEMEA.setOnClick([tft]()
                          { auto screen = new RunScreen(TVBGoneType::EMEA, tft);
                                  ScreenManager::setCurrentScreen(screen);
                                  screen->start(); });

    this->addItem(this->newBackItem());
    this->addItem(regionAmericasAsia);
    this->addItem(regionEMEA);
}