#include "MenuItem.h"

using namespace Applications::Services::GUI;

void MenuItem::removeItem(String id)
{
    // todo
}

void MenuItem::addItem(MenuItem item)
{
    this->_items.push_back(item);
}
