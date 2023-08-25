cmake_minimum_required(VERSION 3.24)

project(
	Expr
	VERSION 0.0.1 
	LANGUAGES CXX
	DESCRIPTION "A simple expression evaluator in C++20"  
)

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
