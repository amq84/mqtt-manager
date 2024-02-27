/**
 * @file IPublisher.hpp
 * @author amq84
 * @brief 
 * @version 0.1
 * @date 2024-02-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once
#include <string>

class IPublisher
{
public:
    virtual void publish_configuration(std::string, std::string)=0;
    virtual void publish_event(std::string, std::string)=0;
    virtual void publish_response(std::string, std::string)=0;
};