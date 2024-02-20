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
#include <fstream>
#include <memory>
#include <future>
#include "IConfigChannel.hpp"

namespace MQTTMANAGER
{           
    class ConfigFile: public IConfigChannel 
    {
    private:
    std::string _path;
    bool _read_guard;
    void _read_file_content();
    std::future<void> _f;
    public:

        ConfigFile(std::string path, bool home);
        ~ConfigFile();
        /**
         * @brief Read from channel
         * 
         * @return int :    0 - No Error, 
         *                  -1 - Unable to read 
         */
        int read();
    };
}



