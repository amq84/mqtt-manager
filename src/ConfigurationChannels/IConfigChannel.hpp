/**
 * @file IConfigChannel.hpp
 * @author amq84
 * @brief 
 * @version 0.1
 * @date 2024-02-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <string>
#include <functional>

namespace MQTTMANAGER
{
    class IConfigChannel
    {
    public:
        std::function<void(std::string)> OnRead;
        virtual int read()=0;
    };
}