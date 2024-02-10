cmake_minimum_required(VERSION 3.1)
project(mqtt-manager)

find_package(aws-crt-cpp REQUIRED)

set(${PROJECT_NAME}_SOURCES src/main.cpp)
add_library(${PROJECT_NAME} STATIC ${${PROJECT_NAME}_SOURCES})
target_link_libraries(${PROJECT_NAME} AWS::aws-crt-cpp)
