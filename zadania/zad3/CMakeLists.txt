# podobnie jak z poprzednimi cmake'amin ten także jest orientacyjny
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_COMPILER g++-8.2)
set(CMAKE_CXX_STANDARD 17)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(zad3 zad3.cpp)
target_link_libraries(zad3 ${GTEST_LIBRARIES} -lbenchmark pthread)
