project(Core)

set (SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set (INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(
    ${PROJECT_NAME}
    SHARED
    ${SRC_DIR}/main.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    ${INC_DIR}
)

target_compile_definitions(${PROJECT_NAME} PRIVATE EDRA_CORE_EXPORTS)