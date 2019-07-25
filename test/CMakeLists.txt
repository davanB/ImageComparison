add_executable(
    unit_tests
    CommandLineArgsParser_success.cpp
    CommandLineArgsParser_fail.cpp
    )

target_link_libraries(
    unit_tests
    gtest_main
    Main
    )

add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
  )
