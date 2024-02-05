#ifdef M5CARDPUTER

#pragma once

#include <memory>

#include "utility/Keyboard.h"
#include "../../domain/entities/KeyboardInterfaceBase.h"

using namespace Domain::Entities;

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Infrastructure::M5Cardputer
    {
        class KeyboardInterface : public KeyboardInterfaceBase
        {
        private:
            Keyboard_Class Keyboard = Keyboard_Class();

        public:
            KeyboardInterface() : KeyboardInterfaceBase(){};

            void begin();
            void loop();

            uint8_t isPressed();
            bool isChange();
            bool isKeyPressed(char c);
            bool capslocked();
        };
    }
#ifdef __cplusplus
}
#endif
#endif