#pragma once

#include <WString.h>
#include <TFT_eSPI.h>

#include "AbstractGuiModule.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Applications::Services::GUI
    {
        class Scrollbar : public AbstractGuiModule
        {
        private:
            int _totalItems = 0;
            int _currentItem = -1;

        public:
            void render(std::shared_ptr<TFT_eSPI> tft);
            void setTotalItems(int totalItems);
            void setCurrentItem(int currentItem);
        };
    }

#ifdef __cplusplus
}
#endif