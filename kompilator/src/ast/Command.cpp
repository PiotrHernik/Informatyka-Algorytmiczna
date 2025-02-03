#include <iostream>
#include <climits>

#include "Command.hpp"
#include "../astUtilities/commandsUtilities/CommandIf.hpp"
#include "../astUtilities/commandsUtilities/CommandIfElse.hpp"
#include "../functions/validIdentifier.hpp"
#include "../functions/makeAsmValue1.hpp"
#include "../functions/makeAsmValue2.hpp"
#include "../functions/arithmetics.hpp"
#include "../ErrorClass/Error.hpp"

CommandAssign::CommandAssign(std::shared_ptr<Identifier> id, std::shared_ptr<Expression> expr)
    : identifier(std::move(id)), expression(std::move(expr))
{
    commandEnum = CommandEnum::ASSIGN;
}

std::string CommandAssign::doAsm() const
{
    return std::string("Command Assign");
}


CommandIfElse::CommandIfElse(std::shared_ptr<Condition> cond, std::vector<std::shared_ptr<Command>> com1, std::vector<std::shared_ptr<Command>> com2)
    : commands1(std::move(com1)), commands2(std::move(com2))
{
    condition = cond;
    commandEnum = CommandEnum::IFELSE;
}

std::string CommandIfElse::doAsm() const
{
    return std::string("Command IFELSE");
}

CommandIf::CommandIf(std::shared_ptr<Condition> cond, std::vector<std::shared_ptr<Command>> commands)
    : commands(std::move(commands))
{
    condition = cond;
    commandEnum = CommandEnum::IF;
}

std::string CommandIf::doAsm() const
{
    return std::string("Command IF");
}


CommandWhile::CommandWhile(std::shared_ptr<Condition> cond, std::vector<std::shared_ptr<Command>> commands)
    : commands(std::move(commands))
{
    condition = cond;
    commandEnum = CommandEnum::WHILE;
}

std::string CommandWhile::doAsm() const
{
    return std::string("Command While");
}


CommandRepeat::CommandRepeat(std::vector<std::shared_ptr<Command>> commands, std::shared_ptr<Condition> cond)
    : commands(std::move(commands))
{
    condition = cond;
    commandEnum = CommandEnum::REPEAT;
}

std::string CommandRepeat::doAsm() const
{
    return std::string("Command Repeat");
}


CommandForTo::CommandForTo(std::string pid, std::shared_ptr<Value> val1, std::shared_ptr<Value> val2, std::vector<std::shared_ptr<Command>> commands)
    : pid(pid), value1(std::move(val1)), value2(std::move(val2)), commands(std::move(commands))
{
    commandEnum = CommandEnum::FORTO;
}

std::string CommandForTo::doAsm() const
{
    return std::string("Command ForTo");
}

CommandDownTo::CommandDownTo(std::string pid, std::shared_ptr<Value> val1, std::shared_ptr<Value> val2, std::vector<std::shared_ptr<Command>> commands)
    : pid(pid), value1(std::move(val1)), value2(std::move(val2)), commands(std::move(commands))
{
    commandEnum = CommandEnum::FORDOWNTO;
}


std::string CommandDownTo::doAsm() const
{
    return std::string("Command DownTo");
}

CommandProcCall::CommandProcCall(std::shared_ptr<ProcCall> procCall)
    : procCall(std::move(procCall))
{
    commandEnum = CommandEnum::PROCCALL;
}

std::string CommandProcCall::doAsm() const
{
    return std::string("Command ProcCall");
}

CommandRead::CommandRead(std::shared_ptr<Identifier> id)
    : identifier(std::move(id))
{
    commandEnum = CommandEnum::READ;
}

std::string CommandRead::doAsm() const
{
    return std::string("Command Read");
}


CommandWrite::CommandWrite(std::shared_ptr<Value> val)
    : value(std::move(val))
{
    commandEnum = CommandEnum::WRITE;
}

std::string CommandWrite::doAsm() const
{
    return std::string("Command Write");
}

std::string CommandProcCall::getProcedureName() const 
{
    return procCall->name;
}


