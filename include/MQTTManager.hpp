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


#include "IMQTTManagerInteraction.hpp"

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