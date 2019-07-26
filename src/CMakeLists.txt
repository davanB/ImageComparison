add_subdirectory(commandLineArgs)
add_subdirectory(csv)

add_executable(ImageComparison main.cpp)

target_link_libraries(ImageComparison Parser CsvUtils)
