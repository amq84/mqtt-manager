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
    while(true)
    {
        std::this_thread::sleep_for(2000ms);
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
}

void MQTTManager::connect()
{
    //trigger connection
}

void MQTTManager::disconnect()
{
    //trigger disconnection
}

void MQTTManager::OnConnectHandler(const Mqtt5::OnConnectionSuccessEventData &eventData)
{
    printf("Connected!\n\r");

}

void MQTTManager::OnDisconnectHandler(const Mqtt5::OnDisconnectionEventData &eventData)
{
    printf("DisConnected!\n\r");
}

void MQTTManager::OnStoppedHandler(const Mqtt5::OnStoppedEventData &)
{
    printf("Stopped!\n\r");
}
/*
bool MQTTManager::_parse_cfgfile()
{
    
    std::string homedir(getpwuid(getuid())->pw_dir);
    std::string relativeLocation("/.config/mqtt-manager/");
    std::string fileName("mqtt-manager-configurator.json");

    std::ifstream ifs{(homedir+relativeLocation+fileName)};
    if(ifs)
    {
        std::string data((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
        value dataJson = parse(data.c_str());
        kind k = dataJson.kind();
        auto const& obj = dataJson.get_object();
        if(! obj.empty())
        {
            auto it = obj.begin();
            for(;;)
            {
                
                //std::cout << *indent << json::serialize(it->key()) << " : ";
                //pretty_print(os, it->value(), indent);
                if(++it == obj.end())
                    break;
                //os << ",\n";
            }
        }

        return true;
    }else
    {
        printf("File not found! \n\r");
        return false;
    }
    
}
*/