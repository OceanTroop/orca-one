#include "Screen.h"

using namespace Applications::Services::GUI;

Screen::Screen(std::shared_ptr<TFT_eSPI> tft)
{
    this->_tft = tft;
}

void Screen::render()
{
    this->render(this->_tft);
}

void Screen::setPrevious(std::shared_ptr<Screen> previous)
{
    this->_previous = previous;
}

std::shared_ptr<Screen> Applications::Services::GUI::Screen::getPrevious()
{
    return this->_previous;
}
