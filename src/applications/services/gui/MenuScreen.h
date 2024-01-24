#pragma once

#include <vector>
#include <WString.h>
#include <TFT_eSPI.h>

#include "Screen.h"
#include "MenuItem.h"
#include "Scrollbar.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Applications::Services::GUI
    {
        class MenuScreen : public Screen
        {
        private:
            int _currentItemIndex = -1;
            std::vector<MenuItem> _items = std::vector<MenuItem>();
            Scrollbar _scrollbar;

        public:
            MenuScreen(std::shared_ptr<TFT_eSPI> tft) : Screen(tft) {}

            void render(std::shared_ptr<TFT_eSPI> tft);
            void addItem(MenuItem item);
            void removeItem(String id);
            void selectNext();
            void selectPrevious();
        };
    }

#ifdef __cplusplus
}
#endif