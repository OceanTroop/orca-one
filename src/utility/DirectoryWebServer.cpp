#include "DirectoryWebServer.h"
#include <WiFi.h>

using namespace Utility;

void DirectoryWebServer::handleFile()
{
    auto filePath = this->uri();

    if (filePath.startsWith("/"))
        filePath = filePath.substring(1);

    if (filePath.length() == 0)
        filePath = "index.html";

    auto file = this->_fs.open(String(this->_basePath) + filePath, FILE_READ);

    if (!file)
    {
        filePath = "index.html";
        file = this->_fs.open(String(this->_basePath) + filePath, FILE_READ);
    }

    String contentType;

    if (filePath.endsWith(".html"))
        contentType = "text/html";
    else if (filePath.endsWith(".css"))
        contentType = "text/css";
    else if (filePath.endsWith(".js"))
        contentType = "text/javascript";
    else
        contentType = "text/plain";

    this->streamFile(file, contentType);

    file.close();
}

DirectoryWebServer::DirectoryWebServer(fs::FS &fs, const char *basePath, IPAddress addr, int port) : WebServer(addr, port), _fs(fs), _basePath(basePath)
{
}

DirectoryWebServer::DirectoryWebServer(fs::FS &fs, const char *basePath, int port) : WebServer(port), _fs(fs), _basePath(basePath)
{
}

void DirectoryWebServer::begin()
{
    if (this->_isRunning || this->_isStopping)
        return;

    this->_isRunning = true;

    if (this->_ssid != nullptr)
    {
        WiFi.softAP(this->_ssid, this->_password);
    }

    this->onNotFound(std::bind(&DirectoryWebServer::handleFile, this));

    WebServer::begin();

    xTaskCreatePinnedToCore([](void *param)
                            { DirectoryWebServer *server = static_cast<DirectoryWebServer *>(param);
                            while(server->_isRunning && !server->_isStopping)
                            {
                                server->handleClient();
                            }
                            
                            vTaskDelete(nullptr); },
                            "DirectoryWebServer_Start", configMINIMAL_STACK_SIZE + 4096, this, 1, nullptr, portNUM_PROCESSORS - 1);
}

void DirectoryWebServer::stop()
{
    if (this->_isRunning)
        this->_isStopping = true;

    if (this->_ssid != nullptr)
    {
        WiFi.softAPdisconnect(true);
    }

    WebServer::stop();
}
