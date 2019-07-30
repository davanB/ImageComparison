add_subdirectory(commandLineArgs)
add_subdirectory(csv)
add_subdirectory(simularityGenerator)
add_subdirectory(Program)

add_executable(ImageComparison main.cpp)

target_link_libraries(ImageComparison SimularityGenerator Parser CsvUtils MainProgram ${OpenCV_LIBS})
