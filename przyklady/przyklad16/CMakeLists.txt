cmake_minimum_required(VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(przyklad16 przyklad16.cpp)
target_link_libraries(przyklad16 ${GTEST_LIBRARIES} -lgmock pthread)
