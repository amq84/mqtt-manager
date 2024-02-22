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
        
class ConfigFile: public IConfigChannel 
{
private:
    std::string _path;
public:

    ConfigFile(std::string path, bool home);
    ~ConfigFile();

    int read(std::string *);
};

