cmake_minimum_required(VERSION 3.10.2)

project(project)

file(GLOB_RECURSE SOURCES CMAKE_CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

set(CMAKE_CXX_STANDARD 20)

add_executable(executable "${SOURCES}")
