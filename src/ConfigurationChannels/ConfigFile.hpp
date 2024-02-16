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
    void _read_file_content_handler();
    int _read_file_content();
    std::future<void> _fh;
    std::future<int> _f;

    public:

        ConfigFile(std::string path);
        ~ConfigFile();
        
        int read();
    };
}



