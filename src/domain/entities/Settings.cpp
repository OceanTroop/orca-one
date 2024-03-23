#include "Settings.h"

#include <ArduinoJson.h>

using namespace Domain::Entities;

String Settings::serialize()
{
    JsonDocument doc;

    doc["deviceName"] = this->_deviceName;
    doc["wifiSSID"] = this->_wifiSSID;
    doc["wifiPassword"] = this->_wifiPassword;
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
    this->_wifiSSID = doc["wifiSSID"].as<String>();
    this->_wifiPassword = doc["wifiPassword"].as<String>();
    this->_language = static_cast<Language>(doc["language"].as<int>());
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

String Settings::getWifiSSID()
{
    return this->_wifiSSID;
}

void Settings::setWifiSSID(String wifiSSID)
{
    this->_wifiSSID = wifiSSID;
}

String Settings::getWifiPassword()
{
    return this->_wifiPassword;
}

void Settings::setWifiPassword(String wifiPassword)
{
    this->_wifiPassword = wifiPassword;
}

Language Settings::getLanguage()
{
    return this->_language;
}

void Settings::setLanguage(Language language)
{
    this->_language = language;
}
