file(GLOB SRCS *.cpp)
set(TEST_NAME CommandLineArgsParserTests)
add_executable(${TEST_NAME} ${SRCS})
target_link_libraries(${TEST_NAME} Parser gtest_main)

add_test(
  NAME TestFunction
  COMMAND ${TEST_NAME}
  )

add_test(
  NAME NoThrow
  COMMAND ${TEST_NAME}
  )

  add_test(
  NAME includeFilePath
  COMMAND ${TEST_NAME}
  )

  add_test(
  NAME ExtraArgumentsNoThrow
  COMMAND ${TEST_NAME}
  )