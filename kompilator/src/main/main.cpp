#include <cstring>
#include <fstream>
#include <iostream>

#include "scanner.hpp"
#include "parser.hpp"
#include "../SymbolTable/SymbolTable.hpp"


int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <input_file> ,output_file" << std::endl;
        return 1;
    }

    const char* input_file = argv[1];
    auto output_file = argv[2];

    // Otwórz plik wejściowy
    std::ifstream inputFile(input_file);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Cannot open file " << input_file << std::endl;
        return 1;
    }

    SymbolTable symbolTable("");
    symbolTable.setOutputFile(output_file);
    

    // Ustaw skaner na plik wejściowy
    yy::Scanner scanner{inputFile, std::cout};
    // scanner.set_debug(debug_flag);

    yy::Parser parser{scanner};
    // parser.set_debug_level(1);
    // parser.set_debug_level(debug_flag);

    return parser();
}