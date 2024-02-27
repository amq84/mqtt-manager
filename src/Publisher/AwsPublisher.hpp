/**
 * @file AwsPublisher.hpp
 * @author amq84
 * @brief 
 * @version 0.1
 * @date 2024-02-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include "IPublisher.hpp"
#include <aws/iot/Mqtt5Client.h>

class AwsPublisher: public IPublisher
{
private:
    std::shared_ptr<Aws::Crt::Mqtt5::Mqtt5Client> _client;
    std::string _clientId;
public:
    AwsPublisher(std::shared_ptr<Aws::Crt::Mqtt5::Mqtt5Client>, std::string);
    ~AwsPublisher();
    void publish_configuration(std::string, std::string);
    void publish_event(std::string, std::string);
    void publish_response(std::string, std::string);
};
