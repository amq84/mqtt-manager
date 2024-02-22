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

ConfigFile::ConfigFile(std::string path, bool home)
{
    if(home)
    {
        _path = std::string(getpwuid(getuid())->pw_dir) + path;
    }else
    {
        _path = path;
    }
}

ConfigFile::~ConfigFile()
{

}

int ConfigFile::read(std::string * data)
{
    std::ifstream ifs(_path.c_str());
    if(ifs)
    {
        std::string file_content((std::istreambuf_iterator<char>(ifs)),
                std::istreambuf_iterator<char>());
        if(data != nullptr)
        {
            *data = file_content;
            return 0;  
        }else
        {
            return -1;
        }               
    }else
    {
        return -1;
    }
}