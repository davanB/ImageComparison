file(GLOB SRCS *.cpp)
set(TEST_NAME CommandLineArgsParserTests)
add_executable(${TEST_NAME} ${SRCS})
target_link_libraries(${TEST_NAME} Parser gtest_main)

include(GoogleTest)
gtest_discover_tests(CommandLineArgsParserTests)