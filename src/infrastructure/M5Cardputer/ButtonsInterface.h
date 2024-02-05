#ifdef M5CARDPUTER

#pragma once

#include <memory>

#include "../utility/Button.h"
#include "../../domain/entities/DeviceBase.h"
#include "../../domain/entities/ButtonsInterfaceBase.h"
#include "../../domain/entities/KeyboardInterfaceBase.h"

using namespace Domain::Entities;

#define BUTTON_SELECT_PIN 0
#define DEBOUNCE_MS 10

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Infrastructure::M5Cardputer
    {
        class ButtonsInterface : public ButtonsInterfaceBase
        {
        public:
            ButtonsInterface();
            void begin();
            void loop();

            virtual bool hasNext() { return true; }
            virtual bool hasPrevious() { return true; }
            virtual bool hasSelect() { return true; }
            virtual bool hasBack() { return true; }

        private:
            std::shared_ptr<KeyboardInterfaceBase> _keyboard = nullptr;
            Button _buttonSelect = Button(BUTTON_SELECT_PIN, true, DEBOUNCE_MS);
        };
    }
#ifdef __cplusplus
}
#endif
#endif