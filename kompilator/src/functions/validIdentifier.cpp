#include "validIdentifier.hpp"

#include <iostream>


bool isValidIdentifier(SymbolTable& symbolTable, std::shared_ptr<Identifier> identifier)
{
    auto idEnum = identifier->idEnum;
    if (idEnum == IdentifierEnum::PID)
    {
        if (symbolTable.isIterator(identifier->name1))
        {
            return false;
        }
        
        if (!symbolTable.isDeclared(identifier->name1, DeclarationEnum::PID) 
        && !symbolTable.isArgument(identifier->name1, DeclarationEnum::PID))
        {
            return false;
        }
    }
    else if (idEnum == IdentifierEnum::PIDT)
    {
        if (!symbolTable.isDeclared(identifier->name1, DeclarationEnum::TABLE) 
            && !symbolTable.isArgument(identifier->name1, DeclarationEnum::TABLE))
        {
            return false;
        }
    }
    else
    {
        if (!symbolTable.isDeclared(identifier->name1, DeclarationEnum::TABLE) 
            && !symbolTable.isArgument(identifier->name1, DeclarationEnum::TABLE)
            || !symbolTable.isDeclared(identifier->name2, DeclarationEnum::PID) 
            && !symbolTable.isArgument(identifier->name2, DeclarationEnum::PID)
            && !symbolTable.isIterator(identifier->name2))
        {
            return false;
        }

    }
    return true;
}