cmake_minimum_required(VERSION 3.8)

project(Edra-SDK)

find_package(Threads REQUIRED)

add_subdirectory(Core)
add_subdirectory(Platform)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Core)

export(
    EXPORT EdraSDKTargets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/EdraSDKTargets.cmake
    NAMESPACE EdraSDK::
)