set(CSV_SOURCES
    CSVParser.h 
    CSVParser.cpp
    CSVWriter.h 
    CSVWriter.cpp
    InputCSVData.h 
    InputCSVData.cpp
    OutputCSVData.h 
    OutputCSVData.cpp
    csv.h 
)

# declare lib
add_library(CsvUtils STATIC 
    ${CSV_SOURCES}
)

target_include_directories(
    CsvUtils PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
    )