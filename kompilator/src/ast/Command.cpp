#include <iostream>

#include "Command.hpp"
#include "../astUtilities/commandsUtilities/CommandIf.hpp"
#include "../astUtilities/commandsUtilities/CommandIfElse.hpp"
#include "../functions/validIdentifier.hpp"

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
            throw std::invalid_argument("You can not change iterator");
        }
        
        throw std::invalid_argument("Undeclared argument");
    }
    
    if (idEnum == IdentifierEnum::PID)
    {
        destinationAddress = symbolTable.getPidAddress(identifier->name1, isInFor);
    }
    else if (idEnum == IdentifierEnum::PIDT)
    {
        destinationAddress = symbolTable.getTableAddress(identifier->name1, identifier->num);
    }
    else
    {
        asmCommands.push_back("    SET " + std::to_string(symbolTable.getTableAddress(identifier->name1)) + "  #Assign pid[pid]");
        asmCommands.push_back("    ADD " + std::to_string(symbolTable.getPidAddress(identifier->name2, isInFor)));
        asmCommands.push_back("    STORE 15");
    }

    auto expEnum = expression->expEnum;
    
    switch (expEnum) {
    case ExpressionEnum::VALUE: {
        auto valueInstructions = makeAsmValue1(symbolTable, isInFor);
        asmCommands.insert(asmCommands.end(), valueInstructions.begin(), valueInstructions.end());

        if (destinationAddress == -1) 
            asmCommands.push_back("    STOREI 15");
        else 
            asmCommands.push_back("    STORE " + std::to_string(destinationAddress));

        break;
    }
    case ExpressionEnum::PLUS: {
        if (expression->value1->valEnum == ValueEnum::NUM && expression->value2->valEnum == ValueEnum::NUM) {
            auto result = expression->value1->value + expression->value2->value;
            asmCommands.push_back("    SET " + std::to_string(result));

            if (destinationAddress == -1) 
                asmCommands.push_back("    STOREI 15");
            else 
                asmCommands.push_back("    STORE " + std::to_string(destinationAddress));

            break;
        }

        auto value2Instructions = makeAsmValue2(symbolTable, isInFor);
        asmCommands.insert(asmCommands.end(), value2Instructions.begin(), value2Instructions.end());

        auto value1Instructions = makeAsmValue1(symbolTable, isInFor);
        asmCommands.insert(asmCommands.end(), value1Instructions.begin(), value1Instructions.end());

        asmCommands.push_back("    ADD 10");
        if (destinationAddress == -1) 
            asmCommands.push_back("    STOREI 15");
        else 
            asmCommands.push_back("    STORE " + std::to_string(destinationAddress));

        break;
    }
    case ExpressionEnum::MINUS: {
        if (expression->value1->valEnum == ValueEnum::NUM && expression->value2->valEnum == ValueEnum::NUM) {
            auto result = expression->value1->value - expression->value2->value;
            asmCommands.push_back("    SET " + std::to_string(result));

            if (destinationAddress == -1) 
                asmCommands.push_back("    STOREI 15");
            else 
                asmCommands.push_back("    STORE " + std::to_string(destinationAddress));

            break;
        }

        auto value2Instructions = makeAsmValue2(symbolTable, isInFor);
        asmCommands.insert(asmCommands.end(), value2Instructions.begin(), value2Instructions.end());

        auto value1Instructions = makeAsmValue1(symbolTable, isInFor);
        asmCommands.insert(asmCommands.end(), value1Instructions.begin(), value1Instructions.end());

        asmCommands.push_back("    SUB 10");
        if (destinationAddress == -1) 
            asmCommands.push_back("    STOREI 15");
        else 
            asmCommands.push_back("    STORE " + std::to_string(destinationAddress));

        break;
    }
    default:
        throw std::invalid_argument("Type of expression isn't supported");
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

    auto tempVec2 = makeAsmValue2(symbolTable, isInFor);
    auto tempVec1 = makeAsmValue1(symbolTable, isInFor);
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

    auto tempVec2 = makeAsmValue2(symbolTable, isInFor);
    auto tempVec1 = makeAsmValue1(symbolTable, isInFor);
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

    for (auto& command : commands2)
    {
        auto tempVec = command->executeCommand(symbolTable, procedures, procedureStartEndInAssembly, howManyAsmCommand + asmCommandCounter + asmCommandsElse.size(), isInFor);
        asmCommandsElse.insert(asmCommandsElse.end(), tempVec.begin(), tempVec.end());
    }
    auto amountElseCommands = asmCommandsElse.size();

    for (auto& command : commands1)
    {
        auto tempVec = command->executeCommand(symbolTable, procedures, procedureStartEndInAssembly, howManyAsmCommand + asmCommandCounter + asmCommandsIF.size(), isInFor);
        asmCommandsIF.insert(asmCommandsIF.end(), tempVec.begin(), tempVec.end());
    }
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

    auto tempVec2 = makeAsmValue2(symbolTable, isInFor);
    auto tempVec1 = makeAsmValue1(symbolTable, isInFor);
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

    auto tempVec2 = makeAsmValue2(symbolTable, isInFor);
    auto tempVec1 = makeAsmValue1(symbolTable, isInFor);
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

    auto tempVec1 = makeAsmValue1(symbolTable, true);
    auto tempVec2 = makeAsmValue2(symbolTable, true);

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

    auto tempVec1 = makeAsmValue1(symbolTable, true);
    auto tempVec2 = makeAsmValue2(symbolTable, true);

    asmCommand.insert(asmCommand.end(), tempVec1.begin(), tempVec1.end());
    asmCommand.push_back("    STORE " + std::to_string(itAddress));

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
    asmCommandsFor.push_back("    JUMP " + std::to_string(-(amountForCommands + 2))); //powrót do sprawdzenia "warunku" SUB, JNEG (w akumulatorze został wynik z dodanie 1 do iteratora)
    amountForCommands++;

    asmCommand.push_back("    LOAD " + std::to_string(itAddress));
    asmCommand.push_back("    SUB " + std::to_string(toAddress));
    asmCommand.push_back("    JNEG " + std::to_string(amountForCommands + 1));

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
    std::vector<std::string> asmCommand;

    //validation of the call
    if (!isValidDeclared(symbolTable, procedures, procCall->name))
    {
        throw std::invalid_argument("Procedure is not declared or declared in bad place");
    }
    if (!areArgsValid(symbolTable, procedures, procCall->name, procCall->args))
        throw std::invalid_argument("Number or type of arguments are not valid or some argument does not exist or it is an iterator");

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
    long long jumpToProc = howManyAsmCommand + 3 - startProcedure; // +3 because SET, STORE and JUMP are added. 

    asmCommand.push_back("    SET " + std::to_string(howManyAsmCommand + 4));
    asmCommand.push_back("    STORE " + std::to_string(procedure->rntrAddress));
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
    bool isArg;
    auto idEnum = identifier->idEnum;

    if(!isValidIdentifier(symbolTable, identifier))
    {
        if (!symbolTable.isIterator(identifier->name1) || identifier->idEnum != IdentifierEnum::PID)
        {
            throw std::invalid_argument("Undeclared argument");
        }
        throw std::invalid_argument("you can't change an iterator");
    }

    if (identifier->idEnum == IdentifierEnum::PID) 
    {
        asmCommands.push_back("    GET " + std::to_string(symbolTable.getPidAddress(idName, isInFor)));
    } 
    else if (identifier->idEnum == IdentifierEnum::PIDT) 
    {
        asmCommands.push_back("    GET " + 
                                std::to_string(symbolTable.getTableAddress(identifier->name1, identifier->num)));
    } 
    else if (identifier->idEnum == IdentifierEnum::PIDTPID) 
    {
        asmCommands.push_back("    GET 2");
        asmCommands.push_back("    SET " + std::to_string(symbolTable.getTableAddress(identifier->name1)));
        asmCommands.push_back("    ADD " + std::to_string(symbolTable.getPidAddress(identifier->name2, isInFor)));
        asmCommands.push_back("    STORE 1");
        asmCommands.push_back("    LOAD 2");
        asmCommands.push_back("    STOREI 1");
    } else {
        throw std::invalid_argument("Bad Identifier Enum");
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
            throw std::invalid_argument("Undeclared argument");
        }
    }

    if (value->identifier->idEnum == IdentifierEnum::PID) {
        asmCommands.push_back("    PUT " + std::to_string(symbolTable.getPidAddress(value->identifier->name1, isInFor)));
    } 
    else if (value->identifier->idEnum == IdentifierEnum::PIDT) {

        asmCommands.push_back("    PUT " +
                              std::to_string(symbolTable.getTableAddress(value->identifier->name1, value->identifier->num)));
    } 
    else if (value->identifier->idEnum == IdentifierEnum::PIDTPID) {
        asmCommands.push_back("    SET " + std::to_string(symbolTable.getTableAddress(value->identifier->name1)));
        asmCommands.push_back("    ADD " + std::to_string(symbolTable.getPidAddress(value->identifier->name2, isInFor)));
        asmCommands.push_back("    LOADI 0");
        asmCommands.push_back("    PUT 0");
    } else {
        throw std::invalid_argument("Invalid Identifier Enum");
    }

    return asmCommands;
}


