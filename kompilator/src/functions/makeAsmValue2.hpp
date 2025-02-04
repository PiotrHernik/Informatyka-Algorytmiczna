#pragma once

#include <vector>
#include <string>

#include "../SymbolTable/SymbolTable.hpp"
#include "../ast/Identifier.hpp"
#include "../ast/Value.hpp"
#include "../ast/Enums.hpp"
#include "validIdentifier.hpp"
#include "../ErrorClass/Error.hpp"

std::vector<std::string> makeAsmValue2(SymbolTable& symbolTable, std::shared_ptr<Value> value2, bool isInFor)
{
    std::vector<std::string> asmCommands;

    if (value2->valEnum == ValueEnum::NUM) {
        asmCommands.push_back("SET " + std::to_string(value2->value));
        asmCommands.push_back("STORE 10");
        return asmCommands;
    }

    if (!isValidIdentifier(symbolTable, value2->identifier))
    {
        if (!symbolTable.isIterator(value2->identifier->name1) || value2->identifier->idEnum != IdentifierEnum::PID)
        {
            std::string errMsg = "Undeclared argument" + std::to_string(value2->identifier->line) + ":" + std::to_string(value2->identifier->column);
            Error err(errMsg);
            err.notifyError();
        }
    }

    if (value2->identifier->idEnum == IdentifierEnum::PID) {
        if (!symbolTable.isInitialized(value2->identifier->name1))
        {
            auto errMsg = "Identifier: " + value2->identifier->name1 + " is not initialized " + std::to_string(value2->identifier->line) + ":" + std::to_string(value2->identifier->column);
            Error err(errMsg);
            err.notifyError();
        }

        if (symbolTable.isArgument(value2->identifier->name1, DeclarationEnum::PID))
        {
            asmCommands.push_back("LOADI " + 
                              std::to_string(symbolTable.getPidAddress(value2->identifier->name1, isInFor)));
        }
        else
        {
            asmCommands.push_back("LOAD " + 
                              std::to_string(symbolTable.getPidAddress(value2->identifier->name1, isInFor)));
        }
        
        asmCommands.push_back("STORE 10");
    } 
    else if (value2->identifier->idEnum == IdentifierEnum::PIDT) {
        if (symbolTable.isArgument(value2->identifier->name1, DeclarationEnum::TABLE))
        {
            asmCommands.push_back("SET " + std::to_string(value2->identifier->num));
            asmCommands.push_back("ADD " + std::to_string(symbolTable.getTableAddress(value2->identifier->name1)));
            asmCommands.push_back("LOADI 0");                                                             
        }
        else
        {
            asmCommands.push_back("LOAD " + std::to_string(symbolTable.getTableAddress(value2->identifier->name1, value2->identifier->num)));
        }
        
        asmCommands.push_back("STORE 10");
    } 
    else if (value2->identifier->idEnum == IdentifierEnum::PIDTPID) {
        if (!symbolTable.isInitialized(value2->identifier->name2))
        {
            auto errMsg = "Identifier: " + value2->identifier->name2 + " is not initialized " + std::to_string(value2->identifier->line) + ":" + std::to_string(value2->identifier->column);
            Error err(errMsg);
            err.notifyError();
        }
        if (symbolTable.isArgument(value2->identifier->name1, DeclarationEnum::TABLE))
        {
            asmCommands.push_back("LOAD " + 
                              std::to_string(symbolTable.getTableAddress(value2->identifier->name1)));
        }
        else
        {
            asmCommands.push_back("SET " + 
                              std::to_string(symbolTable.getTableAddress(value2->identifier->name1)));
        }
        if (symbolTable.isArgument(value2->identifier->name2, DeclarationEnum::PID))
        {
            asmCommands.push_back("ADDI " + std::to_string(symbolTable.getPidAddress(value2->identifier->name2, isInFor)));
        }
        else
        {
            asmCommands.push_back("ADD " + std::to_string(symbolTable.getPidAddress(value2->identifier->name2, isInFor)));
        }
        
        asmCommands.push_back("LOADI 0");
        asmCommands.push_back("STORE 10");
        
    } 

    return asmCommands;
}