#include "EventHandler.h"

using namespace Domain::Entities;

void EventHandler::addHandler(std::function<void()> handler)
{
    this->_handlers.push_back(handler);
}

void EventHandler::fireEvent()
{
    for (const auto &handler : this->_handlers)
    {
        handler();
    }
}