std::vector<std::string> CommandAssign::makeAsmValue1(SymbolTable& symbolTable, bool isInFor) {
    std::vector<std::string> asmCommands;


    if (expression->value1->valEnum == ValueEnum::NUM) {
        asmCommands.push_back("    SET " + std::to_string(expression->value1->value));
        return asmCommands;
    } 

    if (!isValidIdentifier(symbolTable, expression->value1->identifier))
    {
        if (!symbolTable.isIterator(expression->value1->identifier->name1) || expression->value1->identifier->idEnum != IdentifierEnum::PID)
        {
            throw std::invalid_argument("Undeclared argument");
        }
    }

    if (expression->value1->identifier->idEnum == IdentifierEnum::PID) {
        asmCommands.push_back("    LOAD " + 
                              std::to_string(symbolTable.getPidAddress(expression->value1->identifier->name1, isInFor)));
    } 
    else if (expression->value1->identifier->idEnum == IdentifierEnum::PIDT) {
        asmCommands.push_back("    LOAD " + 
                              std::to_string(symbolTable.getTableAddress(expression->value1->identifier->name1, 
                                                                         expression->value1->identifier->num)));
    } 
    else if (expression->value1->identifier->idEnum == IdentifierEnum::PIDTPID) {

        asmCommands.push_back("    SET " + 
                              std::to_string(symbolTable.getTableAddress(expression->value1->identifier->name1)));
        asmCommands.push_back("    ADD " + 
                              std::to_string(symbolTable.getPidAddress(expression->value1->identifier->name2, isInFor)));
        asmCommands.push_back("    LOADI 0");
    } 

    return asmCommands;
}


