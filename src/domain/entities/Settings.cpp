#include "Settings.h"

#include <ArduinoJson.h>

using namespace Domain::Entities;

String Settings::serialize()
{
    JsonDocument doc;

    doc["deviceName"] = this->_deviceName;
    doc["language"] = static_cast<int>(this->_language);

    String jsonString;
    serializeJson(doc, jsonString);

    return jsonString;
}

void Settings::deserialize(String jsonString)
{
    JsonDocument doc;

    auto error = deserializeJson(doc, jsonString);

    this->_deviceName = doc["deviceName"].as<String>();
    this->_language = static_cast<Language>(doc["deviceName"].as<int>());
}

Settings::Settings(String jsonString)
{
    this->deserialize(jsonString);
}

Settings *Settings::fromFile(fs::FS &fs, const char *fileName)
{
    auto file = fs.open(fileName, FILE_WRITE);

    String jsonString = file.readString();

    file.close();

    return new Settings(jsonString);
}

void Settings::save(fs::FS &fs, const char *fileName)
{
    auto jsonString = this->serialize();

    FileUtility::writeFile(fs, fileName, jsonString.c_str());
}

String Settings::getDeviceName()
{
    return this->_deviceName;
}

Language Settings::getLanguage()
{
    return this->_language;
}
