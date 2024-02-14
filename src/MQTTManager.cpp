/**
 * @file MQTTManager.cpp
 * @author amq84
 * @brief 
 * @version 0.1
 * @date 2024-02-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "MQTTManager.hpp"

using namespace MQTTMANAGER;

MQTTManager::MQTTManager()
{
    _run = std::async(std::launch::async, &MQTTManager::run, this);
}

MQTTManager::~MQTTManager()
{
}

int MQTTManager::run()
{    
    while (!_parse_cfgfile())
    {
        std::this_thread::sleep_for(2000ms);
    }

    while(true)
    {

    }
}

void MQTTManager::connect()
{
    //trigger connection
}

void MQTTManager::disconnect()
{
    //trigger disconnection
}

bool MQTTManager::_parse_cfgfile()
{
    std::string data;
    std::string homedir(getpwuid(getuid())->pw_dir);
    std::string relativeLocation("/.config/mqtt-manager/");
    std::string fileName("mqtt-manager-configurator.json");
    _cfgfile = std::move(std::ifstream((homedir+relativeLocation+fileName)));

    return true;
}