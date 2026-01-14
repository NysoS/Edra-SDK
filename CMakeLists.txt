cmake_minimum_required(VERSION 3.8)

project(EdraSDK VERSION 0.1.0 LANGUAGES CXX)

include(GNUInstallDirs)

find_package(Threads REQUIRED)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/EdraSDK) 

add_subdirectory(Core)
add_subdirectory(Platform)
add_subdirectory(PlatformOS)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Core)

### INSTALL ###

install(
    TARGETS
        Core
        Platform
        PlatformOS
    EXPORT EdraSDKTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

### Install cmake target ###

install(
    EXPORT EdraSDKTargets
    FILE EdraSDKTargets.cmake
    NAMESPACE EdraSDK::
    DESTINATION lib/cmake/EdraSDK
)

include(CMakePackageConfigHelpers)

configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/EdraSDKConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/EdraSDKConfig.cmake
    INSTALL_DESTINATION lib/cmake/EdraSDK
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/EdraSDKConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/EdraSDKConfig.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/EdraSDKConfigVersion.cmake
    DESTINATION lib/cmake/EdraSDK
)

export(
    EXPORT EdraSDKTargets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/EdraSDKTargets.cmake
    NAMESPACE EdraSDK::
)