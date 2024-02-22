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
class ConfigJsonParser: public IConfigParser
{
private:
    /* data */
public:
    template<struct T>
    int parse(std::string input, std::map<std::string,std::string> *output);
};
