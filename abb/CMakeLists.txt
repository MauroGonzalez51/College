cmake_minimum_required(VERSION 3.10.2)

project(project)

set(CMAKE_CXX_STANDARD 20)

set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

file(GLOB_RECURSE SOURCES CMAKE_CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(executable ${SOURCES})

target_include_directories(executable PRIVATE ${INCLUDE_DIR})
