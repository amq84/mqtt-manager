/**
 * @file main.cpp
 * @author amq84
 * @brief 
 * @version 0.1
 * @date 2024-02-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdio.h>
#include <chrono>
#include "MQTTManager.hpp"
#include "ConfigCore.hpp"
#include "ConfigJsonParser.hpp"
#include "ConfigFile.hpp"

using namespace MQTTMANAGER;
using namespace std::chrono_literals;

void OnCfgAvailableHandler(ConfigData cfg);
int main(int argc, char const *argv[])
{
    std::string path{"/.config/mqtt-manager/mqtt-manager-configurator.json"};
    ConfigFile file(path, true);
    ConfigJsonParser parser;
    ConfigCore cfg(&file, &parser);
    cfg.OnCfgAvailable = OnCfgAvailableHandler;
    //MQTTManager *man = new MQTTManager(&cfg);
    while (true)
    {
        this_thread::sleep_for(1000ms);
    }
    //delete man;
    return 0;
}

void OnCfgAvailableHandler(ConfigData cfg)
{
    printf("=============== OnCfgAvailable ====\n\r");
    printf("Endpoint: %s \n\r", cfg.endpoint.c_str());
    printf("Port: %i \n\r", cfg.port);
    printf("x509certificate: %s \n\r", cfg.x509certificate.c_str());
    printf("privatekey: %s \n\r", cfg.privatekey.c_str());
    printf("Vendor: %s \n\r", cfg.vendor.c_str());
    printf("UUID: %s \n\r", cfg.uuid.c_str());
}