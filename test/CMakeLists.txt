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

# Test sources end with _test.cpp
file(GLOB TEST_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *_test.cpp)

# Run through each test source and add it to retor test suite
foreach(test_src ${TEST_SOURCES})
        # Extract the filename without an extension (NAME_WE)
        get_filename_component(test_name ${test_src} NAME_WE)

        # Add compile target
        add_executable(${test_name} ${test_src})

        # Link to Boost libraries and our libretor target library
        target_link_libraries(${test_name} ${Boost_LIBRARIES} ${CMAKE_PROJECT_NAME})

        # Finally add it to test execution
        add_test(retor_test_suite ${test_name})
endforeach()
