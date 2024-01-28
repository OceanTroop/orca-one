#include "MenuItem.h"

using namespace Applications::Services::GUI;

void MenuItem::removeItem(String id)
{
    // todo
}

std::vector<MenuItem> MenuItem::getItems()
{
    return this->_items;
}

bool Applications::Services::GUI::MenuItem::hasItems()
{
    return this->_items.size() > 0;
}

void MenuItem::addItem(MenuItem item)
{
    this->_items.push_back(item);
}
