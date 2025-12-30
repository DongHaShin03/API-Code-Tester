cmake_minimum_required(VERSION 3.10)

project(Sorter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(OpenMP REQUIRED)

add_executable(sort src/SortMain.cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(sort PRIVATE -Wall -Wextra -O3)
endif()