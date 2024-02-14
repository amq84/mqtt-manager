/**
 * @file IMQTTManagerCfg.hpp
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

class IMQTTManagerCfg
{
public:
    virtual std::string endpoint()=0;
    virtual std::string port()=0;
    virtual std::string X509Certificate()=0;
    virtual std::string privateKey()=0;
    virtual std::string vendor()=0;
    virtual std::string uuid()=0; 
};
