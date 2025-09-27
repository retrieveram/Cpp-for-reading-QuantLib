# CMakeLists.txt
cmake_minimum_required(VERSION 3.15)
project(${fNAME})

# myLibパッケージのヘッダー, ライブラリの検索
message     (STATUS           "  CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}"  )
find_path   (myLib_INCLUDE_DIRS "calcSum.h" PATHS ${CMAKE_SOURCE_DIR}/inc)
find_library(myLib_LIBRARIES    "myLib.lib" PATHS ${CMAKE_SOURCE_DIR}/lib)

# myLibパッケージ用変数の生成
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(myLib 
                         DEFAULT_MSG myLib_INCLUDE_DIRS myLib_LIBRARIES ) 

# 変数の内容確認
if(myLib_FOUND)
    message(STATUS "  Include directory: ${myLib_INCLUDE_DIRS}")
    message(STATUS         "  Libraries: ${myLib_LIBRARIES}"   )
endif()

# ビルド
add_executable            (myExe        ${fNAME}.cpp       )
target_include_directories(myExe PUBLIC ${myLib_INCLUDE_DIRS})
target_link_libraries     (myExe        ${myLib_LIBRARIES}   )