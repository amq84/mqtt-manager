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

ConfigFile::ConfigFile()
{
    std::string homedir(getpwuid(getuid())->pw_dir);
    std::string relativeLocation("/.config/mqtt-manager/");
    std::string fileName("mqtt-manager-configurator.json");
      try{
        std::ifstream ifs((homedir+relativeLocation+fileName));
        if(ifs.fail() == false)
        {
            std::string data(std::istreambuf_iterator<char>{ifs},
            std::istreambuf_iterator<char>{});
            _data = data;
            boost::system::error_code ec;
            boost::json::value jv = boost::json::parse( _data.c_str(), ec );
            std::cout << _data.c_str() << std::endl;
        }else
        {
            printf("File not found...... \n\r");
        }

        }catch(std::exception const& e){
            std::cout << "There was an error: " << e.what() << std::endl;
        }

}

ConfigFile::~ConfigFile()
{

}

ConfigFile::tError ConfigFile::endpoint()
{
    return FILE_NOERR;
}

ConfigFile::tError ConfigFile::port()
{
    return FILE_NOERR;
}

ConfigFile::tError ConfigFile::X509Certificate()
{
    return FILE_NOERR;
}

ConfigFile::tError ConfigFile::privateKey()
{
    return FILE_NOERR;
}

ConfigFile::tError ConfigFile::vendor()
{
    return FILE_NOERR;
}

ConfigFile::tError ConfigFile::uuid()
{
    return FILE_NOERR;
}