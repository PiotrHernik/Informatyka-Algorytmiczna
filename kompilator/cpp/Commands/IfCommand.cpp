#include "IfCommand.hpp"

std::vector<std::string> executeIfCommand(SymbolTable& symbolTable, 
                                        std::vector<std::shared_ptr<Command>>& commands, 
                                        std::vector<std::shared_ptr<Procedure>>& procedures)
{
    std::vector<std::string> asmCommands;
    std::vector<std::string> asmCommandsIF;

    for (auto& command : commands)
    {
        auto tempVec = command->executeCommand(symbolTable, procedures);
        asmCommandsIF.insert(asmCommandsIF.end(), tempVec.begin(), tempVec.end());
    }
    auto amountIfCommands = asmCommandsIF.size();

    auto tempVec2 = makeAsmValue2(symbolTable);
    auto tempVec1 = makeAsmValue1(symbolTable);
    asmCommands.insert(asmCommands.end(), tempVec2.begin(), tempVec2.end());
    asmCommands.insert(asmCommands.end(), tempVec1.begin(), tempVec1.end());

    auto condEnum = condition->condEnum;
    switch (condEnum)
    {
    case ConditionEnum::EQUAL:
        asmCommands.push_back("    SUB 10");
        asmCommands.push_back("    JPOS " + std::to_string(amountIfCommands + 2));
        asmCommands.push_back("    JNEG " + std::to_string(amountIfCommands + 1));
        
        break;
    case ConditionEnum::NOTEQUAL:
        asmCommands.push_back("    SUB 10");
        asmCommands.push_back("    JZERO " + std::to_string(amountIfCommands + 1));
        break;
    case ConditionEnum::MORE:
        asmCommands.push_back("    SUB 10");
        asmCommands.push_back("    JNEG " + std::to_string(amountIfCommands + 2));
        asmCommands.push_back("    JZERO " + std::to_string(amountIfCommands + 1));
        break;
    case ConditionEnum::LESS:
        asmCommands.push_back("    JPOS " + std::to_string(amountIfCommands + 2));
        asmCommands.push_back("    JZERO " + std::to_string(amountIfCommands + 1));
        break;
    case ConditionEnum::MOREOREQUAL:
        asmCommands.push_back("    SUB 10");
        asmCommands.push_back("    JNEG " + std::to_string(amountIfCommands + 1));
        break;
    case ConditionEnum::LESSOREQUAL:
        asmCommands.push_back("    SUB 10");
        asmCommands.push_back("    JPOS " + std::to_string(amountIfCommands + 1));
        break;
    
    default:
        break;
    }

    asmCommands.insert(asmCommands.end(), asmCommandsIF.begin(), asmCommandsIF.end());


    return asmCommands;
}