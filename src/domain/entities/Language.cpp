#include "Language.h"

#include <sstream>

std::ostream &Domain::Entities::operator<<(std::ostream &os, Language language)
{
    switch (language)
    {
    case Language::English:
        return os << "English";
    case Language::PortuguesBrazil:
        return os << "PortuguesBrazil";
    default:
        return os << "Language not found!";
    }
}

String Domain::Entities::languageToString(Language language)
{
    std::stringstream ss;
    ss << language;
    return String(ss.str().c_str());
}
