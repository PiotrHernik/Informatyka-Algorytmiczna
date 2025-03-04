#include "Ast.hpp"
#include <iostream>

void mainProgram(std::vector<std::shared_ptr<Procedure>>& procedures, std::shared_ptr<Program> program){
    std::cout <<"Jest main program" <<std::endl;
    // for(auto& proc : procedures)
    // {
    //     proc->fillSymbolTable();
    // }
    // program->fillSymbolTable();
    // program->executeCommand(procedures);

}
