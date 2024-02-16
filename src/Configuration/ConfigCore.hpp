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

    }
public:
    ConfigCore(IConfigChannel * channel):
    _channel(channel)
    {
        _channel->OnRead = std::bind(&ConfigCore::channelReadHandler, this, std::placeholders::_1);
        _channel->read();
    }
    ~ConfigCore(){}
    
    std::map<std::string, std::string> get()
    {
        return std::map<std::string, std::string>{};
    }
};
}
