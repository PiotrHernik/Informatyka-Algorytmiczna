#include "ProcHead.hpp"
#include <iostream>

ProcHead::ProcHead(std::string name, std::vector<std::shared_ptr<ArgsDeclaration>> argsDecl)
    : name(name), argsDecl(argsDecl){}

std::string ProcHead::doAsm() const {
    return std::string("ProcHead");
}
 
void ProcHead::fillSymbolTable(SymbolTable& symbTab){
    for( auto& arg : argsDecl)
    {
        symbTab.addArgs(arg);
    }
}

void ProcHead::setLocation(int lin, int col)
{
    line = lin;
    column = col;
}