#include "Ast.hpp"
#include <iostream>

void mainProgram(std::vector<std::shared_ptr<Procedure>>& procedures, std::shared_ptr<Main> program){
    for(auto& proc : procedures)
    {
        proc->fillSymbolTable();
    }
    program->fillSymbolTable();
    program->executeCommand(procedures);

}
