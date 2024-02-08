#include "TaskManager.h"
#include "../../domain/entities/DeviceBase.h"

using namespace Applications;
using namespace Domain::Entities;

TaskManager *TaskManager::_instance = nullptr;
bool TaskManager::_initialized = false;

TaskManager::TaskManager()
{
    if (TaskManager::_initialized)
    {
        throw std::runtime_error("TaskManager previous initialized. Please, define TaskManager only time. Use: TaskManager::getInstance()");
    }

    TaskManager::_initialized = true;
    TaskManager::_instance = this;
}

TaskManager *TaskManager::getInstance()
{
    return TaskManager::_instance;
}

void TaskManager::begin()
{
    DeviceBase::getInstance()->begin();

    this->_launcher = new Launcher();
    this->_launcher->begin();
}

void TaskManager::loop()
{
    DeviceBase::getInstance()->loop();

    this->_launcher->loop();
}