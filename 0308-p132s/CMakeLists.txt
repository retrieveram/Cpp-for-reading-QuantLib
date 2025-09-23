# CMakeLists.txt
cmake_minimum_required(VERSION 3.15)
project(${fNAME})

add_subdirectory(src)

add_executable            (myExe ${fNAME}.cpp)
target_link_libraries     (myExe myLib       )
target_include_directories(myExe PUBLIC "src")