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
#include "ConfigData.hpp"

class IConfigCore
{
public:
    std::function<void(ConfigData)> OnCfgAvailable;
};