std::vector<std::string> CommandAssign::makeAsmValue2(SymbolTable& symbolTable, bool isInFor) {
    std::vector<std::string> asmCommands;

    if (expression->value2->valEnum == ValueEnum::NUM) {
        asmCommands.push_back("    SET " + std::to_string(expression->value2->value));
        asmCommands.push_back("    STORE 10");
        return asmCommands;
    }

    if (!isValidIdentifier(symbolTable, expression->value2->identifier))
    {
        if (!symbolTable.isIterator(expression->value2->identifier->name1) || expression->value2->identifier->idEnum != IdentifierEnum::PID)
        {
            throw std::invalid_argument("Undeclared argument");
        }
    }

    if (expression->value2->identifier->idEnum == IdentifierEnum::PID) {

        asmCommands.push_back("    LOAD " + 
                              std::to_string(symbolTable.getPidAddress(expression->value2->identifier->name1, isInFor)));
        asmCommands.push_back("    STORE 10");
    } 
    else if (expression->value2->identifier->idEnum == IdentifierEnum::PIDT) {

        asmCommands.push_back("    LOAD " + 
                              std::to_string(symbolTable.getTableAddress(expression->value2->identifier->name1, 
                                                                         expression->value2->identifier->num)));
        asmCommands.push_back("    STORE 10");
    } 
    else if (expression->value2->identifier->idEnum == IdentifierEnum::PIDTPID) {

        asmCommands.push_back("    SET " + 
                              std::to_string(symbolTable.getTableAddress(expression->value2->identifier->name1)));
        asmCommands.push_back("    ADD " + 
                              std::to_string(symbolTable.getPidAddress(expression->value2->identifier->name2, isInFor)));
        asmCommands.push_back("    LOADI 0");
        asmCommands.push_back("    STORE 10");
    } 

    return asmCommands;
}



