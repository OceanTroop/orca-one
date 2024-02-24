#include "Color.h"

#include <TFT_eSPI.h>
#include <sstream>

String Domain::Entities::colorToString(Color color)
{
    std::stringstream ss;
    switch (color)
    {
        case Color::Black:
            ss << "Black";
            break;
        case Color::White:
            ss << "White";
            break;
        case Color::Orange:
            ss << "Orange";
            break;
        case Color::Green:
            ss << "Green";
            break;
        default:
            ss << "Color not found!";
            break;
    }
    return String(ss.str().c_str());
}

uint16_t Domain::Entities::colorToUInt16(Color color)
{
    switch (color)
    {
        case Color::Black:
            return TFT_BLACK;
        case Color::White:
            return TFT_WHITE;
        case Color::Orange:
            return TFT_ORANGE;
        case Color::Green:
            return TFT_GREEN;
    }
}