std::vector<std::string> CommandAssign::executeCommand(SymbolTable& symbolTable, 
        std::vector<std::shared_ptr<Procedure>>& procedures, 
        std::unordered_map<std::string, std::pair<int, int>> procedureStartEndInAssembly,
        int howManyAsmCommand, 
        bool isInFor)
{
    std::vector<std::string> asmCommands;
    long long destinationAddress = -1;
    auto idEnum = identifier->idEnum;

    if (!isValidIdentifier(symbolTable, identifier))
    {
        if (identifier->idEnum == IdentifierEnum::PID && symbolTable.isIterator(identifier->name1))
        {
            std::string errMsg = "You can not change iterator, at: " + std::to_string(identifier->line) + ":" + std::to_string(identifier->column);
            Error err(errMsg);
            err.notifyError();
        }
        std::string errMsg = "Undeclared argument " + std::to_string(identifier->line) + ":" + std::to_string(identifier->column);
        Error err(errMsg);
        err.notifyError();
    }
    
    if (idEnum == IdentifierEnum::PID)
    {
        destinationAddress = symbolTable.getPidAddress(identifier->name1, isInFor);        
        symbolTable.setAsInitialized(identifier->name1);
    }
    else if (idEnum == IdentifierEnum::PIDT) //tutaj trzeba dodać koda asm żeby ustawiał destination addres w 7
    {
        if (symbolTable.isArgument(identifier->name1, DeclarationEnum::TABLE))
        {
            destinationAddress = -2;
            asmCommands.push_back("    SET " + std::to_string(identifier->num));
            asmCommands.push_back("    ADD " + std::to_string(symbolTable.getTableAddress(identifier->name1)));
            asmCommands.push_back("    STORE 17");
        }
        else
        {
            destinationAddress = symbolTable.getTableAddress(identifier->name1, identifier->num);
        }
    }
    else
    {
        if (symbolTable.isArgument(identifier->name1, DeclarationEnum::TABLE))
        {
            asmCommands.push_back("    LOAD " + std::to_string(symbolTable.getTableAddress(identifier->name1)));
        }
        else
        {
            asmCommands.push_back("    SET " + std::to_string(symbolTable.getTableAddress(identifier->name1)));
        }
        if (symbolTable.isArgument(identifier->name2, DeclarationEnum::PID))
        {
            asmCommands.push_back("    ADDI " + std::to_string(symbolTable.getPidAddress(identifier->name2, isInFor)));
        }
        else
        {
            asmCommands.push_back("    ADD " + std::to_string(symbolTable.getPidAddress(identifier->name2, isInFor)));
        }
        asmCommands.push_back("    STORE 15");
    }
    
    switch (expression->expEnum) {
    case ExpressionEnum::VALUE: {
        auto valueInstructions = makeAsmValue1(symbolTable, expression->value1, isInFor);
        asmCommands.insert(asmCommands.end(), valueInstructions.begin(), valueInstructions.end());
        if (destinationAddress == -1) 
            asmCommands.push_back("    STOREI 15");
        else 
        {
            auto declEnum = convertIdEnToDeclEn(identifier->idEnum);

            if (symbolTable.isArgument(identifier->name1, declEnum))
            {
                if (idEnum == IdentifierEnum::PID)
                {
                    asmCommands.push_back("    STOREI " + std::to_string(destinationAddress));
                }
                else if(idEnum == IdentifierEnum::PIDT)
                {
                    asmCommands.push_back("    STOREI 17");
                }
                
            }
            else
            {
                asmCommands.push_back("    STORE " + std::to_string(destinationAddress));
            }
        }

        break;
    }
    case ExpressionEnum::PLUS: {
        if (expression->value1->valEnum == ValueEnum::NUM && expression->value2->valEnum == ValueEnum::NUM) 
        {
            if (!(((expression->value2->value ^ expression->value1->value) > 0)
            &&  ((expression->value2->value > 0 && expression->value1->value > LLONG_MAX - expression->value2->value)
            ||  (expression->value2->value < 0 && expression->value1->value < LLONG_MIN - expression->value2->value))))
            {
                auto result = expression->value1->value + expression->value2->value;
                asmCommands.push_back("    SET " + std::to_string(result));

                if (destinationAddress == -1) 
                {
                asmCommands.push_back("    STOREI 15");
                }
                else 
                {
                    if (symbolTable.isArgument(identifier->name1, convertIdEnToDeclEn(identifier->idEnum)))
                    {
                        if (idEnum == IdentifierEnum::PID)
                        {
                            asmCommands.push_back("    STOREI " + std::to_string(destinationAddress));
                        }
                        else if(idEnum == IdentifierEnum::PIDT)
                        {
                            asmCommands.push_back("    STOREI 17");
                        }
                    }
                    else
                    {
                        asmCommands.push_back("    STORE " + std::to_string(destinationAddress));
                    }
                }

            break;
            }
        }

        auto value2Instructions = makeAsmValue2(symbolTable, expression->value2, isInFor);
        asmCommands.insert(asmCommands.end(), value2Instructions.begin(), value2Instructions.end());

        auto value1Instructions = makeAsmValue1(symbolTable, expression->value1, isInFor);
        asmCommands.insert(asmCommands.end(), value1Instructions.begin(), value1Instructions.end());

        asmCommands.push_back("    ADD 10");
        if (destinationAddress == -1) 
            asmCommands.push_back("    STOREI 15");
        else 
        {
            if (symbolTable.isArgument(identifier->name1, convertIdEnToDeclEn(identifier->idEnum)))
            {
                if (idEnum == IdentifierEnum::PID)
                {
                    asmCommands.push_back("    STOREI " + std::to_string(destinationAddress));
                }
                else if (idEnum == IdentifierEnum::PIDT)
                {
                    asmCommands.push_back("    STOREI 17");
                }
            }
            else
            {
                asmCommands.push_back("    STORE " + std::to_string(destinationAddress));
            }
        }
        break;
    }
    case ExpressionEnum::MINUS: {
            
        if (expression->value1->valEnum == ValueEnum::NUM && expression->value2->valEnum == ValueEnum::NUM) {
            if (!(((expression->value2->value ^ expression->value1->value) < 0) &&
            ((expression->value2->value > 0 && expression->value1->value < LLONG_MIN + expression->value2->value) ||
            (expression->value2->value < 0 && expression->value1->value > LLONG_MAX + expression->value2->value))))
            {
                auto result = expression->value1->value - expression->value2->value;
                asmCommands.push_back("    SET " + std::to_string(result));
                if (destinationAddress == -1) 
                    asmCommands.push_back("    STOREI 15");
                else 
                {
                    if (symbolTable.isArgument(identifier->name1, convertIdEnToDeclEn(identifier->idEnum)))
                    {
                        if (idEnum == IdentifierEnum::PID)
                        {
                            asmCommands.push_back("    STOREI " + std::to_string(destinationAddress));
                        }
                        else if (idEnum == IdentifierEnum::PIDT)
                        {
                            asmCommands.push_back("    STOREI 17");
                        }
                    }
                    else
                    {
                        asmCommands.push_back("    STORE " + std::to_string(destinationAddress));
                    }
                }
                break;
            }
        }

        auto value2Instructions = makeAsmValue2(symbolTable, expression->value2, isInFor);
        asmCommands.insert(asmCommands.end(), value2Instructions.begin(), value2Instructions.end());

        auto value1Instructions = makeAsmValue1(symbolTable, expression->value1, isInFor);
        asmCommands.insert(asmCommands.end(), value1Instructions.begin(), value1Instructions.end());

        asmCommands.push_back("    SUB 10");
        if (destinationAddress == -1) 
            asmCommands.push_back("    STOREI 15");
        else 
        {
            if (symbolTable.isArgument(identifier->name1, convertIdEnToDeclEn(identifier->idEnum)))
            {
                if (idEnum == IdentifierEnum::PID)
                {
                    asmCommands.push_back("    STOREI " + std::to_string(destinationAddress));
                }
                else if (idEnum == IdentifierEnum::PIDT)
                {
                    asmCommands.push_back("    STOREI 17");
                }
            }
            else
            {
                asmCommands.push_back("    STORE " + std::to_string(destinationAddress));
            }
        }

        break;
    }
    case ExpressionEnum::MULT:
    {
        if (expression->value1->valEnum == ValueEnum::NUM && expression->value2->valEnum == ValueEnum::NUM)
        {
            if (expression->value1->value == 0 || expression->value2->value == 0)
            {
                asmCommands.push_back("    SET 0");
            }
            else if (!std::abs(expression->value1->value) > (LLONG_MAX / std::abs(expression->value2->value)))
            {
                auto result = expression->value1->value * expression->value2->value;
                asmCommands.push_back("    SET " + std::to_string(result));
            }

            if (expression->value1->value == 0 || expression->value2->value == 0 || !std::abs(expression->value1->value) > (LLONG_MAX / std::abs(expression->value2->value)))
            {
                if (destinationAddress == -1) 
                {
                    asmCommands.push_back("    STOREI 15");
                }
                else 
                {
                    if (symbolTable.isArgument(identifier->name1, convertIdEnToDeclEn(identifier->idEnum)))
                    {
                        if (idEnum == IdentifierEnum::PID)
                        {
                            asmCommands.push_back("    STOREI " + std::to_string(destinationAddress));
                        }
                        else if (idEnum == IdentifierEnum::PIDT)
                        {
                            asmCommands.push_back("    STOREI 17");
                        }
                    }
                    else
                    {
                        asmCommands.push_back("    STORE " + std::to_string(destinationAddress));
                    }
                }

                break;
            }
            
        }
        

        auto value2Instructions = makeAsmValue2(symbolTable, expression->value2, isInFor);
        asmCommands.insert(asmCommands.end(), value2Instructions.begin(), value2Instructions.end());

        auto value1Instructions = makeAsmValue1(symbolTable, expression->value1, isInFor);
        asmCommands.insert(asmCommands.end(), value1Instructions.begin(), value1Instructions.end());

        asmCommands.push_back("    STORE 11"); // VALUE1

        asmCommands.push_back("    SET " + std::to_string(howManyAsmCommand + asmCommands.size() + 4));
        asmCommands.push_back("    STORE " + std::to_string(Arithmetics::rtntAddressMultiply));

        auto startMultiply = procedureStartEndInAssembly["multiply"].first;
        long long jumpToMultiply = howManyAsmCommand + asmCommands.size() - startMultiply + 1;

        asmCommands.push_back("    JUMP " + std::to_string(-jumpToMultiply));


        if (destinationAddress == -1) 
            asmCommands.push_back("    STOREI 15");
        else 
        {
            if (symbolTable.isArgument(identifier->name1, convertIdEnToDeclEn(identifier->idEnum)))
            {
                if (idEnum == IdentifierEnum::PID)
                {
                    asmCommands.push_back("    STOREI " + std::to_string(destinationAddress));
                }
                else if (idEnum == IdentifierEnum::PIDT)
                {
                    asmCommands.push_back("    STOREI 17");
                }
            }
            else
            {
                asmCommands.push_back("    STORE " + std::to_string(destinationAddress));
            }
        }
        break;
    }
    case ExpressionEnum::DIV:
    {

        asmCommands.push_back("    SET 1");
        asmCommands.push_back("    STORE 21");
        auto value2Instructions = makeAsmValue2(symbolTable, expression->value2, isInFor);
        asmCommands.insert(asmCommands.end(), value2Instructions.begin(), value2Instructions.end());

        auto value1Instructions = makeAsmValue1(symbolTable, expression->value1, isInFor);
        asmCommands.insert(asmCommands.end(), value1Instructions.begin(), value1Instructions.end());

        asmCommands.push_back("    STORE 11");

        asmCommands.push_back("    SET " + std::to_string(howManyAsmCommand + asmCommands.size() + 4));
        asmCommands.push_back("    STORE " + std::to_string(Arithmetics::rtntAddressDivide));

        auto startDivide = procedureStartEndInAssembly["divide"].first;
        long long jumpToDivide = howManyAsmCommand + asmCommands.size() - startDivide + 1;

        asmCommands.push_back("    JUMP " + std::to_string(-jumpToDivide));

        if (destinationAddress == -1) 
        {
            asmCommands.push_back("    LOAD 4");
            asmCommands.push_back("    STOREI 15");
        }
        else 
        {
            if (symbolTable.isArgument(identifier->name1, convertIdEnToDeclEn(identifier->idEnum)))
            {
                if (idEnum == IdentifierEnum::PID)
                {
                    asmCommands.push_back("    LOAD 4");
                    asmCommands.push_back("    STOREI " + std::to_string(destinationAddress));
                }
                else if (idEnum == IdentifierEnum::PIDT)
                {
                    asmCommands.push_back("    LOAD 4");
                    asmCommands.push_back("    STOREI 17");
                }
            }
            else
            {
                asmCommands.push_back("    LOAD 4");
                asmCommands.push_back("    STORE " + std::to_string(destinationAddress));
            }
        }

        break;
    }
    case ExpressionEnum::MOD:
    {
        asmCommands.push_back("    SET 1");
        asmCommands.push_back("    STORE 21");
        auto value2Instructions = makeAsmValue2(symbolTable, expression->value2, isInFor);
        asmCommands.insert(asmCommands.end(), value2Instructions.begin(), value2Instructions.end());

        auto value1Instructions = makeAsmValue1(symbolTable, expression->value1, isInFor);
        asmCommands.insert(asmCommands.end(), value1Instructions.begin(), value1Instructions.end());

        asmCommands.push_back("    STORE 11");

        asmCommands.push_back("    SET " + std::to_string(howManyAsmCommand + asmCommands.size() + 4));
        asmCommands.push_back("    STORE " + std::to_string(Arithmetics::rtntAddressDivide));

        auto startDivide = procedureStartEndInAssembly["divide"].first;
        long long jumpToDivide = howManyAsmCommand + asmCommands.size() - startDivide + 1;

        asmCommands.push_back("    JUMP " + std::to_string(-jumpToDivide));


        if (destinationAddress == -1) 
        {
            asmCommands.push_back("    LOAD 3");
            asmCommands.push_back("    STOREI 15");
        }
        else 
        {
            if (symbolTable.isArgument(identifier->name1, convertIdEnToDeclEn(identifier->idEnum)))
            {
                if (idEnum == IdentifierEnum::PID)
                {
                    asmCommands.push_back("    LOAD 3");
                    asmCommands.push_back("    STOREI " + std::to_string(destinationAddress));
                }
                else if (idEnum == IdentifierEnum::PIDT)
                {
                    asmCommands.push_back("    LOAD 3");
                    asmCommands.push_back("    STOREI 17");
                }
            }
            else
            {
                asmCommands.push_back("    LOAD 3");
                asmCommands.push_back("    STORE " + std::to_string(destinationAddress));
            }
        }

        break;
    }
    default:
        std::string errMsg = "Type of expression isn't supported";
        Error err(errMsg);
        err.notifyError();
        break;
    }
    return asmCommands;
}

