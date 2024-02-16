/**
 * @file IMQTTManagerInteraction.hpp
 * @author amq84
 * @brief 
 * @version 0.1
 * @date 2024-02-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

namespace MQTTMANAGER
{
    class IMQTTManagerInteraction
    {
    private:
        /* data */
    public:
        virtual void OnConnect()=0;
        virtual void OnDisconnect()=0;        
        virtual void OnError()=0;
    };
        
}