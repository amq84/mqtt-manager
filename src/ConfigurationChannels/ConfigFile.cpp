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

ConfigFile::ConfigFile(std::string path):
_path(path)
{

}

ConfigFile::~ConfigFile()
{

}

int ConfigFile::read()
{
    _f = std::async(std::launch::async, &ConfigFile::_read_file_content, this);
    return 1;
}

int ConfigFile::_read_file_content()
{
    std::ifstream ifs(_path.c_str());
    if(ifs)
    {
        std::string file_content((std::istreambuf_iterator<char>(ifs)),
                 std::istreambuf_iterator<char>());
        OnRead(file_content);
        return 0;
    }
    else
    {
        return 1;
    }
}