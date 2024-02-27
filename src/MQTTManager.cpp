/**
 * @file MQTTManager.cpp
 * @author amq84
 * @brief 
 * @version 0.1
 * @date 2024-02-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "MQTTManager.hpp"
using std::placeholders::_1;

MQTTManager::MQTTManager(IConfigCore * cfg):
_cfg(cfg)
{
    cfg->OnCfgAvailable = std::bind(&MQTTManager::OnConfigAvailableHandler,this,_1);
}

MQTTManager::~MQTTManager()
{
}

void MQTTManager::run()
{ 
    apiHandle.InitializeLogging(Aws::Crt::LogLevel::Info, stderr);
    
    Aws::Iot::Mqtt5ClientBuilder *builder = Aws::Iot::Mqtt5ClientBuilder::NewMqtt5ClientBuilderWithMtlsFromPath(
            _cfgdata.endpoint.c_str(),
            _cfgdata.x509certificate.c_str(),
            _cfgdata.privatekey.c_str()
    );
    // Check if the builder setup correctly.
    if (builder == nullptr)
    {
        printf(
            "Failed to setup mqtt5 client builder with error code %d: %s", LastError(), ErrorDebugString(LastError()));
    }else
    {
        printf("Builder created succesfully! \n\r");
    }
    std::shared_ptr<Mqtt5::ConnectPacket> connectOptions = std::make_shared<Mqtt5::ConnectPacket>();
    connectOptions->WithClientId(String(_cfgdata.uuid.c_str()));
    connectOptions->WithKeepAliveIntervalSec(60);
    builder->WithConnectOptions(connectOptions);
    builder->WithClientConnectionSuccessCallback (std::bind(&MQTTManager::OnConnectHandler,this,_1));
    builder->WithClientDisconnectionCallback (std::bind(&MQTTManager::OnDisconnectHandler,this,_1));
    builder->WithClientStoppedCallback (std::bind(&MQTTManager::OnStoppedHandler,this,_1));
    _client = builder->Build();
    if (_client == nullptr)
    {
        fprintf(
            stdout, "Failed to Init Mqtt5Client with error code %d: %s", LastError(), ErrorDebugString(LastError()));
    }else
    {
        printf("Succesfully created Mqtt5 client \n\r");
    }
    _client->Start();
    int publishedCount=0;
    while(true)
    {
        String message = "\"" + String("Flowmeter") + std::to_string(publishedCount + 1).c_str() + "\"";
        ByteCursor payload = ByteCursorFromString(message);
        std::shared_ptr<Mqtt5::PublishPacket> publish = std::make_shared<Mqtt5::PublishPacket>(
            "Flowmeter", payload, Mqtt5::QOS::AWS_MQTT5_QOS_AT_LEAST_ONCE);
        _client->Publish(publish);
        publishedCount++;
        std::this_thread::sleep_for(10000ms);
    }
}

void MQTTManager::OnConfigAvailableHandler(ConfigData cfg)
{
    printf("=============== OnCfgAvailable ====\n\r");
    printf("Endpoint: %s \n\r", cfg.endpoint.c_str());
    printf("Port: %i \n\r", cfg.port);
    printf("x509certificate: %s \n\r", cfg.x509certificate.c_str());
    printf("privatekey: %s \n\r", cfg.privatekey.c_str());
    printf("Vendor: %s \n\r", cfg.vendor.c_str());
    printf("UUID: %s \n\r", cfg.uuid.c_str());
    _cfgdata = cfg;
    _cfg->OnCfgAvailable = nullptr;
    _Th = std::thread(&MQTTManager::run, this);
    printf("===================================\n\r");
}

void MQTTManager::connect()
{
    //trigger connection
}

void MQTTManager::disconnect()
{
    //trigger disconnection
}
void MQTTManager::_print_OnConnectionSuccessEventData(const Mqtt5::OnConnectionSuccessEventData &eventData)
{
    if(eventData.connAckPacket != nullptr)
    {
        if(eventData.connAckPacket->getReasonString().has_value())
        {
            printf("Connect reason: %s \n\r", eventData.connAckPacket->getReasonString().value().c_str());
        }
        if(eventData.connAckPacket->getAssignedClientIdentifier().has_value())
        {
            printf("AssignedClientIdentifier : %s \n\r", eventData.connAckPacket->getAssignedClientIdentifier().value().c_str());
        }
        
        if(!eventData.connAckPacket->getUserProperty().empty())
        {
            for(auto prop: eventData.connAckPacket->getUserProperty())
            {
                printf("Name: %s - Value: %s \n\r", prop.getName().c_str(), prop.getValue().c_str());
            }
            
        }
    }
    if(eventData.negotiatedSettings != nullptr)
    {
        printf("Server Keep Alive: %i \n\r", eventData.negotiatedSettings->getServerKeepAliveSec());
        printf("Maximum Packet size: %i \n\r", eventData.negotiatedSettings->getMaximumPacketSizeToServer());
        printf("Wild card subscription enabled: %s \n\r", eventData.negotiatedSettings->getWildcardSubscriptionsAvailable()? "true" : "false");
    }
}

void MQTTManager::OnConnectHandler(const Mqtt5::OnConnectionSuccessEventData &eventData)
{
    printf("Device connected!\n\r");
    _print_OnConnectionSuccessEventData(eventData);
    // Capture relevant information, if needed
    // Start serial-server
    
}

void MQTTManager::OnDisconnectHandler(const Mqtt5::OnDisconnectionEventData &eventData)
{
    printf("DisConnected with reason code: %i \n\r", eventData.errorCode);
    if(eventData.disconnectPacket != nullptr)
    {
        if(eventData.disconnectPacket->getReasonString().has_value())
        {
            //printf("Disconnect reason:", eventData.disconnectPacket->getReasonString().value().c_str());
        }        
    }
    // Re-Start the client
    _client->Start();
}

void MQTTManager::OnStoppedHandler(const Mqtt5::OnStoppedEventData &)
{
    printf("Stopped!\n\r");
    // Currently not being used
}

