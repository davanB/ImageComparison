set(PARSER_SOURCES
    CommandLineArgsParser.h 
    CommandLineArgsParser.cpp
    CommandLineArgs.h 
    CommandLineArgs.cpp
    cxxopts.hpp 
)

# declare lib
add_library(Parser STATIC 
    ${PARSER_SOURCES}
)

target_include_directories(
    Parser PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
    )