project(PlatformOS)

set (SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set (INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES
    CONFIGURE_DEPENDS
    ${SRC_DIR}/*.cpp
)

add_library(
    ${PROJECT_NAME}
    SHARED
    ${SOURCES}
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    Core
    Platform
)

file(GLOB_RECURSE HEADERS
    CONFIGURE_DEPENDS
    ${INC_DIR}/EdraSDK/${PROJECT_NAME}/*.hpp
)

source_group(
    TREE ${INC_DIR}
    PREFIX "Headers Files"
    FILES ${HEADERS}
)

target_sources(${PROJECT_NAME}
    PRIVATE
    ${HEADERS}
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${INC_DIR}>
    $<INSTALL_INTERFACE:include>
)

target_compile_definitions(${PROJECT_NAME} PRIVATE EDRA_PLATFORM_OS_BUILD_DLL)

install(
    DIRECTORY ${INC_DIR}/
    DESTINATION include
)

if(CMAKE_VERSION VERSION_GREATER 3.8)
    set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
else()
    set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
endif()
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)