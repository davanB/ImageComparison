file(GLOB SRCS *.cpp)
set(TEST_NAME CsvUtilsTests)
add_executable(${TEST_NAME} ${SRCS})
target_link_libraries(${TEST_NAME} CsvUtils gtest_main)

include(GoogleTest)
gtest_discover_tests(CsvUtilsTests)

add_custom_command(
    TARGET CsvUtilsTests 
    POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy  
                     "${CMAKE_CURRENT_SOURCE_DIR}/../testFiles/images.csv" 
                     "$<TARGET_FILE_DIR:CsvUtilsTests>/images.csv"
)

add_custom_command(
    TARGET CsvUtilsTests 
    POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy  
                     "${CMAKE_CURRENT_SOURCE_DIR}/../testFiles/imagesWrong.csv" 
                     "$<TARGET_FILE_DIR:CsvUtilsTests>/imagesWrong.csv"
)