#include "Translate.h"

#include <ArduinoJson.h>

using namespace Applications;

Translate *Translate::_instance = nullptr;
bool Translate::_initialized = false;

void Translate::deserialize(String jsonString)
{
    JsonDocument doc;

    auto error = deserializeJson(doc, jsonString);

    if (error)
        return;

    for (const auto &kvp : doc.as<JsonObjectConst>())
    {
        const auto key = kvp.key().c_str();
        const auto value = kvp.value().as<String>();

        this->_texts[key] = value;
    }
}

Translate::Translate(Language language, String jsonString) : _language(language)
{
    if (Translate::_initialized)
    {
        throw std::runtime_error("Device previous initialized. Please, define Device only time. Use: Translate::getInstance()");
    }

    this->deserialize(jsonString);

    Translate::_initialized = true;
    Translate::_instance = this;
}

Translate *Translate::getInstance()
{
    return Translate::_instance;
}

Translate *Translate::fromFile(Language language, fs::FS &fs, const char *fileName)
{
    auto file = fs.open(fileName, FILE_READ);

    if (!file)
        return new Translate(language, "{}");

    String jsonString = file.readString();

    file.close();

    return new Translate(language, jsonString);
}

Language Translate::getLanguage()
{
    return this->_language;
}

String Translate::get(String key)
{
    auto pair = _texts.find(key);

    if (pair != _texts.end())
    {
        return pair->second;
    }

    return "";
}