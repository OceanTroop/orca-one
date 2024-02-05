#pragma once

#include <WString.h>
#include <TFT_eSPI.h>

#include "AbstractGuiModule.h"
#include "../../AppContext.h"

using namespace Domain::Entities;

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Applications::Services::GUI
    {
        class ButtonMenu : public AbstractGuiModule
        {
        protected:
            int _borderColor = TFT_GREEN;
            int _backgroundColor = TFT_GREEN;
            int _textColor = TFT_GREEN;
            int _selectedTextColor = TFT_BLACK;
            int _width = -1;
            int _height = -1;
            int _x = -1;
            int _y = -1;
            String _text;
            bool _selected = false;
            std::function<void()> _onClick = nullptr;

        public:
            void render(std::shared_ptr<TFT_eSPI> tft);

            void setBorderColor(int color);
            void setBackgroundColor(int color);
            void setTextColor(int color);
            void setSelectedTextColor(int color);
            void setSize(int width, int height);
            void setPosition(int x, int y);
            void setText(String text);
            void setSelected(bool selected);
            bool isSelected();
            void setOnClick(std::function<void()> onClick);
            void click();
            bool isDefinedOnClick();
        };
    }

#ifdef __cplusplus
}
#endif