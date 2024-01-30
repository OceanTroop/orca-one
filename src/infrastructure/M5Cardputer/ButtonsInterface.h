#ifdef M5CARDPUTER

#pragma once

#include <memory>

#include "../../domain/entities/ButtonsInterfaceBase.h"

#define DEBOUNCE_MS 10

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Infrastructure::M5Cardputer
    {
        class ButtonsInterface : public Domain::Entities::ButtonsInterfaceBase
        {
        public:
            ButtonsInterface();
            void begin();
            void loop();

        private:
            // Button _buttonNext = Button(BUTTON_B_PIN, true, DEBOUNCE_MS);
            // Button _buttonSelect = Button(BUTTON_A_PIN, true, DEBOUNCE_MS);
        };
    }
#ifdef __cplusplus
}
#endif
#endif