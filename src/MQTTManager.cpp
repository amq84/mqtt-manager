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
using namespace boost::json;

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
        std::this_thread::sleep_for(2000ms);
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
    
    std::string homedir(getpwuid(getuid())->pw_dir);
    std::string relativeLocation("/.config/mqtt-manager/");
    std::string fileName("mqtt-manager-configurator.json");

    std::ifstream ifs{(homedir+relativeLocation+fileName)};
    if(ifs)
    {
        std::string data((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
        value dataJson = parse(data.c_str());
        kind k = dataJson.kind();
        auto const& obj = dataJson.get_object();
        if(! obj.empty())
        {
            auto it = obj.begin();
            for(;;)
            {
                
                //std::cout << *indent << json::serialize(it->key()) << " : ";
                //pretty_print(os, it->value(), indent);
                if(++it == obj.end())
                    break;
                //os << ",\n";
            }
        }

        return true;
    }else
    {
        printf("File not found! \n\r");
        return false;
    }
    
}