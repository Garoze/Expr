cmake_minimum_required(VERSION 3.26)

project(
  Expr
  VERSION 0.0.1 
  LANGUAGES CXX
  DESCRIPTION "A simple expression evaluator in C++20"  
)

include(CTest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")

add_subdirectory(src)
add_subdirectory(external)

target_include_directories(${PROJECT_NAME}
  PUBLIC include/Expr/
)

option(BUILD_TESTING "Enable the tests" ON)
if(BUILD_TESTING)
  enable_testing()
  add_subdirectory(test)
endif()

option(DEBUG_MESSAGE "Print some Debug information" ON)
if (DEBUG_MESSAGE)
  message("CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
  message("CMAKE_CXX_FLAGS_DEBUG: ${CMAKE_CXX_FLAGS_DEBUG}")
  message("CMAKE_CXX_FLAGS_RELEASE: ${CMAKE_CXX_FLAGS_RELEASE}")
endif()


unset(BUILD_TESTING CACHE)
unset(DEBUG_MESSAGE CACHE)
