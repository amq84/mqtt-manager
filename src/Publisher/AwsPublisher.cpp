/**
 * @file AwsPublisher.cpp
 * @author amq84
 * @brief 
 * @version 0.1
 * @date 2024-02-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "AwsPublisher.hpp"

AwsPublisher::AwsPublisher(std::shared_ptr<Aws::Crt::Mqtt5::Mqtt5Client> client,
                            std::string clientId):
_client(client),
_clientId(clientId)
{

}

AwsPublisher::~AwsPublisher()
{

}

void AwsPublisher::publish_configuration(std::string topic, std::string payload)
{
    //_client->Publish();
    
}
void AwsPublisher::publish_event(std::string topic, std::string payload)
{
    //_client->Publish();
    
}
void AwsPublisher::publish_response(std::string topic, std::string payload)
{
    //_client->Publish();
    
}