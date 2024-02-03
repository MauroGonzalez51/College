cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebug$<$<CONFIG:Debug>:DEBUG>")
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")

# Link a thirdParty lib (Must have a CMakeLists.txt file)
add_subdirectory("lib/thirdPartyLib") 

project(main)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*cpp")

add_executable(main "${MY_SOURCES}")

# Keep the routes consistent when is compiled
target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/")

# un-comment this line when shipping the .exe to a client
# and comment the other one, copy the /resources/ to /build/
# target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="./resources/")

target_include_directories(main PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")
target_link_libraries(main PRIVATE thirdPartyLib)