/**
 * @file MQTTManager.hpp
 * @author amq84
 * @brief 
 * @version 0.1
 * @date 2024-02-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <string>
#include <memory>
#include <aws/crt/Api.h>
#include <thread>
#include <future>
#include <fstream>
#include "IConfigCore.hpp"
#include "IMQTTManagerInteraction.hpp"
#include <aws/crt/Api.h>
#include <aws/crt/UUID.h>
#include <aws/crt/mqtt/Mqtt5Packets.h>
#include <aws/iot/Mqtt5Client.h>
#include "AwsPublisher.hpp"

#define CONFIGURATION_FILE_MAX_SIZE_BYTES = 4096;
using namespace Aws::Crt;
using namespace std;

class MQTTManager
{
private:
    ConfigData _cfgdata;
    ApiHandle apiHandle;
    IConfigCore * _cfg;
    std::thread _Th;
    std::shared_ptr<Aws::Crt::Mqtt5::Mqtt5Client> _client;
    IPublisher * _publisher;

    void run();
    void OnConfigAvailableHandler(ConfigData);
    void OnConnectHandler(const Mqtt5::OnConnectionSuccessEventData &eventData);
    void OnDisconnectHandler(const Mqtt5::OnDisconnectionEventData &eventData);
    void OnStoppedHandler(const Mqtt5::OnStoppedEventData &);

    void _print_OnConnectionSuccessEventData(const Mqtt5::OnConnectionSuccessEventData &eventData);
public:
    MQTTManager(IConfigCore *);
    ~MQTTManager();
};