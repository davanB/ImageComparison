file(GLOB SRCS *.cpp)
set(TEST_NAME parserTests)
add_executable(${TEST_NAME} ${SRCS})
#target_include_directories(${TEST_NAME} PUBLIC ${SRCS})
#target_include_directories(${TEST_NAME} PUBLIC Parser)
target_link_libraries(${TEST_NAME} Parser gtest_main)

add_test(
  NAME ${TEST_NAME}
  COMMAND ${TEST_NAME}
  )
