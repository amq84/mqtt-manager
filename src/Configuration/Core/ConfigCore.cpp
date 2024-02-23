/**
 * @file ConfigCore.cpp
 * @author amq84
 * @brief 
 * @version 0.1
 * @date 2024-02-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "ConfigCore.hpp"
#include <chrono>
using namespace std::chrono_literals;

ConfigCore::ConfigCore(IConfigChannel * channel, IConfigParser * parser):
_channel(channel),
_parser(parser)
{
    _workerTh = std::thread(&ConfigCore::_worker, this);
}

void ConfigCore::_worker()
{
    while(true)
    {
        if(OnCfgAvailable)
        {
            std::string channelString;
            if(_channel->read(&channelString)==0)
            {
                ConfigData cfgdata;
                if(_parser->parse(channelString, &cfgdata)==0)
                {
                    OnCfgAvailable(cfgdata);
                }
            }

        }
        std::this_thread::sleep_for(1000ms);
    }
}