std::vector<std::string> CommandCondition::makeAsmValue1(SymbolTable& symbolTable, bool isInFor) const
{
    std::vector<std::string> asmCommands;
    if (condition->value1->valEnum == ValueEnum::NUM) {
        asmCommands.push_back("    SET " + std::to_string(condition->value1->value));
        return asmCommands;
    } 

    if (!isValidIdentifier(symbolTable, condition->value1->identifier))
    {
        if (!symbolTable.isIterator(condition->value1->identifier->name1) || condition->value1->identifier->idEnum != IdentifierEnum::PID)
        {
            throw std::invalid_argument("Undeclared argument");
        }
    }

    if (condition->value1->identifier->idEnum == IdentifierEnum::PID) {
        asmCommands.push_back("    LOAD " + 
                              std::to_string(symbolTable.getPidAddress(condition->value1->identifier->name1, isInFor)));
    } 
    else if (condition->value1->identifier->idEnum == IdentifierEnum::PIDT) {
        asmCommands.push_back("    LOAD " + 
                              std::to_string(symbolTable.getTableAddress(condition->value1->identifier->name1, 
                                                                         condition->value1->identifier->num)));
    } 
    else if (condition->value1->identifier->idEnum == IdentifierEnum::PIDTPID) {

        asmCommands.push_back("    SET " + 
                              std::to_string(symbolTable.getTableAddress(condition->value1->identifier->name1)));
        asmCommands.push_back("    ADD " + 
                              std::to_string(symbolTable.getPidAddress(condition->value1->identifier->name2, isInFor)));
        asmCommands.push_back("    LOADI 0");
    } 

    return asmCommands;
}
std::vector<std::string> CommandCondition::makeAsmValue2(SymbolTable& symbolTable, bool isInFor) const
{
    std::vector<std::string> asmCommands;

    if (condition->value2->valEnum == ValueEnum::NUM) {
        asmCommands.push_back("    SET " + std::to_string(condition->value2->value));
        asmCommands.push_back("    STORE 10");
        return asmCommands;
    }

    if (!isValidIdentifier(symbolTable, condition->value2->identifier))
    {
        if (!symbolTable.isIterator(condition->value2->identifier->name1) || condition->value2->identifier->idEnum != IdentifierEnum::PID)
        {
            throw std::invalid_argument("Undeclared argument");
        }
    }

    if (condition->value2->identifier->idEnum == IdentifierEnum::PID) {

        asmCommands.push_back("    LOAD " + 
                              std::to_string(symbolTable.getPidAddress(condition->value2->identifier->name1, isInFor)));
        asmCommands.push_back("    STORE 10");
    } 
    else if (condition->value2->identifier->idEnum == IdentifierEnum::PIDT) {

        asmCommands.push_back("    LOAD " + 
                              std::to_string(symbolTable.getTableAddress(condition->value2->identifier->name1, 
                                                                         condition->value2->identifier->num)));
        asmCommands.push_back("    STORE 10");
    } 
    else if (condition->value2->identifier->idEnum == IdentifierEnum::PIDTPID) {

        asmCommands.push_back("    SET " + 
                              std::to_string(symbolTable.getTableAddress(condition->value2->identifier->name1)));
        asmCommands.push_back("    ADD " + 
                              std::to_string(symbolTable.getPidAddress(condition->value2->identifier->name2, isInFor)));
        asmCommands.push_back("    LOADI 0");
        asmCommands.push_back("    STORE 10");
    } 

    return asmCommands;
}

std::vector<std::string> CommandForTo::makeAsmValue1(SymbolTable& symbolTable, bool isInFor)
{
    std::vector<std::string> asmCommands;
    if (value1->valEnum == ValueEnum::NUM) {
        asmCommands.push_back("    SET " + std::to_string(value1->value));
        return asmCommands;
    } 

    if (!isValidIdentifier(symbolTable, value1->identifier))
    {
        if (!symbolTable.isIterator(value1->identifier->name1) || value1->identifier->idEnum != IdentifierEnum::PID)
        {
            throw std::invalid_argument("Undeclared argument");
        }
    }

    if (value1->identifier->idEnum == IdentifierEnum::PID) {
        asmCommands.push_back("    LOAD " + 
                              std::to_string(symbolTable.getPidAddress(value1->identifier->name1, isInFor)));
    } 
    else if (value1->identifier->idEnum == IdentifierEnum::PIDT) {
        asmCommands.push_back("    LOAD " + 
                              std::to_string(symbolTable.getTableAddress(value1->identifier->name1, 
                                                                         value1->identifier->num)));
    } 
    else if (value1->identifier->idEnum == IdentifierEnum::PIDTPID) {

        asmCommands.push_back("    SET " + 
                              std::to_string(symbolTable.getTableAddress(value1->identifier->name1)));
        asmCommands.push_back("    ADD " + 
                              std::to_string(symbolTable.getPidAddress(value1->identifier->name2, isInFor)));
        asmCommands.push_back("    LOADI 0");
    } 

    return asmCommands;
}

