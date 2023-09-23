add_library(Lexer
  Kind.cpp
  Location.cpp
  Value.cpp
  Token.cpp
  Lexer.cpp
)

target_link_libraries(Lexer fmt)

target_include_directories(Lexer
    PUBLIC 
      "${PROJECT_SOURCE_DIR}/include/Expr/"
)
