cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebug$<$CONFIG:Debug>:DEBUG>")
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")

project(main)

set(CMAKE_CXX_STANDARD 20)
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(main "main.cpp" "${MY_SOURCES}")

target_include_directories(main PUBLIC "${INCLUDE_DIR}")
