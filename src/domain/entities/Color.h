#pragma once

#include <iostream>
#include <WString.h>

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Domain::Entities
    {
        enum Color
        {
            Green,
            Black,
            White,
            Orange,
        };

        String colorToString(Color color);
        uint16_t colorToUInt16(Color color);
    }
#ifdef __cplusplus
}
#endif