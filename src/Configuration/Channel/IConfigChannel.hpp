/**
 * @file IConfigChannel.hpp
 * @author amq84
 * @brief 
 * @version 0.1
 * @date 2024-02-14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <string>
#include <functional>


class IConfigChannel
{
public:
    /**
     * @brief read from configuration channel
     * 
     * @return int error code < 0
     */
    virtual int read(std::string *)=0;
};