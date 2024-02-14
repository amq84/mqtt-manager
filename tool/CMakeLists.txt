project(mqtt-manager-tool)
cmake_minimum_required(VERSION 3.1)


add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} mqtt-manager)

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

