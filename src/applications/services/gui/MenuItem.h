#pragma once

#include <vector>
#include <WString.h>
#include <TFT_eSPI.h>

#include "ButtonMenu.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Applications::Services::GUI
    {
        class MenuItem : public ButtonMenu
        {
        protected:
            std::vector<MenuItem> _items = std::vector<MenuItem>();

        public:
            MenuItem() {}
            MenuItem(String id, String text, Delegates::OnExecute onClick)
            {
                this->_id = id;
                this->_text = text;
                this->_onClick = onClick;
            }

            virtual void addItem(MenuItem item);
            virtual void removeItem(String id);
        };
    }

#ifdef __cplusplus
}
#endif