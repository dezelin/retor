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

# add a target to generate API documentation with Doxygen
find_package(Doxygen)
option(BUILD_DOCUMENTATION "Create and install the HTML based API documentation (requires Doxygen)" ${DOXYGEN_FOUND})

if (BUILD_DOCUMENTATION)
    if (NOT DOXYGEN_FOUND)
        message(FATAL_ERROR "Doxygen is needed to build the documentation.")
    endif()

    set (doxy_main_page ${CMAKE_CURRENT_SOURCE_DIR}/index.md)
    set (doxyfile_in_src ${CMAKE_CURRENT_SOURCE_DIR}/../src/Doxyfile.in)
    set (doxyfile_src ${CMAKE_CURRENT_BINARY_DIR}/../src/Doxyfile)

    configure_file (${doxyfile_in_src} ${doxyfile_src} @ONLY)

    add_custom_target (doc_retor
        COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile_src}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../doc/
        COMMENT "Generating retor library documentation with Doxygen"
        VERBATIM)

    add_custom_target (doc
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)

    add_dependencies (doc doc_retor)

    install (DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../doc/html DESTINATION share/doc/retor)
endif()
