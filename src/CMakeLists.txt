set(PARSER_SOURCES
    CommandLineArgsParser.cpp
    CommandLineArgs.cpp
    CommandLineArgsParser.h 
    CommandLineArgs.h 
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

add_executable(Main main.cpp)

target_link_libraries(Main Parser)
