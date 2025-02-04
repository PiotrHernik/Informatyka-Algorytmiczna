#pragma once

#include <vector>
#include <string>

#include "../SymbolTable/SymbolTable.hpp"
#include "../ast/Identifier.hpp"
#include "../ast/Value.hpp"
#include "../ast/Enums.hpp"
#include "../ErrorClass/Error.hpp"
#include "validIdentifier.hpp"

std::vector<std::string> makeAsmValue1(SymbolTable& symbolTable, std::shared_ptr<Value> value1, bool isInFor)
{
    std::vector<std::string> asmCommands;
    
    if (value1->valEnum == ValueEnum::NUM) {
        asmCommands.push_back("SET " + std::to_string(value1->value));
        return asmCommands;
    } 

    if (!isValidIdentifier(symbolTable, value1->identifier))
    {
        if (!symbolTable.isIterator(value1->identifier->name1) || value1->identifier->idEnum != IdentifierEnum::PID)
        {
            std::string errMsg = "Undeclared argument" + std::to_string(value1->identifier->line) + ":" + std::to_string(value1->identifier->column);
            Error err(errMsg);
            err.notifyError();
        }
    }

    if (value1->identifier->idEnum == IdentifierEnum::PID) {
        if (!symbolTable.isInitialized(value1->identifier->name1))
        {
            auto errMsg = "Identifier: " + value1->identifier->name1 + " is not initialized " + std::to_string(value1->identifier->line) + ":" + std::to_string(value1->identifier->column);
            Error err(errMsg);
            err.notifyError();
        }
        
        if (symbolTable.isArgument(value1->identifier->name1, DeclarationEnum::PID))
            asmCommands.push_back("LOADI " + 
                              std::to_string(symbolTable.getPidAddress(value1->identifier->name1, isInFor)));
        else
            asmCommands.push_back("LOAD " + 
                              std::to_string(symbolTable.getPidAddress(value1->identifier->name1, isInFor)));
    } 
    else if (value1->identifier->idEnum == IdentifierEnum::PIDT) {
        if (symbolTable.isArgument(value1->identifier->name1, DeclarationEnum::TABLE))
        {
            asmCommands.push_back("SET " + std::to_string(value1->identifier->num));
            asmCommands.push_back("ADD " + std::to_string(symbolTable.getTableAddress(value1->identifier->name1)));
            asmCommands.push_back("LOADI 0");

        }
        else
        {
            asmCommands.push_back("LOAD " + 
                              std::to_string(symbolTable.getTableAddress(value1->identifier->name1, 
                                                                         value1->identifier->num)));
        }
    } 
    else if (value1->identifier->idEnum == IdentifierEnum::PIDTPID) {
        if (!symbolTable.isInitialized(value1->identifier->name2))
        {
            auto errMsg = "Identifier: " + value1->identifier->name2 + " is not initialized " + std::to_string(value1->identifier->line) + ":" + std::to_string(value1->identifier->column);
            Error err(errMsg);
            err.notifyError();
        }

        if (symbolTable.isArgument(value1->identifier->name1, DeclarationEnum::TABLE))
        {
            asmCommands.push_back("LOAD " + std::to_string(symbolTable.getTableAddress(value1->identifier->name1)));
            if (symbolTable.isArgument(value1->identifier->name2, DeclarationEnum::PID))
            {
                asmCommands.push_back("ADDI " + 
                                std::to_string(symbolTable.getPidAddress(value1->identifier->name2, isInFor)));
            }
            else
            {
                asmCommands.push_back("ADD " + 
                                std::to_string(symbolTable.getPidAddress(value1->identifier->name2, isInFor)));
            }
        }
        else
        {
            asmCommands.push_back("SET " + 
                              std::to_string(symbolTable.getTableAddress(value1->identifier->name1)));
            if (symbolTable.isArgument(value1->identifier->name2, DeclarationEnum::PID))
            {
                asmCommands.push_back("ADDI " + 
                                std::to_string(symbolTable.getPidAddress(value1->identifier->name2, isInFor)));
            }
            else
            {
                asmCommands.push_back("ADD " + 
                                std::to_string(symbolTable.getPidAddress(value1->identifier->name2, isInFor)));
            }
        }

        asmCommands.push_back("LOADI 0");

        
    } 

    return asmCommands;
}