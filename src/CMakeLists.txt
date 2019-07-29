add_subdirectory(commandLineArgs)
add_subdirectory(csv)
add_subdirectory(simularityGenerator)

add_executable(ImageComparison main.cpp)

target_link_libraries(ImageComparison SimularityGenerator Parser CsvUtils)
