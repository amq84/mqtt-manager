/**
 * @file ConfigData.hpp
 * @author amq84
 * @brief 
 * @version 0.1
 * @date 2024-02-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include <string>

struct ConfigData
{
    std::string endpoint;
    int port;
    std::string x509certificate;
    std::string privatekey;
    std::string vendor;
    std::string uuid;
};
