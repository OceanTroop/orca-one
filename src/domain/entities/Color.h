#pragma once

#include <iostream>
#include <WString.h>

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Domain::Entities
    {
        enum ColorScheme
        {
            Default,
            FlipperZero
        };
        enum Color
        {
            Green,
            Black,
            White,
            Orange,
            Yellow,
            Marron
        };
        struct ColorSchemeData
        {
            Color primaryColor;
            Color backgroundColor;

            ColorSchemeData(Color primary, Color background) : primaryColor(primary), backgroundColor(background) {}
        };

        uint16_t colorToUInt16(Color color);

        String colorSchemeToString(ColorScheme scheme);
        ColorSchemeData colorSchemeToData(ColorScheme scheme);
    }
#ifdef __cplusplus
}
#endif