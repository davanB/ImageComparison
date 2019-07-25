add_library(Main "")

target_sources(
    Main
    PRIVATE
        CommandLineArgParser.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/CommandLineArgParser.h
    )

target_include_directories(
    Main
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
    )
