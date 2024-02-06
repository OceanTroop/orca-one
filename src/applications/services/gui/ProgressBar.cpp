#include "ProgressBar.h"

using namespace Applications::Services::GUI;

void ProgressBar::render(std::shared_ptr<TFT_eSPI> tft)
{
    tft->drawRect(this->_x, this->_y, this->_width, this->_height, this->_borderColor);

    int filledWidth = map(this->_progress, 0, 100, 0, this->_width);

    tft->fillRect(this->_x + 1, this->_y + 1, filledWidth - 2, this->_height - 2, this->_progressColor);
}

void ProgressBar::setBorderColor(int color)
{
    this->_borderColor = color;
}

void ProgressBar::setProgressColor(int color)
{
    this->_progressColor = color;
}

void ProgressBar::setTextColor(int color)
{
    this->_textColor = color;
}

void ProgressBar::setInvertedTextColor(int color)
{
    this->_invertedTextColor = color;
}

void ProgressBar::setSize(int width, int height)
{
    this->_width = width;
    this->_height = height;
}

void ProgressBar::setPosition(int x, int y)
{
    this->_x = x;
    this->_y = y;
}

void ProgressBar::setProgress(int progress)
{
    this->_progress = progress;
}
