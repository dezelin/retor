#
#  This file is part of the retor library
#  Copyright (C) 2015  Aleksandar Dezelin <dezelin@gmail.com>
#
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

cmake_minimum_required(VERSION 2.8.4)
project(retor CXX)

# Don't start build from the root directory
if(CMAKE_BINARY_DIR STREQUAL ${CMAKE_SOURCE_DIR})
  message(FATAL_ERROR "type: git clean -df && mkdir build && cd build && cmake .. && make")
endif()

# Set CMake modules path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

# Set make files verbosity
if(CMAKE_BUILD_TYPE MATCHES Debug)
  set(CMAKE_VERBOSE_MAKEFILE 1)
  option(__DEBUG__ "Debug build" ON)
else()
  set(CMAKE_VERBOSE_MAKEFILE 0)
  option(__DEBUG__ "Debug build" OFF)
endif()

# Additional c++ compilation flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Basic set of project directories
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_SOURCE_DIR}/test)

# Enable testing with CTest
include(CTest)

# Requires Boost 1.46 at least
find_package(Boost 1.46 REQUIRED)
find_package(Boost 1.46 COMPONENTS unit_test_framework REQUIRED)

# Define include directories
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include/)

# Generate config header
configure_file(${INCLUDE_DIR}/config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/include/config.h)

# Add subprojects
add_subdirectory(doc)
add_subdirectory(src)
add_subdirectory(test)
