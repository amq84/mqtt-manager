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

namespace MQTTMANAGER
{
    class MQTTManager
    {
    private:
        /* data */
    public:
        MQTTManager(/* args */);
        ~MQTTManager();
        
        void init();
        void connect();
        void disconnect();
    };
        
}