/**
 * @file ConfigJsonParser.hpp
 * @author amq84
 * @brief 
 * @version 0.1
 * @date 2024-02-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include "IConfigParser.hpp"
#include <boost/json.hpp>

class ConfigJsonParser: public IConfigParser
{
private:
    bool _value_to_string(std::string *, boost::json::value);
    bool _value_to_int(int *, boost::json::value);
public:
    
    int parse(std::string input, ConfigData *output);
};
