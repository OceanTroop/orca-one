#include "Scrollbar.h"
#include "../../../domain/entities/DeviceBase.h"

using namespace Applications::Services::GUI;
using namespace Domain::Entities;

void Scrollbar::render(std::shared_ptr<TFT_eSPI> tft)
{
    tft->fillRect(TFT_HEIGHT - 9, 0, 2, TFT_WIDTH, TFT_GREEN);

    int scrollBarHeight = TFT_WIDTH / this->_totalItems;
    int scrollBarY = this->_currentItem * scrollBarHeight;

    if (this->_currentItem + 1 == this->_totalItems)
        scrollBarY = TFT_WIDTH - scrollBarHeight;

    tft->fillRect(TFT_HEIGHT - 11, scrollBarY, 6, scrollBarHeight, TFT_GREEN);
}

void Scrollbar::setCurrentItem(int currentItem)
{
    this->_currentItem = currentItem;
}

void Scrollbar::setTotalItems(int totalItems)
{
    this->_totalItems = totalItems;
}
