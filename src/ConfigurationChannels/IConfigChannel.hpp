/**
 * @file IConfigChannel.hpp
 * @author amq84
 * @brief 
 * @version 0.1
 * @date 2024-02-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <string>

namespace MQTTMANAGER
{
    class IConfigChannel
    {
    public:
        virtual std::string read()=0;
    };
}