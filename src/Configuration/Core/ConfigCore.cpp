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

ConfigCore(IConfigChannel * channel, IConfigParser * parser):
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
            
        }
    }
}