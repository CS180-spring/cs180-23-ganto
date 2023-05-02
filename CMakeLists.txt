cmake_minimum_required(VERSION 3.10)
project(GantoApi)

set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(${PROJECT_SOURCE_DIR})

# Include GoogleTest from the local clone
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Main GantoApi library
add_library(GantoApi SHARED gantoApi.cpp)

# Test executable
add_executable(GantoApiTests tests.cpp)
target_link_libraries(GantoApiTests GantoApi gtest gtest_main)

enable_testing()
add_test(NAME GantoApiTests COMMAND GantoApiTests)
