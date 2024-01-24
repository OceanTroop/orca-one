#include "MenuScreen.h"

using namespace Applications::Services::GUI;

void MenuScreen::render(std::shared_ptr<TFT_eSPI> tft)
{
    // TODO: show buttons
    // when first, show: current, current+1 and current+2
    // when last, show current-2, current-1, current
    // else show: current-1, current, current+1
    int totalItems = this->_items.size();

    if (totalItems == 0)
        return;

    for (int i = 0; i < totalItems; i++)
    {
        this->_items.at(i).setSelected(i == this->_currentItemIndex ? true : false);
    }

    std::vector<MenuItem> itemsToShow = std::vector<MenuItem>();

    if (this->_currentItemIndex == 0 || totalItems <= 3) // First
    {
        itemsToShow.push_back(this->_items.at(0));

        if (totalItems > 1)
            itemsToShow.push_back(this->_items.at(1));

        if (totalItems > 2)
            itemsToShow.push_back(this->_items.at(2));
    }
    else if (this->_currentItemIndex == (totalItems - 1)) // Last
    {
        itemsToShow.push_back(this->_items.at(this->_currentItemIndex - 2));
        itemsToShow.push_back(this->_items.at(this->_currentItemIndex - 1));
        itemsToShow.push_back(this->_items.at(this->_currentItemIndex));
    }
    else
    {
        itemsToShow.push_back(this->_items.at(this->_currentItemIndex - 1));
        itemsToShow.push_back(this->_items.at(this->_currentItemIndex));
        itemsToShow.push_back(this->_items.at(this->_currentItemIndex + 1));
    }

    if (itemsToShow.size() > 0)
    {
        itemsToShow.at(0).setPosition(5, 10);
        itemsToShow.at(0).render(this->_tft);
    }

    if (itemsToShow.size() > 1)
    {
        itemsToShow.at(1).setPosition(5, 40);
        itemsToShow.at(1).render(this->_tft);
    }

    if (itemsToShow.size() > 2)
    {
        itemsToShow.at(2).setPosition(5, 70);
        itemsToShow.at(2).render(this->_tft);
    }

    this->_scrollbar.setCurrentItem(this->_currentItemIndex);
    this->_scrollbar.render(tft);
}

void MenuScreen::addItem(MenuItem item)
{
    this->_items.push_back(item);

    if (this->_currentItemIndex < 0)
    {
        this->_currentItemIndex = 0;
        this->_items.at(0).setSelected(true);
    }

    this->_scrollbar.setTotalItems(this->_items.size());
}

void MenuScreen::removeItem(String id)
{
    // todo
    this->_scrollbar.setTotalItems(this->_items.size());
}

void MenuScreen::selectNext()
{
    if (this->_items.size() <= 1)
        return;

    this->_items.at(this->_currentItemIndex).setSelected(false);

    if (this->_currentItemIndex == (this->_items.size() - 1)) // last item
    {
        this->_currentItemIndex = 0;
    }
    else
    {
        this->_currentItemIndex++;
    }

    this->_items.at(this->_currentItemIndex).setSelected(true);

    Screen::render();
}

void MenuScreen::selectPrevious()
{
    if (this->_items.size() <= 1)
        return;

    this->_items.at(this->_currentItemIndex).setSelected(false);

    if (this->_currentItemIndex == 0) // first item
    {
        this->_currentItemIndex = this->_items.size() - 1;
    }
    else
    {
        this->_currentItemIndex--;
    }

    this->_items.at(this->_currentItemIndex).setSelected(true);

    Screen::render();
}
