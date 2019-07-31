set(GENERATOR_SOURCES
    simularityEngine.h 
    simularityEngine.cpp
    simularityGenerator.h
)

find_package(OpenCV REQUIRED)
add_library(opencv INTERFACE IMPORTED)
set_target_properties(opencv PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${OpenCV_INCLUDE_DIRS}"
  INTERFACE_LINK_LIBRARIES "${OpenCV_LIBS}")

# declare lib
add_library(SimularityGenerator STATIC
    ${GENERATOR_SOURCES}
)

target_link_libraries(SimularityGenerator opencv)

target_include_directories(
    SimularityGenerator PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
    )