#include "WebUIScreen.h"
#include "../../../utility/FileUtility.h"
#include "../../../domain/entities/DeviceBase.h"
#include "../../../domain/entities/Settings.h"

using namespace Applications::Settings::WebUI;
using namespace Domain::Entities;
using namespace Utility;

void WebUIScreen::startServer()
{
    auto settings = DeviceBase::getInstance()->getSettings();
    this->_ssid = settings->getWifiSSID();
    this->_ssidPassword = settings->getWifiPassword();

    if (!this->_ssid || this->_ssid.isEmpty())
        this->_ssid = "OrcaOne-AP";

    if (!this->_ssidPassword || this->_ssidPassword.isEmpty())
        this->_ssidPassword = "orcaoneap";

    this->_webServer = new DirectoryWebServer(SPIFFS_STORAGE, BASE_PATH);
    this->_webServer->setWiFi(this->_ssid.c_str(), this->_ssidPassword.c_str());
    this->_webServer->on("/settings", HTTP_GET, std::bind(&WebUIScreen::handleSettingsGet, this));
    this->_webServer->on("/settings", HTTP_POST, std::bind(&WebUIScreen::handleSettingsPost, this));
    this->_webServer->begin();
}

void WebUIScreen::stopServer()
{
    this->_webServer->stop();

    vTaskDelay(pdMS_TO_TICKS(200));

    delete this->_webServer;
}

WebUIScreen::WebUIScreen(std::shared_ptr<TFT_eSPI> tft) : Screen(tft)
{
}

void WebUIScreen::render(std::shared_ptr<TFT_eSPI> tft)
{
    auto displayInterface = DeviceBase::getInstance()->getInterfaces().displayInterface;
    auto displaySettings = displayInterface->getSettings();

    this->startServer();

    IPAddress ipAddress = WiFi.softAPIP();

    tft->setTextColor(DEFAULT_PRIMARY_COLOR);

    this->setTextSizeMedium(tft);
    auto title = String("Web UI");
    auto titleX = (displaySettings.width - tft->textWidth(title)) / 2;
    tft->drawString(title, titleX, 5);

    this->setTextSizeSmall(tft);
    tft->setCursor(0, 35);
    tft->println("SSID: " + this->_ssid);
    tft->println("Password: " + this->_ssidPassword);
    tft->println("URL:\nhttp://" + ipAddress.toString());
    tft->println("\nPress select to exit");
}

void WebUIScreen::buttonSelectPressed()
{
    this->stopServer();
    this->buttonBackPressed();
}

void WebUIScreen::handleSettingsGet()
{
    this->_webServer->send(200, "application/json", DeviceBase::getInstance()->getSettings()->serialize());
}

void WebUIScreen::handleSettingsPost()
{
    if (!this->_webServer->hasArg("plain"))
        return;

    auto jsonString = this->_webServer->arg("plain");

    Domain::Entities::Settings newSettings(jsonString);
    auto currentSettings = DeviceBase::getInstance()->getSettings();

    currentSettings->setDeviceName(newSettings.getDeviceName());
    currentSettings->setWifiSSID(newSettings.getWifiSSID());
    currentSettings->setWifiPassword(newSettings.getWifiPassword());

    DeviceBase::getInstance()->saveSettings();
    this->_webServer->send(200, "text/plain", "Settings saved!");

    ESP.restart();
}
