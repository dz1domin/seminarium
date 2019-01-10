# to samo co dla zadania pierwszego
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_COMPILER g++-8.2)
set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
add_executable(zad2 zad2.cpp)
target_link_libraries(zad2 ${GTEST_LIBRARIES} -lgmock pthread)
