# CMakeLists.txt
cmake_minimum_required(VERSION 3.15)
project(${fNAME})

# 一般的情報の表示
message(STATUS "                  (   一般情報   )"                 )
message(STATUS "  PROJECT_SOURCE_DIR       = ${PROJECT_SOURCE_DIR}" )
message(STATUS "  CMAKE_SOURCE_DIR         = ${CMAKE_SOURCE_DIR}"   )
message(STATUS "  ========================================"         )

# QuantLib検索                    "E:     ...      -1.37"は各自環境へ
set         (QuantLib_ROOT_DIR    "E:/local/QuantLib-1.37"          )
find_path   (QuantLib_INCLUDE_DIRS "ql/quantlib.hpp" 
                                PATHS ${QuantLib_ROOT_DIR}/include  )
find_library(QuantLib_LIBRARIES    "QuantLib-x64-mt-gd.lib" 
                                PATHS ${QuantLib_ROOT_DIR}/lib      )
# QuantLib変数設定
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(QuantLib 
             DEFAULT_MSG  QuantLib_INCLUDE_DIRS  QuantLib_LIBRARIES    ) 
if(QuantLib_FOUND)
    message(STATUS "               (   QuantLib情報   )"               )
    message(STATUS "  QuantLib_FOUND        = ${QuantLib_FOUND}"       )
    message(STATUS "  QuantLib_INCLUDE_DIRS = ${QuantLib_INCLUDE_DIRS}")
    message(STATUS "  QuantLib_LIBRARIES    = ${QuantLib_LIBRARIES}"   )
    message(STATUS "  ========================================"        )
else()
    message(FATAL_ERROR "*** QuantLib not found ***")
endif()

# Boost検索
find_package(Boost REQUIRED)               #または(Boost 1.88.0 REQUIRED)
message(STATUS "            (   Boost情報   )"            )
message(STATUS "  Boost_FOUND       = ${Boost_FOUND}"       )
message(STATUS "  Boost_INCLUDE_DIRS= ${Boost_INCLUDE_DIRS}")
message(STATUS "  Boost_VERSION     = ${Boost_VERSION}"     )
message(STATUS "  ========================================" )

# 実行ファイルの作成
add_executable(myExe ${fNAME}.cpp)
target_compile_features(myExe PUBLIC cxx_std_17)  # (必須)標準規格指定
# ライブラリとインクルードディレクトリ                      boostは小文字
target_link_libraries(myExe ${QuantLib_LIBRARIES} Boost::boost)
target_include_directories(myExe PRIVATE 
                    ${QuantLib_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
