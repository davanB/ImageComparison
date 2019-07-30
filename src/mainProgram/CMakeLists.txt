set(PROGRAM_SOURCES
    mainProgram.h 
    mainProgram.cpp
)

# declare lib
add_library(MainProgram STATIC 
    ${PROGRAM_SOURCES}
)

target_include_directories(
    MainProgram PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
    )