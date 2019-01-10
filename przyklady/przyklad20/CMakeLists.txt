cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_COMPILER g++-8.2)
set (CMAKE_CXX_STANDARD 17)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(przyklad20 przyklad20.cpp)
target_link_libraries(przyklad20 ${GTEST_LIBRARIES} -lbenchmark pthread)
