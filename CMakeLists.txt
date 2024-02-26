cmake_minimum_required(VERSION 3.1)
project(mqtt-manager)

find_package(aws-crt-cpp REQUIRED)
find_package(Boost 1.78.0 REQUIRED)

if(DEFINED REMOTE_DEBUG)
    message("REMOTE_DEBUG is define value is ${REMOTE_DEBUG}")
else()
    set(REMOTE_DEBUG false)
endif()


set(${PROJECT_NAME}_SOURCES 
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/MQTTManager.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/Configuration/Core/ConfigCore.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/Configuration/Channel/ConfigFile.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/Configuration/Channel/ConfigFile.hpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/Configuration/Channel/IConfigChannel.hpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/Configuration/Parser/ConfigJsonParser.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/Configuration/Parser/ConfigJsonParser.hpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/Configuration/Parser/IConfigParser.hpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/include/MQTTManager.hpp)

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})

target_link_libraries(${PROJECT_NAME} AWS::aws-crt-cpp ${Boost_LIBRARIES})


target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/Configuration/Core
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/Configuration/Parser
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/Configuration/Channel
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/Configuration/Data
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC ${Boost_INCLUDE_DIRS})


if(${REMOTE_DEBUG})
    add_custom_target(build_deploy ALL DEPENDS ${PROJECT_NAME})

    add_custom_target(build_deploy_debug ALL DEPENDS ${PROJECT_NAME})

    add_custom_command(TARGET build_deploy POST_BUILD
    COMMAND /bin/bash   ${CMAKE_CURRENT_SOURCE_DIR}/../scripts/deploy_artifact_on_target.sh ${CMAKE_CURRENT_SOURCE_DIR}/../targets "libmqtt-manager.so" ${PROJECT_NAME}
    )

    add_custom_command(TARGET build_deploy_debug POST_BUILD
    COMMAND /bin/bash   ${CMAKE_CURRENT_SOURCE_DIR}/../scripts/deploy_artifact_on_target.sh ${CMAKE_CURRENT_SOURCE_DIR}/../targets "libmqtt-manager.so" ${PROJECT_NAME}
    COMMAND /bin/bash   ${CMAKE_CURRENT_SOURCE_DIR}/../scripts/start_gdbserver_on_target.sh ${CMAKE_CURRENT_SOURCE_DIR}/../targets ${PROJECT_NAME}
    )  
endif()
