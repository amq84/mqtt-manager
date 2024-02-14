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
namespace MQTTMANAGER
{    
       
    const static std::string _FILE = "~/.config/mqtt-manager/mqtt-manager-configurator.json";
    const static uint32_t _FILE_MAX_SIZE_BYTES = 4096;
    class ConfigFile
    {
    private:
    std::string _data;
     
    public:

        ConfigFile();
        ~ConfigFile();
        typedef enum {
            FILE_NOERR,
            FILE_NOT_FOUND,
            FILE_SIZE_EXCEEDED,
            FILE_FORMAT_NOT_JSON,
            FILE_DATA_NOT_CORRECT
        }tError;
        
        tError read();
    };
}



