#include "AbstractGuiModule.h"

using namespace Applications::Services::GUI;

void AbstractGuiModule::setId(String id)
{
    this->_id = id;
}

const String AbstractGuiModule::getId()
{
    return this->_id;
}
