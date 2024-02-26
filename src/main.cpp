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

using namespace std::chrono_literals;

void OnCfgAvailableHandler(ConfigData cfg);
int main(int argc, char const *argv[])
{
    std::string path{"/.config/mqtt-manager/mqtt-manager-configurator.json"};
    ConfigFile file(path, true);
    ConfigJsonParser parser;
    ConfigCore cfg(&file, &parser);
    
    MQTTManager *man = new MQTTManager(&cfg);
    while (true)
    {
        this_thread::sleep_for(1000ms);
    }
    //delete man;
    return 0;
}
