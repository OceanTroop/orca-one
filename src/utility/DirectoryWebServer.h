
#pragma once

#include <WiFi.h>
#include <WebServer.h>
#include <FS.h>

namespace Utility
{
    class DirectoryWebServer : public WebServer
    {
    private:
        fs::FS &_fs;
        const char *_basePath;
        bool _useWiFiAP = false;
        bool _isRunning = false;
        bool _isStopping = false;
        const char *_ssid = nullptr;
        const char *_password = nullptr;
        void handleFile();

    public:
        DirectoryWebServer(fs::FS &fs, const char *path, IPAddress addr, int port = 80);
        DirectoryWebServer(fs::FS &fs, const char *path, int port = 80);
        ~DirectoryWebServer() { this->stop(); }

        void setWiFi(const char *ssid, const char *password)
        {
            this->_ssid = ssid;
            this->_password = password;
        }

        virtual void begin();
        virtual void stop();
    };
}
