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
                     "${CMAKE_CURRENT_BINARY_DIR}/images.csv"
)

add_custom_command(
    TARGET CsvUtilsTests 
    POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy  
                     "${CMAKE_CURRENT_SOURCE_DIR}/../testFiles/imagesWrong.csv" 
                     "${CMAKE_CURRENT_BINARY_DIR}/imagesWrong.csv"
)

add_custom_command(
    TARGET CsvUtilsTests 
    POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy  
                     "${CMAKE_CURRENT_SOURCE_DIR}/../testFiles/image1.png" 
                     "${CMAKE_CURRENT_BINARY_DIR}/image1.png"
)

add_custom_command(
    TARGET CsvUtilsTests 
    POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy  
                     "${CMAKE_CURRENT_SOURCE_DIR}/../testFiles/image2.png" 
                     "${CMAKE_CURRENT_BINARY_DIR}/image2.png"
)

add_custom_command(
    TARGET CsvUtilsTests 
    POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy  
                     "${CMAKE_CURRENT_SOURCE_DIR}/../testFiles/image3.png" 
                     "${CMAKE_CURRENT_BINARY_DIR}/image3.png"
)

add_custom_command(
    TARGET CsvUtilsTests 
    POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy  
                     "${CMAKE_CURRENT_SOURCE_DIR}/../testFiles/image4.png" 
                     "${CMAKE_CURRENT_BINARY_DIR}/image4.png"
)