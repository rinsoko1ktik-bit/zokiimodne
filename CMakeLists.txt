cmake_minimum_required(VERSION 3.20)

project(ZokiiMenu LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT DEFINED ENV{OO_PS4_TOOLCHAIN})
    message(FATAL_ERROR "OO_PS4_TOOLCHAIN is not set.")
endif()

set(OPENORBIS "$ENV{OO_PS4_TOOLCHAIN}")

message(STATUS "OpenOrbis: ${OPENORBIS}")

add_executable(ZokiiMenu
    src/main.cpp
    src/menu.cpp
    src/controller.cpp
)

target_include_directories(ZokiiMenu PRIVATE
    src
    ${OPENORBIS}/include
)

# OpenOrbis libraries
target_link_directories(ZokiiMenu PRIVATE
    ${OPENORBIS}/lib
)

target_compile_options(ZokiiMenu PRIVATE
    -O2
    -fPIC
    -funwind-tables
)

target_link_options(ZokiiMenu PRIVATE
    -Wl,--gc-sections
)
