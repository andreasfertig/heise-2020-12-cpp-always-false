# Copyright (c) Andreas Fertig.
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.16.2 FATAL_ERROR)

set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(IS_GNU On)
else()
    set(IS_GNU Off)
endif()

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
    set(IS_CLANG On)
else()
    set(IS_CLANG Off)
endif()

if(MSVC)
    add_definitions(/WX)
    add_definitions(/W4)
    add_definitions(/wd4189)
    add_definitions(/wd4100)
    add_definitions(/wd4996) # 'fopen': This function or variable may be unsafe. Consider using fopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
    
else()
    add_definitions(-Werror)
    add_definitions(-Wall)
    add_definitions(-Wextra)
    add_definitions(-Wold-style-cast)
    add_definitions(-Wno-unused-variable)
    add_definitions(-Wno-unused-parameter)
    add_definitions(-Wno-unused-value)
    add_definitions(-Wno-cpp)

    if(IS_CLANG)
      add_definitions(-Wno-unused-private-field)
      add_definitions(-Wno-unneeded-internal-declaration)
      
    else()
      
    endif()
endif()

set(EXEC_NAME ${CMAKE_CURRENT_SOURCE_DIR})

# build the filename
get_filename_component(EXEC_NAME "${EXEC_NAME}" NAME)

add_executable(${EXEC_NAME} main.cpp)

