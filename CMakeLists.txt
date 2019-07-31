cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(ImageComparison)
set (CMAKE_CXX_STANDARD 14)

# place binaries and libraries according to GNU standards
include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

# we use this to get code coverage
if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()

include(cmake/googletest.cmake)
fetch_googletest(
    ${PROJECT_SOURCE_DIR}/cmake
    ${PROJECT_BINARY_DIR}/googletest
    )

option(COVERALLS "Turn on coveralls support" OFF)
option(COVERALLS_UPLOAD "Upload the generated coveralls json" ON)

if (COVERALLS)
    include(cmake/Coveralls.cmake)
    coveralls_turn_on_coverage()

    file(GLOB_RECURSE COVERAGE_SRCS "src/*.cpp" "src/*.h")

    # Create the coveralls target.
    if (COVERALLS)
	coveralls_setup(
        "${COVERAGE_SRCS}" 
        ${COVERALLS_UPLOAD}                 
        "${PROJECT_SOURCE_DIR}/coveralls-cmake/cmake")
    endif()
endif()

enable_testing()
add_subdirectory(src)
add_subdirectory(test)
