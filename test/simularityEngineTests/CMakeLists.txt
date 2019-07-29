file(GLOB SRCS *.cpp)
set(TEST_NAME SimularityGeneratorTests)
add_executable(${TEST_NAME} ${SRCS})
target_link_libraries(${TEST_NAME} SimularityGenerator CsvUtils gtest_main)

include(GoogleTest)
gtest_discover_tests(SimularityGeneratorTests)