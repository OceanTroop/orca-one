#include "Settings.h"

#include <ArduinoJson.h>

using namespace Domain::Entities;

String Settings::serialize()
{
    JsonDocument doc;

    doc["deviceName"] = this->_deviceName;
    doc["language"] = static_cast<int>(this->_language);
    doc["color"] = static_cast<int>(this->_primaryColor);

    String jsonString;
    serializeJson(doc, jsonString);

    return jsonString;
}

void Settings::deserialize(String jsonString)
{
    JsonDocument doc;

    auto error = deserializeJson(doc, jsonString);

    this->_deviceName = doc["deviceName"].as<String>();
    this->_language = static_cast<Language>(doc["language"].as<int>());
    this->_primaryColor = static_cast<Color>(doc["color"].as<int>());
}

Settings::Settings(String jsonString)
{
    this->deserialize(jsonString);
}

Settings *Settings::fromFile(fs::FS &fs, const char *fileName)
{
    auto file = fs.open(fileName, FILE_READ);

    if (!file)
        return new Settings();

    String jsonString = file.readString();

    // Serial.println("Settings: " + jsonString);

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

void Settings::setDeviceName(String deviceName)
{
    this->_deviceName = deviceName;
}

Language Settings::getLanguage()
{
    return this->_language;
}

void Settings::setLanguage(Language language)
{
    this->_language = language;
}

Color Settings::getPrimaryColor()
{
    return this->_primaryColor;
}

void Settings::setPrimaryColor(Color color)
{
    this->_primaryColor = color;
}
