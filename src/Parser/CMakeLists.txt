add_library(Parser
  Node.cpp
  Expression.cpp
  NumberLiteral.cpp
  BinaryExpression.cpp
  Printer.cpp
  Evaluator.cpp
  Parser.cpp
)

target_link_libraries(Parser fmt)

target_include_directories(Parser
  PUBLIC "${PROJECT_SOURCE_DIR}/include/Expr/"
)
