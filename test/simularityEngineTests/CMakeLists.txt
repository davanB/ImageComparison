file(GLOB SRCS *.cpp)
set(TEST_NAME SimularityGeneratorTests)
add_executable(${TEST_NAME} ${SRCS})
include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries(${TEST_NAME} SimularityGenerator CsvUtils gtest_main ${OpenCV_LIBS})

include(GoogleTest)
gtest_discover_tests(SimularityGeneratorTests)

add_custom_command(
    TARGET SimularityGeneratorTests 
    POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy  
                     "${CMAKE_CURRENT_SOURCE_DIR}/../testFiles/images.csv" 
                     "${CMAKE_CURRENT_BINARY_DIR}/images.csv"
)

add_custom_command(
    TARGET SimularityGeneratorTests 
    POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy  
                     "${CMAKE_CURRENT_SOURCE_DIR}/../testFiles/imagesSame.csv" 
                     "${CMAKE_CURRENT_BINARY_DIR}/imagesSame.png"
)

add_custom_command(
    TARGET SimularityGeneratorTests 
    POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy  
                     "${CMAKE_CURRENT_SOURCE_DIR}/../testFiles/image1.png" 
                     "${CMAKE_CURRENT_BINARY_DIR}/image1.png"
)

add_custom_command(
    TARGET SimularityGeneratorTests 
    POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy  
                     "${CMAKE_CURRENT_SOURCE_DIR}/../testFiles/image1.png" 
                     "${CMAKE_CURRENT_BINARY_DIR}/image2.png"
)

add_custom_command(
    TARGET SimularityGeneratorTests 
    POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy  
                     "${CMAKE_CURRENT_SOURCE_DIR}/../testFiles/image1.png" 
                     "${CMAKE_CURRENT_BINARY_DIR}/image3.png"
)

add_custom_command(
    TARGET SimularityGeneratorTests 
    POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy  
                     "${CMAKE_CURRENT_SOURCE_DIR}/../testFiles/image4.png" 
                     "${CMAKE_CURRENT_BINARY_DIR}/image4.png"
)