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
                           std::string clientId) : _client(client),
                                                   _clientId(clientId)
{
}

AwsPublisher::~AwsPublisher()
{
}

void AwsPublisher::publish_configuration(std::string name, std::string payload)
{
    std::string topic = _clientId + "/" + name + "/" + "configuration";
    std::shared_ptr<Mqtt5::PublishPacket> publish = std::make_shared<Mqtt5::PublishPacket>(
        topic.c_str(), ByteCursorFromString(String(payload.c_str())), Mqtt5::QOS::AWS_MQTT5_QOS_AT_LEAST_ONCE);

    _client->Publish(publish);
}
void AwsPublisher::publish_event(std::string name, std::string payload)
{
    std::string topic = _clientId + "/" + name + "/" + "event";
    std::shared_ptr<Mqtt5::PublishPacket> publish = std::make_shared<Mqtt5::PublishPacket>(
        topic.c_str(), ByteCursorFromString(String(payload.c_str())), Mqtt5::QOS::AWS_MQTT5_QOS_AT_LEAST_ONCE);
    
    _client->Publish(publish);
}
void AwsPublisher::publish_response(std::string name, std::string cmd, std::string payload)
{
    std::string topic = _clientId + "/" + name + "/" + cmd + "/" + "response";
    std::shared_ptr<Mqtt5::PublishPacket> publish = std::make_shared<Mqtt5::PublishPacket>(
        topic.c_str(), ByteCursorFromString(String(payload.c_str())), Mqtt5::QOS::AWS_MQTT5_QOS_AT_LEAST_ONCE);
    
    _client->Publish(publish);
}