# CMakeLists.txt
cmake_minimum_required(VERSION 3.15)
project(${fNAME})
 
find_package(Boost REQUIRED)  #(Boost 1.88.0 REQUIRED)
if(Boost_FOUND)
  message(STATUS "           **Boost found**              "  )
  message(STATUS "  --------------------------------------"  )
  message(STATUS "  Boost_INCLUDE_DIRS=${Boost_INCLUDE_DIRS}")
  message(STATUS "  Boost_LIBRARY_DIRS=${Boost_LIBRARY_DIRS}")
  message(STATUS "  Boost_LIBRARIES  = ${Boost_LIBRARIES}   ")
  message(STATUS "  --------------------------------------"  )
endif()

add_executable            (myExe ${fNAME}.cpp)
target_include_directories(myExe PUBLIC ${BOOST_INCLUDE_DIRS})
target_link_libraries     (myExe Boost::boost)