std::vector<std::string> CommandForTo::makeAsmValue2(SymbolTable& symbolTable, bool isInFor)
{
    std::vector<std::string> asmCommands;
    if (value2->valEnum == ValueEnum::NUM) {
        asmCommands.push_back("    SET " + std::to_string(value2->value));
        return asmCommands;
    } 

    if (!isValidIdentifier(symbolTable, value2->identifier))
    {
        if (!symbolTable.isIterator(value2->identifier->name1) || value2->identifier->idEnum != IdentifierEnum::PID)
        {
            throw std::invalid_argument("Undeclared argument");
        }
    }
        

    if (value2->identifier->idEnum == IdentifierEnum::PID) {
        asmCommands.push_back("    LOAD " + 
                              std::to_string(symbolTable.getPidAddress(value2->identifier->name1, isInFor)));
    } 
    else if (value2->identifier->idEnum == IdentifierEnum::PIDT) {
        asmCommands.push_back("    LOAD " + 
                              std::to_string(symbolTable.getTableAddress(value2->identifier->name1, 
                                                                         value2->identifier->num)));
    } 
    else if (value2->identifier->idEnum == IdentifierEnum::PIDTPID) {

        asmCommands.push_back("    SET " + 
                              std::to_string(symbolTable.getTableAddress(value2->identifier->name1)));
        asmCommands.push_back("    ADD " + 
                              std::to_string(symbolTable.getPidAddress(value2->identifier->name2, isInFor)));
        asmCommands.push_back("    LOADI 0");
    } 

    return asmCommands;
}

std::vector<std::string> CommandDownTo::makeAsmValue1(SymbolTable& symbolTable, bool isInFor)
{
    std::vector<std::string> asmCommands;
    if (value1->valEnum == ValueEnum::NUM) {
        asmCommands.push_back("    SET " + std::to_string(value1->value));
        return asmCommands;
    } 

    if (!isValidIdentifier(symbolTable, value1->identifier))
    {
        if (!symbolTable.isIterator(value1->identifier->name1) || value1->identifier->idEnum != IdentifierEnum::PID)
        {
            throw std::invalid_argument("Undeclared argument");
        }
    }

    if (value1->identifier->idEnum == IdentifierEnum::PID) {
        asmCommands.push_back("    LOAD " + 
                              std::to_string(symbolTable.getPidAddress(value1->identifier->name1, isInFor)));
    } 
    else if (value1->identifier->idEnum == IdentifierEnum::PIDT) {
        asmCommands.push_back("    LOAD " + 
                              std::to_string(symbolTable.getTableAddress(value1->identifier->name1, 
                                                                         value1->identifier->num)));
    } 
    else if (value1->identifier->idEnum == IdentifierEnum::PIDTPID) {

        asmCommands.push_back("    SET " + 
                              std::to_string(symbolTable.getTableAddress(value1->identifier->name1)));
        asmCommands.push_back("    ADD " + 
                              std::to_string(symbolTable.getPidAddress(value1->identifier->name2, isInFor)));
        asmCommands.push_back("    LOADI 0");
    } 

    return asmCommands;
}

std::vector<std::string> CommandDownTo::makeAsmValue2(SymbolTable& symbolTable, bool isInFor)
{
    std::vector<std::string> asmCommands;
    if (value2->valEnum == ValueEnum::NUM) {
        asmCommands.push_back("    SET " + std::to_string(value2->value));
        return asmCommands;
    } 

    if (!isValidIdentifier(symbolTable, value2->identifier))
    {
        if (!symbolTable.isIterator(value2->identifier->name1) || value2->identifier->idEnum != IdentifierEnum::PID)
        {
            throw std::invalid_argument("Undeclared argument");
        }
    }
        

    if (value2->identifier->idEnum == IdentifierEnum::PID) {
        asmCommands.push_back("    LOAD " + 
                              std::to_string(symbolTable.getPidAddress(value2->identifier->name1, isInFor)));
    } 
    else if (value2->identifier->idEnum == IdentifierEnum::PIDT) {
        asmCommands.push_back("    LOAD " + 
                              std::to_string(symbolTable.getTableAddress(value2->identifier->name1, 
                                                                         value2->identifier->num)));
    } 
    else if (value2->identifier->idEnum == IdentifierEnum::PIDTPID) {

        asmCommands.push_back("    SET " + 
                              std::to_string(symbolTable.getTableAddress(value2->identifier->name1)));
        asmCommands.push_back("    ADD " + 
                              std::to_string(symbolTable.getPidAddress(value2->identifier->name2, isInFor)));
        asmCommands.push_back("    LOADI 0");
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