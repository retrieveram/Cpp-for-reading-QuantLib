# CMakeLists.txt
cmake_minimum_required(VERSION 3.15)
project(${fNAME})

add_library(myLib setXX.cpp calcSum.cpp)

add_executable(myExe ${fNAME}.cpp)
target_link_libraries(myExe myLib)
