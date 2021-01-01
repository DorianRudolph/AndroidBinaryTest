cmake_minimum_required(VERSION 3.17)
project(AndroidBinaryTest)

set(CMAKE_CXX_STANDARD 14)

find_library(log-lib log)

add_executable(abt main.cpp)
target_link_libraries(abt ${log-lib})