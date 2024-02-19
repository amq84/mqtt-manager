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
#include "MQTTManager.hpp"
#include "ConfigCore.hpp"
#include "ConfigFile.hpp"

using namespace MQTTMANAGER;

int main(int argc, char const *argv[])
{
    std::string path{"/.config/mqtt-manager/mqtt-manager.json"};
    ConfigFile file(path, true);
    ConfigCore cfg(&file);
    MQTTManager *man = new MQTTManager(&cfg);
    while (true)
    {
        
    }
    delete man;
    return 0;
}