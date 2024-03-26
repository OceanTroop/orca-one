#include "ComingSoonScreen.h"
using namespace Applications::Services::GUI;

void ComingSoonScreen::render(std::shared_ptr<TFT_eSPI> tft)
{
    tft->setTextDatum(TL_DATUM);
    this->setTextSizeSmall(this->_tft);
    tft->setCursor(0, 0);
    tft->println("");
    tft->println("Coming Soon...");
    tft->println("");
    tft->println("Join https://bit.ly/hackingtroop");
}

void ComingSoonScreen::buttonNextPressed()
{
    this->buttonBackPressed();
}

void ComingSoonScreen::buttonPreviousPressed()
{
    this->buttonBackPressed();
}

void ComingSoonScreen::buttonSelectPressed()
{
    this->buttonBackPressed();
}
