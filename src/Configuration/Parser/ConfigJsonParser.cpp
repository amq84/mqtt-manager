/**
 * @file ConfigJsonParser.cpp
 * @author amq84
 * @brief 
 * @version 0.1
 * @date 2024-02-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "ConfigJsonParser.hpp"
#include <boost/json.hpp>
#include <boost/json/src.hpp>

using namespace boost::json;

int ConfigJsonParser::parse(std::string input, ConfigData *output)
{
    value jv = boost::json::parse(input.c_str());
    object obj = jv.as_object();
    if(!_value_to_string(&output->endpoint, obj.at("endpoint")))
    {
        return -1;
    }
    if(!_value_to_int(&output->port, obj.at("port")))
    {
        return -1;
    }
    if(!_value_to_string(&output->x509certificate, obj.at("x509certificate")))
    {
        return -1;
    }
    if(!_value_to_string(&output->privatekey, obj.at("privatekey")))
    {
        return -1;
    }
    if(!_value_to_string(&output->vendor, obj.at("vendor")))
    {
        return -1;
    }
    if(!_value_to_string(&output->uuid, obj.at("uuid")))
    {
        return -1;
    }

    return 0;
}

bool ConfigJsonParser::_value_to_string(std::string *str, value jv)
{
    if(jv.is_string())
    {
        if(str != nullptr)
            *str = value_to<std::string>(jv);
        return true;
    }else
    {
        return false;
    }
}

bool ConfigJsonParser::_value_to_int(int *str, value jv)
{
    if(jv.is_int64())
    {
        if(str != nullptr)
            *str = value_to<int>(jv);
        return true;
    }else
    {
        return false;
    }
}