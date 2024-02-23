/**
 * @file IConfigParser.hpp
 * @author amq84
 * @brief 
 * @version 0.1
 * @date 2024-02-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include <string>
#include <map>
#include "ConfigData.hpp"

class IConfigParser
{
public:
    
    virtual int parse(std::string, ConfigData *)=0;
};

