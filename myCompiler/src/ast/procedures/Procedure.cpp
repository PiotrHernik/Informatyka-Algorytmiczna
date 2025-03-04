#include "Procedure.hpp"

Procedure::Procedure(std::shared_ptr<ProcHead> procHead, std::vector<std::shared_ptr<Command>> commands)
    : procHead_(procHead), commands_(commands), rntrAddress_(SymbolTable::useFirstFreeAddress()), symbolTable_(SymbolTable(procHead->getName())) {}