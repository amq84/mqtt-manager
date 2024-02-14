/**
 * @file ConfigFile.hpp
 * @author amq84
 * @brief 
 * @version 0.1
 * @date 2024-02-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <string>
#include <memory>
#include "IConfigChannel.hpp"

namespace MQTTMANAGER
{           
    class ConfigFile: IConfigChannel 
    {
    private:
    std::unique_ptr<std::string> _path;
     
    public:

        ConfigFile(std::unique_ptr<std::string> path);
        ~ConfigFile();
        
        std::string read();
    };
}



