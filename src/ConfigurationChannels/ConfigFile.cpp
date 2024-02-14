/**
 * @file ConfigFile.cpp
 * @author amq84
 * @brief 
 * @version 0.1
 * @date 2024-02-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <boost/json.hpp>


#include "ConfigFile.hpp"

using namespace MQTTMANAGER;

ConfigFile::ConfigFile(std::unique_ptr<std::string> path):
_path(std::move(path))
{
}

ConfigFile::~ConfigFile()
{

}

std::string ConfigFile::read()
{
    std::ifstream ifs(_path.get()->c_str());
    if(ifs)
    {
        std::string data((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
        return data;
    }else
    {
        return std::string{};
    }
}