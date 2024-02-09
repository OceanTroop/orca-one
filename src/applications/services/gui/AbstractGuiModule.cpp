#include "AbstractGuiModule.h"
#include "../../../domain/entities/DeviceBase.h"

using namespace Applications::Services::GUI;
using namespace Domain::Entities;

void AbstractGuiModule::setId(String id)
{
    this->_id = id;
}

const String AbstractGuiModule::getId()
{
    return this->_id;
}

void AbstractGuiModule::setTextSizeBig(std::shared_ptr<TFT_eSPI> tft)
{
    auto displayInterface = DeviceBase::getInstance()->getInterfaces().displayInterface;
    tft->setTextSize(displayInterface->getTextSizeBig());
}

void AbstractGuiModule::setTextSizeMedium(std::shared_ptr<TFT_eSPI> tft)
{
    auto displayInterface = DeviceBase::getInstance()->getInterfaces().displayInterface;
    tft->setTextSize(displayInterface->getTextSizeMedium());
}

void AbstractGuiModule::setTextSizeSmall(std::shared_ptr<TFT_eSPI> tft)
{
    auto displayInterface = DeviceBase::getInstance()->getInterfaces().displayInterface;
    tft->setTextSize(displayInterface->getTextSizeSmall());
}

void AbstractGuiModule::setTextSizeTiny(std::shared_ptr<TFT_eSPI> tft)
{
    auto displayInterface = DeviceBase::getInstance()->getInterfaces().displayInterface;
    tft->setTextSize(displayInterface->getTextSizeTiny());
}

void AbstractGuiModule::drawBorderedText(std::shared_ptr<TFT_eSPI> tft, String text, int x, int y, int borderSize, uint16_t textColor, uint16_t borderColor)
{
    tft->setTextColor(borderColor);

    for (int i = -borderSize; i <= borderSize; i++)
    {
        for (int j = -borderSize; j <= borderSize; j++)
        {
            if (i != 0 || j != 0)
            {
                tft->setCursor(x + i, y + j);
                tft->print(text);
            }
        }
    }

    tft->setTextColor(textColor);
    tft->setCursor(x, y);
    tft->print(text);
}
