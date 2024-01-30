#include "Scrollbar.h"
#include "../../../domain/entities/DeviceBase.h"

using namespace Applications::Services::GUI;
using namespace Domain::Entities;

void Scrollbar::render(std::shared_ptr<TFT_eSPI> tft)
{
    auto displayInterface = DeviceBase::getCurrent()->getInterfaces().displayInterface;
    auto displaySettings = displayInterface->getSettings();

    tft->fillRect(displaySettings.width - 9, 0, 2, displaySettings.height, TFT_GREEN);

    int scrollBarHeight = displaySettings.height / this->_totalItems;
    int scrollBarY = this->_currentItem * scrollBarHeight;

    if (this->_currentItem + 1 == this->_totalItems)
        scrollBarY = displaySettings.height - scrollBarHeight;

    tft->fillRect(displaySettings.width - 11, scrollBarY, 6, scrollBarHeight, TFT_GREEN);
}

void Scrollbar::setCurrentItem(int currentItem)
{
    this->_currentItem = currentItem;
}

void Scrollbar::setTotalItems(int totalItems)
{
    this->_totalItems = totalItems;
}
