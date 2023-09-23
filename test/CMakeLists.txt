if(BUILD_TESTING)
  add_executable(initial_test expr_test.cpp)

  target_link_libraries(
    initial_test
    GTest::gtest_main
  )

  include(GoogleTest)
  gtest_discover_tests(initial_test)

  target_include_directories(${PROJECT_NAME} 
    PUBLIC 
      "${PROJECT_SOURCE_DIR}/external/googletest"
  )
endif()
