#include "ProcHead.hpp"

ProcHead::ProcHead(std::string& name, std::vector<std::shared_ptr<ArgDeclaration>> argsDecl, Location& loc)
    : name_(name), argsDecl_(argsDecl), location_(loc) {}
 
// void ProcHead::fillSymbolTable(SymbolTable& symbTab){
//     for( auto& arg : argsDecl)
//     {
//         symbTab.addArgs(arg);
//     }
// }

std::pair<int,int> ProcHead::getLocation() const
{
    return { location_.getLine(), location_.getColumn() };
}

std::string ProcHead::getName() const
{
    return name_;
}