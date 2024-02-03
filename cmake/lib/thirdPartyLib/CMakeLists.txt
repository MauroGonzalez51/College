cmake_minimum_required(VERSION 3.10.2)

project(thirdPartyLib)

add_library(thirdPartyLib INTERFACE)

target_include_directories(thirdPartyLib INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")

file(GLOB_RECURSE THIRD_PARTY_LIB_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(thirdPartyLib_test)

target_sources(thirdPartyLib_test PRIVATE "${THIRD_PARTY_LIB_SOURCES}")
target_link_libraries(thirdPartyLib_test PUBLIC thirdPartyLib)

# In case the library have more than just header files

# cmake_minimum_required(VERSION 3.10.2)

# project(lib)

# add_library(lib)

# target_include_directories(lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")
# target_sources(lib PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")