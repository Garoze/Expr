#include <iostream>
#include <string>

#include "Lexer/Lexer.hpp"

int main()
{
    Lexer l;

    std::cout << "Basic expression evaluator\n";

    std::string input;
    for (;;)
    {
        std::cout << "> ";
        std::getline(std::cin, input);
        l.lex_line(input);
        input = "";
    }

    return EXIT_SUCCESS;
}
