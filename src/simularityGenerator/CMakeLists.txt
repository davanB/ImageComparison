set(GENERATOR_SOURCES
    simularityEngine.h 
    simularityEngine.cpp
    simularityGenerator.h
)

# declare lib
add_library(SimularityGenerator STATIC 
    ${GENERATOR_SOURCES}
)

target_include_directories(
    SimularityGenerator PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
    )