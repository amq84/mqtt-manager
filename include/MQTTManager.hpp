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
#include <chrono>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <boost/json.hpp>
#include "boost/json/src.hpp"

#include "IMQTTManagerInteraction.hpp"
#include "MQTTManagerCfg.hpp"
#include "ConfigFile.hpp"

#define CONFIGURATION_FILE = "~/.config/mqtt-manager/mqtt-manager-configurator.json";
#define CONFIGURATION_FILE_MAX_SIZE_BYTES = 4096;

using namespace std;

namespace MQTTMANAGER
{
    class MQTTManager
    {
    private:
        Aws::Crt::String _endpoint;
        Aws::Crt::String _port;
        Aws::Crt::String _X509Certificate;
        Aws::Crt::String _privateKey;
        Aws::Crt::String _vendor;
        Aws::Crt::String _uuid;

        weak_ptr<ifstream> _cfgfile;
        future<int> _run;
        unique_ptr<IConfigChannel> channel;
        bool _parse_cfgfile();
    protected:
        int run();
    public:
        MQTTManager();
        ~MQTTManager();
        void connect();
        void disconnect();

    };
        
}