add_library(Parser
  Expression.cpp
  NumberLiteral.cpp
  BinaryOperation.cpp
  Parser.cpp
)

target_link_libraries(Parser)

target_include_directories(Parser
  PUBLIC "${PROJECT_SOURCE_DIR}/include/Expr/"
)