std::vector<std::string> CommandIf::executeCommand(SymbolTable& symbolTable, 
        std::vector<std::shared_ptr<Procedure>>& procedures,
        std::unordered_map<std::string, std::pair<int, int>> procedureStartEndInAssembly,
        int howManyAsmCommand,  
        bool isInFor)
{
    std::vector<std::string> asmCommands;
    std::vector<std::string> asmCommandsIF;

    auto tempVec2 = makeAsmValue2(symbolTable, condition->value2, isInFor);
    auto tempVec1 = makeAsmValue1(symbolTable, condition->value1, isInFor);
    asmCommands.insert(asmCommands.end(), tempVec2.begin(), tempVec2.end());
    asmCommands.insert(asmCommands.end(), tempVec1.begin(), tempVec1.end());

    auto condEnum = condition->condEnum;
    int asmCommandCounter = asmCommands.size();
    switch (condEnum)
    {
    case ConditionEnum::EQUAL:
        asmCommandCounter += 3;
        break;
    case ConditionEnum::NOTEQUAL:
        asmCommandCounter += 2;
        break;
    case ConditionEnum::MORE:
        asmCommandCounter += 3;
        break;
    case ConditionEnum::LESS:
        asmCommandCounter += 3;
        break;
    case ConditionEnum::MOREOREQUAL:
        asmCommandCounter += 2;
        break;
    case ConditionEnum::LESSOREQUAL:
        asmCommandCounter += 2;
        break;
    default:
        break;
    }

    for (auto& command : commands)
    {
        auto tempVec = command->executeCommand(symbolTable, procedures, procedureStartEndInAssembly, howManyAsmCommand + asmCommandCounter + asmCommandsIF.size(), isInFor);
        asmCommandsIF.insert(asmCommandsIF.end(), tempVec.begin(), tempVec.end());
    }
    auto amountIfCommands = asmCommandsIF.size();


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
        asmCommands.push_back("    SUB 10");
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

std::vector<std::string> CommandIfElse::executeCommand(SymbolTable& symbolTable, 
        std::vector<std::shared_ptr<Procedure>>& procedures, 
        std::unordered_map<std::string, std::pair<int, int>> procedureStartEndInAssembly,
        int howManyAsmCommand, 
        bool isInFor)
{
    std::vector<std::string> asmCommands;
    std::vector<std::string> asmCommandsIF;
    std::vector<std::string> asmCommandsElse;

    auto tempVec2 = makeAsmValue2(symbolTable, condition->value2, isInFor);
    auto tempVec1 = makeAsmValue1(symbolTable, condition->value1, isInFor);
    asmCommands.insert(asmCommands.end(), tempVec2.begin(), tempVec2.end());
    asmCommands.insert(asmCommands.end(), tempVec1.begin(), tempVec1.end());

    auto condEnum = condition->condEnum;
    int asmCommandCounter = asmCommands.size();
    switch (condEnum)
    {
    case ConditionEnum::EQUAL:
        asmCommandCounter += 3;
        break;
    case ConditionEnum::NOTEQUAL:
        asmCommandCounter += 2;
        break;
    case ConditionEnum::MORE:
        asmCommandCounter += 3;
        break;
    case ConditionEnum::LESS:
        asmCommandCounter += 3;
        break;
    case ConditionEnum::MOREOREQUAL:
        asmCommandCounter += 2;
        break;
    case ConditionEnum::LESSOREQUAL:
        asmCommandCounter += 2;
        break;
    default:
        break;
    }

    for (auto& command : commands1)
    {
        auto tempVec = command->executeCommand(symbolTable, procedures, procedureStartEndInAssembly, howManyAsmCommand + asmCommandCounter + asmCommandsIF.size(), isInFor);
        asmCommandsIF.insert(asmCommandsIF.end(), tempVec.begin(), tempVec.end());
    }

    for (auto& command : commands2)
    {
        auto tempVec = command->executeCommand(symbolTable, procedures, procedureStartEndInAssembly, howManyAsmCommand + asmCommandCounter + asmCommandsIF.size() + 1 + asmCommandsElse.size(), isInFor);
        asmCommandsElse.insert(asmCommandsElse.end(), tempVec.begin(), tempVec.end());
    }
    auto amountElseCommands = asmCommandsElse.size();

    asmCommandsIF.push_back("    JUMP " + std::to_string(amountElseCommands + 1));
    auto amountIfCommands = asmCommandsIF.size();

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
        asmCommands.push_back("    SUB 10");
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
    asmCommands.insert(asmCommands.end(), asmCommandsElse.begin(), asmCommandsElse.end());


    return asmCommands;
}
std::vector<std::string> CommandWhile::executeCommand(SymbolTable& symbolTable, 
        std::vector<std::shared_ptr<Procedure>>& procedures, 
        std::unordered_map<std::string, std::pair<int, int>> procedureStartEndInAssembly,
        int howManyAsmCommand, 
        bool isInFor)
{
    std::vector<std::string> asmCommands;
    std::vector<std::string> asmCommandsWhile;

    auto tempVec2 = makeAsmValue2(symbolTable, condition->value2, isInFor);
    auto tempVec1 = makeAsmValue1(symbolTable, condition->value1, isInFor);
    asmCommands.insert(asmCommands.end(), tempVec2.begin(), tempVec2.end());
    asmCommands.insert(asmCommands.end(), tempVec1.begin(), tempVec1.end());

    auto condEnum = condition->condEnum;
    int asmCommandCounter = asmCommands.size();
    switch (condEnum)
    {
    case ConditionEnum::EQUAL:
        asmCommandCounter += 3;
        break;
    case ConditionEnum::NOTEQUAL:
        asmCommandCounter += 2;
        break;
    case ConditionEnum::MORE:
        asmCommandCounter += 3;
        break;
    case ConditionEnum::LESS:
        asmCommandCounter += 3;
        break;
    case ConditionEnum::MOREOREQUAL:
        asmCommandCounter += 2;
        break;
    case ConditionEnum::LESSOREQUAL:
        asmCommandCounter += 2;
        break;
    default:
        break;
    }

    for (auto& command : commands)
    {
        auto tempVec = command->executeCommand(symbolTable, procedures, procedureStartEndInAssembly, howManyAsmCommand + asmCommandCounter + asmCommandsWhile.size(), isInFor);
        asmCommandsWhile.insert(asmCommandsWhile.end(), tempVec.begin(), tempVec.end());
    }
    auto amountWhileCommands = asmCommandsWhile.size() + 1; //plus jump to condition

    switch (condEnum)
    {
    case ConditionEnum::EQUAL:
        asmCommands.push_back("    SUB 10");
        asmCommands.push_back("    JPOS " + std::to_string(amountWhileCommands + 2));
        asmCommands.push_back("    JNEG " + std::to_string(amountWhileCommands + 1));
        
        break;
    case ConditionEnum::NOTEQUAL:
        asmCommands.push_back("    SUB 10");
        asmCommands.push_back("    JZERO " + std::to_string(amountWhileCommands + 1));
        break;
    case ConditionEnum::MORE:
        asmCommands.push_back("    SUB 10");
        asmCommands.push_back("    JNEG " + std::to_string(amountWhileCommands + 2));
        asmCommands.push_back("    JZERO " + std::to_string(amountWhileCommands + 1));
        break;
    case ConditionEnum::LESS:
        asmCommands.push_back("    SUB 10");
        asmCommands.push_back("    JPOS " + std::to_string(amountWhileCommands + 2));
        asmCommands.push_back("    JZERO " + std::to_string(amountWhileCommands + 1));
        break;
    case ConditionEnum::MOREOREQUAL:
        asmCommands.push_back("    SUB 10");
        asmCommands.push_back("    JNEG " + std::to_string(amountWhileCommands + 1));
        break;
    case ConditionEnum::LESSOREQUAL:
        asmCommands.push_back("    SUB 10");
        asmCommands.push_back("    JPOS " + std::to_string(amountWhileCommands + 1));
        break;
    
    default:
        break;
    }
    long long jumpToCondition = asmCommands.size() + amountWhileCommands - 1;
    asmCommandsWhile.push_back("    JUMP " + std::to_string(-jumpToCondition)); //można dokonać optymalizacji analizując w które miejsce w condition skoczyć. (2 mniej instrukcje conajmniej);

    asmCommands.insert(asmCommands.end(), asmCommandsWhile.begin(), asmCommandsWhile.end());

    return asmCommands;


}
std::vector<std::string> CommandRepeat::executeCommand(SymbolTable& symbolTable, 
        std::vector<std::shared_ptr<Procedure>>& procedures, 
        std::unordered_map<std::string, std::pair<int, int>> procedureStartEndInAssembly,
        int howManyAsmCommand, 
        bool isInFor)
{
    std::vector<std::string> asmCommands;

    for (auto& command : commands)
    {
        auto tempVec = command->executeCommand(symbolTable, procedures, procedureStartEndInAssembly, howManyAsmCommand + asmCommands.size(), isInFor);
        asmCommands.insert(asmCommands.end(), tempVec.begin(), tempVec.end());
    }

    auto tempVec2 = makeAsmValue2(symbolTable, condition->value2, isInFor);
    auto tempVec1 = makeAsmValue1(symbolTable, condition->value1, isInFor);
    asmCommands.insert(asmCommands.end(), tempVec2.begin(), tempVec2.end());
    asmCommands.insert(asmCommands.end(), tempVec1.begin(), tempVec1.end());

    asmCommands.push_back("    SUB 10");
    long long jumpBackAddress = asmCommands.size();

    auto condEnum = condition->condEnum;

    switch (condEnum)
    {
    case ConditionEnum::EQUAL:
        asmCommands.push_back("    JPOS " + std::to_string(-jumpBackAddress));
        asmCommands.push_back("    JNEG " + std::to_string(-(jumpBackAddress + 1)));
        
        break;
    case ConditionEnum::NOTEQUAL:
        asmCommands.push_back("    JZERO " + std::to_string(-jumpBackAddress));
        break;
    case ConditionEnum::MORE:
        asmCommands.push_back("    JNEG " + std::to_string(-jumpBackAddress));
        asmCommands.push_back("    JZERO " + std::to_string(-(jumpBackAddress + 1)));
        break;
    case ConditionEnum::LESS:
        asmCommands.push_back("    JPOS " + std::to_string(-jumpBackAddress));
        asmCommands.push_back("    JZERO " + std::to_string(-(jumpBackAddress + 1)));
        break;
    case ConditionEnum::MOREOREQUAL:
        asmCommands.push_back("    JNEG " + std::to_string(-jumpBackAddress));
        break;
    case ConditionEnum::LESSOREQUAL:
        asmCommands.push_back("    JPOS " + std::to_string(-jumpBackAddress));
        break;
    
    default:
        break;
    }

    return asmCommands;

}
std::vector<std::string> CommandForTo::executeCommand(SymbolTable& symbolTable, 
        std::vector<std::shared_ptr<Procedure>>& procedures, 
        std::unordered_map<std::string, std::pair<int, int>> procedureStartEndInAssembly,
        int howManyAsmCommand, 
        bool isInFor)
{
    std::vector<std::string> asmCommand;
    std::vector<std::string> asmCommandsFor;

    //Jesli warunek jest nie spełniony
    if (value1->valEnum == ValueEnum::NUM && value2->valEnum == ValueEnum::NUM
        && value1->value > value2->value)
    {
        return asmCommand;
    }
    
    auto [itAddress, toAddress] = symbolTable.addIterator(pid);

    auto tempVec1 = makeAsmValue1(symbolTable, value1, true);
    auto tempVec2 = makeAsmValue2(symbolTable, value2, true);

    asmCommand.insert(asmCommand.end(), tempVec1.begin(), tempVec1.end());
    asmCommand.push_back("    STORE " + std::to_string(itAddress));

    asmCommand.insert(asmCommand.end(), tempVec2.begin(), tempVec2.end());
    asmCommand.push_back("    STORE " + std::to_string(toAddress));

    asmCommand.push_back("    SET 1");
    asmCommand.push_back("    STORE 21"); //zapisanie wartości 1 do łatwiejszej iteracji

    
    for (auto& command : commands)
    {
        auto tempVec = command->executeCommand(symbolTable, procedures, procedureStartEndInAssembly, howManyAsmCommand + asmCommand.size() + asmCommandsFor.size() + 3, true); // +3 because LOAD, SUB and JPOS will be before commands in for
        asmCommandsFor.insert(asmCommandsFor.end(), tempVec.begin(), tempVec.end()); 
    }
    asmCommandsFor.push_back("    LOAD " + std::to_string(itAddress));
    asmCommandsFor.push_back("    ADD 21");
    asmCommandsFor.push_back("    STORE " + std::to_string(itAddress));


    long long amountForCommands = asmCommandsFor.size();
    asmCommandsFor.push_back("    JUMP " + std::to_string(-(amountForCommands + 2))); //powrót do sprawdzenia "warunku" SUB, JNEG (w akumulatorze został wynik z dodanie 1 do iteratora)
    amountForCommands++;

    asmCommand.push_back("    LOAD " + std::to_string(itAddress));
    asmCommand.push_back("    SUB " + std::to_string(toAddress));
    asmCommand.push_back("    JPOS " + std::to_string(amountForCommands + 1));

    asmCommand.insert(asmCommand.end(), asmCommandsFor.begin(), asmCommandsFor.end());

    symbolTable.delateIterator(pid);

    return asmCommand;
}
std::vector<std::string> CommandDownTo::executeCommand(SymbolTable& symbolTable, 
        std::vector<std::shared_ptr<Procedure>>& procedures, 
        std::unordered_map<std::string, std::pair<int, int>> procedureStartEndInAssembly,
        int howManyAsmCommand, 
        bool isInFor)
{
    std::vector<std::string> asmCommand;
    std::vector<std::string> asmCommandsFor;

    //Jesli warunek jest nie spełniony
    if (value1->valEnum == ValueEnum::NUM && value2->valEnum == ValueEnum::NUM
        && value1->value < value2->value)
    {
        return asmCommand;
    }
    
    auto [itAddress, toAddress] = symbolTable.addIterator(pid);

    auto tempVec1 = makeAsmValue1(symbolTable, value1, true);
    auto tempVec2 = makeAsmValue2(symbolTable, value2, true);

    asmCommand.insert(asmCommand.end(), tempVec1.begin(), tempVec1.end());
    asmCommand.push_back("    STORE " + std::to_string(itAddress) + "#po ustawieniu make value");

    asmCommand.insert(asmCommand.end(), tempVec2.begin(), tempVec2.end());
    asmCommand.push_back("    STORE " + std::to_string(toAddress));

    asmCommand.push_back("    SET 1");
    asmCommand.push_back("    STORE 21"); //zapisanie wartości 1 do łatwiejszej iteracji

    
    for (auto& command : commands)
    {
        auto tempVec = command->executeCommand(symbolTable, procedures, procedureStartEndInAssembly, howManyAsmCommand + asmCommand.size() + asmCommandsFor.size() + 3, true); //+3 like in ForTo
        asmCommandsFor.insert(asmCommandsFor.end(), tempVec.begin(), tempVec.end());
    }
    asmCommandsFor.push_back("    LOAD " + std::to_string(itAddress));
    asmCommandsFor.push_back("    SUB 21");
    asmCommandsFor.push_back("    STORE " + std::to_string(itAddress));


    long long amountForCommands = asmCommandsFor.size();
    asmCommandsFor.push_back("    JUMP " + std::to_string(-(amountForCommands + 2)) + "# skok do sprawdzenia warunku"); //powrót do sprawdzenia "warunku" SUB, JNEG (w akumulatorze został wynik z dodanie 1 do iteratora)
    amountForCommands++;

    asmCommand.push_back("    LOAD " + std::to_string(itAddress));
    asmCommand.push_back("    SUB " + std::to_string(toAddress));
    asmCommand.push_back("    JNEG " + std::to_string(amountForCommands + 1) + "#koniec downTO");

    asmCommand.insert(asmCommand.end(), asmCommandsFor.begin(), asmCommandsFor.end());

    symbolTable.delateIterator(pid);

    return asmCommand;
}



std::vector<std::string> CommandProcCall::executeCommand(SymbolTable& symbolTable, 
        std::vector<std::shared_ptr<Procedure>>& procedures, 
        std::unordered_map<std::string, std::pair<int, int>> procedureStartEndInAssembly,
        int howManyAsmCommand, 
        bool isInFor)
{
    int procCallAsmCommandSize = 3 + 2 * procCall->args.size();
    symbolTable.increasNumProcCall();
    std::vector<std::string> asmCommand;

    //validation of the call
    if (!isValidDeclared(symbolTable, procedures, procCall->name))
    {
        std::string errMsg = "Procedure is not declared or declared in bad place, " + std::to_string(procCall->line) + ":" + std::to_string(procCall->column);
        Error err(errMsg);
        err.notifyError();
    }
    if (!areArgsValid(symbolTable, procedures, procCall->name, procCall->args))
    {
        std::string errMsg = "Number or type of arguments are not valid or some argument does not exist or it is an iterator, " + std::to_string(procCall->line) + ":" + std::to_string(procCall->column);
        Error err(errMsg);
        err.notifyError();
    }
    std::shared_ptr<Procedure> procedure;

    for (auto i = 0; i < procedures.size(); i++)
    {
        if (procedures[i]->procHead->name == procCall->name)
        {
            procedure = procedures[i];
        }
    }
    procedure->fillArgsAddress(symbolTable, procCall);
    auto startProcedure = procedureStartEndInAssembly[procCall->name].first;
    long long jumpToProc = howManyAsmCommand + procCallAsmCommandSize - startProcedure;

    asmCommand.push_back("    SET " + std::to_string(howManyAsmCommand + procCallAsmCommandSize + 1));
    asmCommand.push_back("    STORE " + std::to_string(procedure->rntrAddress));
    for(auto i = 0; i < procCall->args.size(); i++)
    {
        auto argsEnum = procedure->procHead->argsDecl[i]->argsDecEnum;
        if (argsEnum == ArgsDeclarationEnum::PID)
        {
            symbolTable.setAsInitialized(procCall->args[i]->name);
            if (symbolTable.isArgument(procCall->args[i]->name, DeclarationEnum::PID))
            {
                asmCommand.push_back("    LOAD " + std::to_string(symbolTable.getPidAddress(procCall->args[i]->name)));
            }
            else
            {
                asmCommand.push_back("    SET " + std::to_string(symbolTable.getPidAddress(procCall->args[i]->name)));
            }
            asmCommand.push_back("    STORE " + std::to_string(procedure->symbolTable.getPidAddress(procedure->procHead->argsDecl[i]->name)));
        }
        else
        {
            if (symbolTable.isArgument(procCall->args[i]->name, DeclarationEnum::TABLE))
            {
                asmCommand.push_back("    LOAD " + std::to_string(symbolTable.getTableAddress(procCall->args[i]->name)));
            }
            else
            {
                asmCommand.push_back("    SET " + std::to_string(symbolTable.getTableAddress(procCall->args[i]->name)));
            }
            asmCommand.push_back("    STORE " + std::to_string(procedure->symbolTable.getTableAddress(procedure->procHead->argsDecl[i]->name)));
        }
    }

    asmCommand.push_back("    JUMP " + std::to_string(-jumpToProc));

    return asmCommand;
}



std::vector<std::string> CommandRead::executeCommand(SymbolTable& symbolTable, 
        std::vector<std::shared_ptr<Procedure>>& procedures, 
        std::unordered_map<std::string, std::pair<int, int>> procedureStartEndInAssembly,
        int howManyAsmCommand, 
        bool isInFor) 
{
    std::vector<std::string> asmCommands;
    auto idName = identifier->name1;
    bool isDeclared;
    auto idEnum = identifier->idEnum;


    if(!isValidIdentifier(symbolTable, identifier))
    {
        if (!symbolTable.isIterator(identifier->name1) || identifier->idEnum != IdentifierEnum::PID)
        {
            std::string errMsg = "Undeclared argument, " + std::to_string(identifier->line) + ":" + std::to_string(identifier->column);
            Error err(errMsg);
            err.notifyError();
        }
        std::string errMsg = "You can't change an iterator, " + std::to_string(identifier->line) + ":" + std::to_string(identifier->column);
        Error err(errMsg);
        err.notifyError();
    }

    if (identifier->idEnum == IdentifierEnum::PID) 
    {
        symbolTable.setAsInitialized(identifier->name1);
        if (symbolTable.isArgument(idName, DeclarationEnum::PID))
        {
            asmCommands.push_back("    GET 0");
            asmCommands.push_back("    STOREI " + std::to_string(symbolTable.getPidAddress(idName)));
        }
        else
        {
            asmCommands.push_back("    GET " + std::to_string(symbolTable.getPidAddress(idName, isInFor)));
        }
    } 
    else if (identifier->idEnum == IdentifierEnum::PIDT) 
    {
        if (symbolTable.isArgument(idName, DeclarationEnum::TABLE))
        {
            asmCommands.push_back("    SET " + std::to_string(identifier->num));
            asmCommands.push_back("    ADD " + std::to_string(symbolTable.getTableAddress(identifier->name1)));
            asmCommands.push_back("    STORE 2");
            asmCommands.push_back("    GET 0");
            asmCommands.push_back("    STOREI 2");
        }
        else
        {
            asmCommands.push_back("    GET " + 
                                std::to_string(symbolTable.getTableAddress(identifier->name1, identifier->num)));
        }
        
    } 
    else if (identifier->idEnum == IdentifierEnum::PIDTPID) 
    {
        if (!symbolTable.isInitialized(identifier->name2))
        {
            auto errMsg = "Value: " + identifier->name2 + " is not initialized " + std::to_string(identifier->line) + ":" + std::to_string(identifier->column);
            Error err(errMsg);
            err.notifyError();
        }
        if (symbolTable.isArgument(identifier->name1, DeclarationEnum::TABLE))
        {
            asmCommands.push_back("    LOAD " + std::to_string(symbolTable.getTableAddress(identifier->name1, isInFor)));
        }
        else
        {
            asmCommands.push_back("    SET " + std::to_string(symbolTable.getTableAddress(identifier->name1, isInFor)));
        }
        if (symbolTable.isArgument(identifier->name2, DeclarationEnum::PID))
        {
            asmCommands.push_back("    ADDI " + std::to_string(symbolTable.getPidAddress(identifier->name2, isInFor)));
        }
        else
        {
            asmCommands.push_back("    ADD " + std::to_string(symbolTable.getPidAddress(identifier->name2, isInFor)));
        }
        
        asmCommands.push_back("    STORE 1");
        asmCommands.push_back("    GET 0");
        asmCommands.push_back("    STOREI 1");
    } else {
        std::string errMsg = "Bad Identifier Enum";
        Error err(errMsg);
        err.notifyError();
    }

    return asmCommands;
}


std::vector<std::string> CommandWrite::executeCommand(SymbolTable& symbolTable,
        std::vector<std::shared_ptr<Procedure>>& procedures,
        std::unordered_map<std::string, std::pair<int, int>> procedureStartEndInAssembly,
        int howManyAsmCommand,
        bool isInFor) 
{
    std::vector<std::string> asmCommands;
    if (value->valEnum == ValueEnum::NUM) {
        asmCommands.push_back("    SET " + std::to_string(value->value));
        asmCommands.push_back("    PUT 0");
        return asmCommands;
    }

    if(!isValidIdentifier(symbolTable, value->identifier))
    {
        if (!symbolTable.isIterator(value->identifier->name1) || value->identifier->idEnum != IdentifierEnum::PID)
        {
            std::string errMsg = "Undeclared argument, " + std::to_string(value->identifier->line) + ":" + std::to_string(value->identifier->column);
            Error err(errMsg);
            err.notifyError();
        }
    }

    if (value->identifier->idEnum == IdentifierEnum::PID) {
        if (!symbolTable.isInitialized(value->identifier->name1))
        {
            auto errMsg = "Value: " + value->identifier->name1 + " is not initialized " + std::to_string(value->identifier->line) + ":" + std::to_string(value->identifier->column);
            Error err(errMsg);
            err.notifyError();
        }

        if(symbolTable.isArgument(value->identifier->name1, DeclarationEnum::PID))
        {
            asmCommands.push_back("    LOADI " + std::to_string(symbolTable.getPidAddress(value->identifier->name1)));
            asmCommands.push_back("    PUT 0");
        }
        else
        {
            asmCommands.push_back("    PUT " + std::to_string(symbolTable.getPidAddress(value->identifier->name1, isInFor)));
        }
    } 
    else if (value->identifier->idEnum == IdentifierEnum::PIDT) {
        if (symbolTable.isArgument(value->identifier->name1, DeclarationEnum::TABLE))
        {
            asmCommands.push_back("    SET " + std::to_string(value->identifier->num));
            asmCommands.push_back("    ADD " + std::to_string(symbolTable.getTableAddress(value->identifier->name1)));
            asmCommands.push_back("    LOADI 0");
            asmCommands.push_back("    PUT 0");
        }
        else
        {
            asmCommands.push_back("    PUT " +
                              std::to_string(symbolTable.getTableAddress(value->identifier->name1, value->identifier->num)));
        }        
    } 
    else if (value->identifier->idEnum == IdentifierEnum::PIDTPID) {
        if (!symbolTable.isInitialized(value->identifier->name2))
        {
            auto errMsg = "Value: " + value->identifier->name2 + " is not initialized " + std::to_string(value->identifier->line) + ":" + std::to_string(value->identifier->column);
            Error err(errMsg);
            err.notifyError();
        }
        if (symbolTable.isArgument(value->identifier->name1, DeclarationEnum::TABLE))
        {
            asmCommands.push_back("    LOAD " + std::to_string(symbolTable.getTableAddress(value->identifier->name1)));
        }
        else
        {
            asmCommands.push_back("    SET " + std::to_string(symbolTable.getTableAddress(value->identifier->name1)));
        }
        if (symbolTable.isArgument(value->identifier->name2, DeclarationEnum::PID))
        {
            asmCommands.push_back("    ADDI " + std::to_string(symbolTable.getPidAddress(value->identifier->name2)));
        }
        else
        {
            asmCommands.push_back("    ADD " + std::to_string(symbolTable.getPidAddress(value->identifier->name2, isInFor)));
        }
        
        asmCommands.push_back("    LOADI 0");
        asmCommands.push_back("    PUT 0");
    } else {
        std::string errMsg = "Invalid Identifier Enum";
        Error err(errMsg);
        err.notifyError();
    }

    return asmCommands;
}


bool CommandProcCall::isValidDeclared(SymbolTable& symbolTable, std::vector<std::shared_ptr<Procedure>>& procedures, std::string procCallName)
{
    bool result = false;
    //is declared before procedure in which is call?
    auto currentProcedure = symbolTable.getMembership();
    int currentProceduePlace = 0;
    int calledProcedurePlace = 0;
    


    if (currentProcedure == "Main")
    {
        for (auto i = 0; i < procedures.size(); i++)
        {
            if (procedures[i]->procHead->name == procCallName)
            {
                return true;
            }
        }
    }
    else 
    {
        for (auto i = 0; i < procedures.size(); i++)
        {
            if (procedures[i]->procHead->name == currentProcedure)
                currentProceduePlace = i;
        }

        for (auto i = 0; i < procedures.size(); i++)
        {
            if (procedures[i]->procHead->name == procCallName)
                calledProcedurePlace = i;
        }

        if (currentProceduePlace > calledProcedurePlace)
        {
            return true;
        }
        
    }     
    return false;  
}

bool CommandProcCall::areArgsValid(SymbolTable& symbolTable, std::vector<std::shared_ptr<Procedure>>& procedures, std::string procCallName, std::vector<std::shared_ptr<Args>> args)
{
    std::shared_ptr<ProcHead> procHead;
    for (auto i = 0; i < procedures.size(); i++)
    {
        if (procedures[i]->procHead->name == procCallName)
        {
            procHead = procedures[i]->procHead;
        }        
    }
    
    if (procHead->argsDecl.size() != args.size())
    {
        return false;
    }
    
    for (auto i = 0; i < args.size(); i++)
    {
        auto argsEnum = procHead->argsDecl[i]->argsDecEnum;
        if (argsEnum == ArgsDeclarationEnum::PID)
        {
            if (!symbolTable.isDeclared(args[i]->name, DeclarationEnum::PID)
            && ! symbolTable.isArgument(args[i]->name, DeclarationEnum::PID))
                return false;
        }
        else if (argsEnum == ArgsDeclarationEnum::TABLE)
        {
            if (!symbolTable.isDeclared(args[i]->name, DeclarationEnum::TABLE)
            && ! symbolTable.isArgument(args[i]->name, DeclarationEnum::TABLE))
                return false;
        }
    }
    return true;
}

DeclarationEnum Command::convertIdEnToDeclEn(IdentifierEnum& idEnum)
{
    DeclarationEnum declEnum;
    if (idEnum == IdentifierEnum::PID)
    {
        declEnum = DeclarationEnum::PID; 
    }
    else
    {
        declEnum = DeclarationEnum::TABLE;
    }
    return declEnum;
}

bool CommandWrite::isMultiplication()
{
    return false;
}

bool CommandRead::isMultiplication()
{
    return false;
}

bool CommandAssign::isMultiplication()
{
    return expression->expEnum == ExpressionEnum::MULT;   
}

bool CommandIfElse::isMultiplication()
{
    for(auto& command : commands1)
    {
        if (command->isMultiplication())
        {
            return true;  
        } 
    }
    for(auto& command : commands2)
    {
        if (command->isMultiplication())
        {
            return true;  
        } 
    }
    return false;
}

bool CommandIf::isMultiplication()
{
    for(auto& command : commands)
    {
        if (command->isMultiplication())
        {
            return true;  
        } 
    }
    return false;
}

bool CommandWhile::isMultiplication()
{
    for(auto& command : commands)
    {
        if (command->isMultiplication())
        {
            return true;  
        }
    }
    return false;
}

bool CommandRepeat::isMultiplication()
{
    for(auto& command : commands)
    {
        if (command->isMultiplication())
        {
            return true;  
        }  
    }
    return false;
}

bool CommandForTo::isMultiplication()
{
    for(auto& command : commands)
    {
        if (command->isMultiplication())
        {
            return true;  
        } 
    }
    return false;
}

bool CommandDownTo::isMultiplication()
{
    for(auto& command : commands)
    {
        if (command->isMultiplication())
        {
            return true;
        }
    }
    return false;
}

bool CommandProcCall::isMultiplication()
{
    
    return false;
}

bool CommandWrite::isDivOrMod()
{
    return false;
}

bool CommandRead::isDivOrMod()
{
    return false;
}

bool CommandAssign::isDivOrMod()
{
    return expression->expEnum == ExpressionEnum::DIV || expression->expEnum == ExpressionEnum::MOD;   
}

bool CommandIfElse::isDivOrMod()
{
    for(auto& command : commands1)
    {
        if (command->isDivOrMod())
        {
            return true;  
        }  
    }
    for(auto& command : commands2)
    {
        if (command->isDivOrMod())
        {
            return true;  
        } 
    }
    return false;
}

bool CommandIf::isDivOrMod()
{
    for(auto& command : commands)
    {
        if (command->isDivOrMod())
        {
            return true;  
        } 
    }
    return false;
}

bool CommandWhile::isDivOrMod()
{
    for(auto& command : commands)
    {
        if (command->isDivOrMod())
        {
            return true;  
        } 
    }
    return false;
}

bool CommandRepeat::isDivOrMod()
{
    for(auto& command : commands)
    {
        if (command->isDivOrMod())
        {
            return true;  
        } 
    }
    return false;
}

bool CommandForTo::isDivOrMod()
{
    for(auto& command : commands)
    {
        if (command->isDivOrMod())
        {
            return true;  
        }
    }
    return false;
}

bool CommandDownTo::isDivOrMod()
{
    for(auto& command : commands)
    {
        if (command->isDivOrMod())
        {
            return true;  
        } 
    }
    return false;
}

bool CommandProcCall::isDivOrMod()
{
    
    return false;
}

std::string CommandWrite::ifIsProcCallGetName()
{
    return "";
}

std::string CommandRead::ifIsProcCallGetName()
{
    return "";
}

std::string CommandAssign::ifIsProcCallGetName()
{
    return "";   
}

std::string CommandIfElse::ifIsProcCallGetName()
{
    for(auto& command : commands1)
    {   
        auto procCallName = command->ifIsProcCallGetName();
        if (procCallName != "")
        {
            return procCallName;  
        }
    }
    for(auto& command : commands2)
    {
        auto procCallName = command->ifIsProcCallGetName();
        if (procCallName != "")
        {
            return procCallName;  
        } 
    }
    return "";
}

std::string CommandIf::ifIsProcCallGetName()
{
    for(auto& command : commands)
    {
        auto procCallName = command->ifIsProcCallGetName();
        if (procCallName != "")
        {
            return procCallName;  
        } 
    }
    return "";
}

std::string CommandWhile::ifIsProcCallGetName()
{
    for(auto& command : commands)
    {
        auto procCallName = command->ifIsProcCallGetName();
        if (procCallName != "")
        {
            return procCallName;  
        } 
    }
    return "";
}

std::string CommandRepeat::ifIsProcCallGetName()
{
    for(auto& command : commands)
    {
        auto procCallName = command->ifIsProcCallGetName();
        if (procCallName != "")
        {
            return procCallName;  
        } 
    }
    return "";
}

std::string CommandForTo::ifIsProcCallGetName()
{
    for(auto& command : commands)
    {
        auto procCallName = command->ifIsProcCallGetName();
        if (procCallName != "")
        {
            return procCallName;  
        }
    }
    return "";
}

std::string CommandDownTo::ifIsProcCallGetName()
{
    for(auto& command : commands)
    {
        auto procCallName = command->ifIsProcCallGetName();
        if (procCallName != "")
        {
            return procCallName;  
        } 
    }
    return "";
}

std::string CommandProcCall::ifIsProcCallGetName()
{
    
    return procCall->name;
}

void Command::setLocation(int lin, int col)
{
    line = lin;
    column = col;
}
