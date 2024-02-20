/**
 * @file IConfigCore.hpp
 * @author amq84
 * @brief 
 * @version 0.1
 * @date 2024-02-15
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <map>
#include <functional>


class IConfigCore
{
public:
    std::function<void(std::map<std::string, std::string>)> OnCfgAvailable;
    virtual void start()=0;
    virtual void stop()=0;
};
