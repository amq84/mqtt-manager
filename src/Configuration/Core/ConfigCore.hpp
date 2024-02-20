/**
 * @file ConfigCore.hpp
 * @author amq84
 * @brief 
 * @version 0.1
 * @date 2024-02-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <condition_variable>
#include "IConfigCore.hpp"
#include "IConfigChannel.hpp"

namespace MQTTMANAGER
{
class ConfigCore: public IConfigCore
{
private:
    IConfigChannel * _channel;
    void channelReadHandler(std::string data)
    {
        if(_reading_flag)
        {
            _data.clear();
            _data = data;
            //_fParseData = std::async(std::launch::async, &ConfigFile::_parse, this);
        }
    }

    bool _reading_flag;
    std::string _data;
    
public:
    ConfigCore(IConfigChannel * channel):
    _channel(channel)
    {
        _channel->OnRead = std::bind(&ConfigCore::channelReadHandler, this, std::placeholders::_1);
    }
    ~ConfigCore(){}

    void start();
    void stop();
};
}

void MQTTMANAGER::ConfigCore::start()
{
}

void MQTTMANAGER::ConfigCore::stop()
{
}