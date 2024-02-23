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

#include <thread>
#include <condition_variable>
#include "IConfigCore.hpp"
#include "IConfigParser.hpp"
#include "IConfigChannel.hpp"

class ConfigCore: public IConfigCore
{
private:
    IConfigChannel * _channel;
    IConfigParser * _parser;
    std::thread _workerTh;
    
public:
    ConfigCore(IConfigChannel * channel, IConfigParser * parser);
    ~ConfigCore(){}
    void _worker();
};
