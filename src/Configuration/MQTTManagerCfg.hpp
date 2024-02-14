/**
 * @file MQTTManagerCfg.hpp
 * @author amq84
 * @brief 
 * @version 0.1
 * @date 2024-02-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "IMQTTManagerCfg.hpp"

class MQTTManagerCfg: public IMQTTManagerCfg
{
private:
    /* data */
public:
    MQTTManagerCfg(/* args */);
    ~MQTTManagerCfg();
    std::string endpoint();
    std::string port();
    std::string X509Certificate();
    std::string privateKey();
    std::string vendor();
    std::string uuid(); 
};

MQTTManagerCfg::MQTTManagerCfg(/* args */)
{
}

MQTTManagerCfg::~MQTTManagerCfg()
{
}

std::string MQTTManagerCfg::endpoint()
{
    std::string str;

    return str;
}

std::string MQTTManagerCfg::port()
{
    std::string str;

    return str;
}

std::string MQTTManagerCfg::X509Certificate()
{
    std::string str;

    return str;
}

std::string MQTTManagerCfg::privateKey()
{
    std::string str;

    return str;
}

std::string MQTTManagerCfg::vendor()
{
    std::string str;

    return str;
}

std::string MQTTManagerCfg::uuid()
{
    std::string str;

    return str;
}