cmake_minimum_required(VERSION 3.20)

project(ZokiiMenu LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT DEFINED ENV{OO_PS4_TOOLCHAIN})
    message(FATAL_ERROR
        "OO_PS4_TOOLCHAIN is not set."
    )
endif()

add_executable(ZokiiMenu
    src/main.cpp
    src/menu.cpp
    src/controller.cpp
)

target_include_directories(ZokiiMenu PRIVATE
    src
    $ENV{OO_PS4_TOOLCHAIN}/include
)

target_compile_options(ZokiiMenu PRIVATE
    -O2
    -fPIC
    -funwind-tables
)

set_target_properties(ZokiiMenu PROPERTIES
    OUTPUT_NAME "ZokiiMenu"
)
