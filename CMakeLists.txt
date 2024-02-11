cmake_minimum_required(VERSION 3.1)
project(mqtt-manager)

find_package(aws-crt-cpp REQUIRED)

set(${PROJECT_NAME}_SOURCES src/MQTTManager.cpp)

add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_SOURCES})

target_link_libraries(${PROJECT_NAME} AWS::aws-crt-cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
