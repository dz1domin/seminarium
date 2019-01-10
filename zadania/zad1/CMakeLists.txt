# nie trzeba używać tego cmake'a jego zadaniem jest głównie sugerowanie jak można skompilować zadanie
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_COMPILER g++-8.2)
set (CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
add_executable(zad1 zad1.cpp)
target_link_libraries(zad1 ${GTEST_LIBRARIES} pthread)
