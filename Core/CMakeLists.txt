project(Core)

set (SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set (INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES
    CONFIGURE_DEPENDS
    ${SRC_DIR}/*.cpp
)

file(GLOB_RECURSE HEADERS
    CONFIGURE_DEPENDS
    ${INC_DIR}/EdraSDK/${PROJECT_NAME}/*.hpp
)

add_library(
    ${PROJECT_NAME}
    SHARED
    ${SOURCES}
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

target_compile_definitions(${PROJECT_NAME} PRIVATE EDRA_CORE_BUILD_DLL)

install(
    DIRECTORY ${INC_DIR}/
    DESTINATION include
)