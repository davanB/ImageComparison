find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_subdirectory(commandLineArgs)
add_subdirectory(csv)
add_subdirectory(simularityGenerator)
add_subdirectory(mainProgram)

add_executable(ImageComparison main.cpp)

target_link_libraries(ImageComparison SimularityGenerator Parser CsvUtils MainProgram ${OpenCV_LIBS})
