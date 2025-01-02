#include <iostream>

#include "ast.hpp"
#include "SymbolTable.hpp"
#include "functions/validIdentifier.hpp"
#include "Commands/CommandIf.hpp"
#include "Commands/CommandIfElse.hpp"


Identifier::Identifier(std::string pid, IdentifierEnum idEnum) : name1(pid), idEnum(idEnum)
{
}
Identifier::Identifier(std::string pid1, std::string pid2, IdentifierEnum idEnum) : name1(pid1), name2(pid2), idEnum(idEnum)
{
}
Identifier::Identifier(std::string pid, long long num, IdentifierEnum idEnum) : name1(pid), num(num), idEnum(idEnum)
{
}
std::string Identifier::doAsm() const{
    return std::string("Identifier");
}

std::shared_ptr<Identifier> makeIdentifier(std::string name, IdentifierEnum idEnum) {
    std::cout <<"tworzę Identifier pid" <<std::endl;
    auto id = std::make_unique<Identifier>(name, idEnum);
    return std::move(id);
}

std::shared_ptr<Identifier> makeIdentifier(std::string pid1, std::string pid2, IdentifierEnum idEnum) {
    std::cout <<"tworzę Identifier pid[pid]" <<std::endl;
    auto id = std::make_unique<Identifier>(pid1, pid2, idEnum);
    return std::move(id);
}

std::shared_ptr<Identifier> makeIdentifier(std::string pid, long long num, IdentifierEnum idEnum) {
    std::cout <<"tworzę Identifier pid[num]" <<std::endl;
    auto id = std::make_unique<Identifier>(pid, num, idEnum);
    return std::move(id);
}


Value::Value(std::shared_ptr<Identifier> id, ValueEnum valEnum) : identifier(std::move(id)), valEnum(valEnum){}

Value::Value(long long num, ValueEnum valEnum) : value(num), valEnum(valEnum){}

std::string Value::doAsm() const{
    return std::string("Value");
}


Condition::Condition(std::shared_ptr<Value> val1, std::shared_ptr<Value> val2, ConditionEnum condEnum) 
    : value1(std::move(val1)), value2(std::move(val2)), condEnum(condEnum){}

std::string Condition::doAsm() const{
    return std::string("Condition");
}


Expression::Expression(std::shared_ptr<Value> value, ExpressionEnum expEnum)
    : value1(std::move(value)), expEnum(expEnum){} 

Expression::Expression(std::shared_ptr<Value> value1, std::shared_ptr<Value> value2, ExpressionEnum expEnum)
    : value1(std::move(value1)), value2(std::move(value2)), expEnum(expEnum){}

std::string Expression::doAsm() const{
    return std::string("Expression");
}

Args::Args(std::string name) : name(name){}

std::string Args::doAsm() const 
{
    return std::string("Args");
}

std::vector<std::shared_ptr<Args>> makeArgs(std::string& arg)
{
    return std::vector<std::shared_ptr<Args>>({std::make_shared<Args>(arg)});
}

std::vector<std::shared_ptr<Args>> makeArgs(std::vector<std::shared_ptr<Args>>& vec, std::string& arg)
{
    vec.push_back(std::make_shared<Args>(arg));
    return vec;
}


ArgsDeclaration::ArgsDeclaration(std::string name, ArgsDeclarationEnum argsDecEnum)
    : name(std::move(name)), argsDecEnum(argsDecEnum){}

std::string ArgsDeclaration::doAsm() const {
    return std::string("ArgsDec");
}


std::vector<std::shared_ptr<ArgsDeclaration>> makeArgsDeclaration(
    std::vector<std::shared_ptr<ArgsDeclaration>>& vec, 
    const std::string& argDec, 
    ArgsDeclarationEnum argDecEnum)
{
    vec.push_back(std::make_shared<ArgsDeclaration>(argDec, argDecEnum));
    return vec;
}

std::vector<std::shared_ptr<ArgsDeclaration>> makeArgsDeclaration(
    const std::string& argDec, 
    ArgsDeclarationEnum argsDecEnum)
{
    std::vector<std::shared_ptr<ArgsDeclaration>> vec({std::make_shared<ArgsDeclaration>(argDec, argsDecEnum)});
    return vec;
}


Declaration::Declaration(const std::string name, DeclarationEnum decEnum)
    : name(name), decEnum(decEnum), num1(0), num2(0){}

Declaration::Declaration(const std::string name, DeclarationEnum decEnum, long long num1, long long num2)
    : name(name), decEnum(decEnum), num1(num1), num2(num2)
    {
        if(num1 > num2) throw std::invalid_argument("num1 > num2");
    }

std::string Declaration::doAsm() const
{
    return std::string("Declaration");
}

std::vector<std::shared_ptr<Declaration>> makeDeclaration(const std::string name, std::initializer_list<long long> list)
{
    std::vector<std::shared_ptr<Declaration>> vec;
    if(list.size() == 0) vec.push_back(std::make_shared<Declaration>(name, DeclarationEnum::PID));
    else if(list.size() == 2)  
    {
        auto it = list.begin();
        vec.push_back(std::make_shared<Declaration>(name, DeclarationEnum::TABLE, *it, *(it+1)));
    }
    else
        throw std::invalid_argument("Ivalid number of arguments");
    return vec;
}

std::vector<std::shared_ptr<Declaration>> makeDeclaration(
    std::vector<std::shared_ptr<Declaration>> vec, 
    const std::string name, 
    std::initializer_list<long long> list){
    if(list.size() == 0) 
        vec.push_back(std::make_shared<Declaration>(name, DeclarationEnum::PID));
    else if(list.size() == 2) 
    {
        auto it = list.begin();
        vec.push_back(std::make_shared<Declaration>(name, DeclarationEnum::TABLE, *it, *(it+1)));
    }
    else 
        throw std::invalid_argument("Invalid number of argument");
    return vec;
}


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

std::shared_ptr<ProcHead> makeProcHead(std::string name, std::vector<std::shared_ptr<ArgsDeclaration>> argsDecl)
{
    return std::make_unique<ProcHead>(name, argsDecl);
}


ProcCall::ProcCall(std::string name, std::vector<std::shared_ptr<Args>> args)
    : name(name), args(args){}

std::string ProcCall::doAsm() const 
{
    return std::string("Proc_call");
}

std::shared_ptr<ProcCall> makeProcCall(std::string name, std::vector<std::shared_ptr<Args>> args)
{
    return std::make_unique<ProcCall>(name, args);
}


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
    : condition(std::move(cond)), commands(std::move(commands))
{
    commandEnum = CommandEnum::WHILE;
}

std::string CommandWhile::doAsm() const
{
    return std::string("Command While");
}


CommandRepeat::CommandRepeat(std::vector<std::shared_ptr<Command>> commands, std::shared_ptr<Condition> cond)
    : commands(std::move(commands)), condition(std::move(cond))
{
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
    commandEnum = CommandEnum::FORTO;
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


std::vector<std::shared_ptr<Command>> makeCommands(std::shared_ptr<Command> command)
{
    return std::vector<std::shared_ptr<Command>>({std::move(command)});
}
std::vector<std::shared_ptr<Command>> makeCommands(std::vector<std::shared_ptr<Command>> vec, std::shared_ptr<Command> command)
{
    vec.push_back(std::move(command));
    return vec;
}


Procedure::Procedure(
        std::shared_ptr<ProcHead> procHead, 
        std::vector<std::shared_ptr<Declaration>> declarations, 
        std::vector<std::shared_ptr<Command>> commands,
        ProcedureEnum procEnum)
    : procHead(std::move(procHead)), declarations(declarations), commands(commands), procEnum(procEnum), symbolTable(SymbolTable()){}

Procedure::Procedure(
    std::shared_ptr<ProcHead> procHead,
    std::vector<std::shared_ptr<Command>> commands,
    ProcedureEnum procEnum)
: procHead(std::move(procHead)), declarations({}), commands(commands), procEnum(procEnum){}

std::string Procedure::doAsm() const
{
    return std::string("Procedure");
}

void Procedure::fillSymbolTable(){
    procHead->fillSymbolTable(symbolTable);
    if(procEnum == ProcedureEnum::WITHDECLARATION){
        for(auto& decl : declarations)
        {
            symbolTable.addDeclarations(decl);
        }
    }    
}

std::vector<std::shared_ptr<Procedure>> makeProcedures(
    std::vector<std::shared_ptr<Procedure>> vec
    , std::shared_ptr<ProcHead> procHead
    , std::vector<std::shared_ptr<Declaration>> declarations
    , std::vector<std::shared_ptr<Command>> commands
    , ProcedureEnum procEnum) 
{
    vec.push_back(std::make_unique<Procedure>(std::move(procHead), declarations, commands, procEnum));
    return vec;
}

std::vector<std::shared_ptr<Procedure>> makeProcedures(
    std::vector<std::shared_ptr<Procedure>> vec
    , std::shared_ptr<ProcHead> procHead
    , std::vector<std::shared_ptr<Command>> commands
    , ProcedureEnum procEnum) 
{
    vec.push_back(std::make_unique<Procedure>(std::move(procHead), commands, procEnum));
    return vec;
}

std::vector<std::shared_ptr<Procedure>> makeProcedures()
{
    std::vector<std::shared_ptr<Procedure>> vec = {};
    return vec;
}


MainWithDecl::MainWithDecl(std::vector<std::shared_ptr<Declaration>> declarations, std::vector<std::shared_ptr<Command>> commands)
    : declarations(declarations)
{
    this->commands = commands;
    this->symbolTable = SymbolTable();
}

std::string MainWithDecl::doAsm() const 
{
    std::cout << "MainWithDecl  start" <<std::endl;
    for(auto comm : commands)
    {
        comm->doAsm();
    }
    std::cout << "MainWithDecl  end" <<std::endl;
    return std::string("MainwithDecl");
}

void MainWithDecl::fillSymbolTable() {
    for (const auto& decl : declarations) {
        symbolTable.addDeclarations(decl);
    }
}

    

void MainWithDecl::executeCommand(std::vector<std::shared_ptr<Procedure>>& procedures)
{
    std::vector<std::string> asmCommands;
    for(auto& command : commands)
    {
        auto tempVector = command->executeCommand(symbolTable, procedures);
        asmCommands.insert(asmCommands.end(), tempVector.begin(), tempVector.end());
    }

    for (auto& line : asmCommands)
    {
        symbolTable.outputFile << line << std::endl;
    }
    symbolTable.outputFile << "    HALT" << std::endl;
}

MainWithoutDecl::MainWithoutDecl(std::vector<std::shared_ptr<Command>> commands)
{
    this->commands = commands;
}

std::string MainWithoutDecl::doAsm() const 
{
    for(auto comm : commands)
    {
        comm->doAsm();
    }
    return std::string("b");
}

void MainWithoutDecl::fillSymbolTable() {}

void MainWithoutDecl::executeCommand(std::vector<std::shared_ptr<Procedure>>& procedures)
{
    std::vector<std::string> asmCommands;
    for(auto& command : commands)
    {
        auto tempVector = command->executeCommand(symbolTable, procedures);
        asmCommands.insert(asmCommands.end(), tempVector.begin(), tempVector.end());
    }

    for (auto& line : asmCommands)
    {
        symbolTable.outputFile << line;
    }
    symbolTable.outputFile << "    HALT" <<std::endl;
}


void mainProgram(std::vector<std::shared_ptr<Procedure>>& procedures, std::shared_ptr<Main> program){
    for(auto& proc : procedures)
    {
        proc->fillSymbolTable();
        proc->symbolTable.printAllDeclAndArgs();
    }
    program->fillSymbolTable();
    program->symbolTable.printAllDeclAndArgs();
    program->executeCommand(procedures);






    // std::cout << "Main program start" <<std::endl;
    // for(auto& proc_ptr : procedures)
    // {
    //     proc_ptr->doAsm();
    // }

    // program->doAsm();

    // std::cout << "Main program end" <<std::endl;

}

std::vector<std::string> CommandAssign::executeCommand(SymbolTable& symbolTable, std::vector<std::shared_ptr<Procedure>>& procedures)
{
    std::vector<std::string> asmCommands;
    long long destinationAddress = -1;
    auto idEnum = identifier->idEnum;

    if (!isValidIdentifier(symbolTable, identifier))
    {
        throw std::invalid_argument("Undeclared variable: " + identifier->name1);
    }
    
    
    if (idEnum == IdentifierEnum::PID)
    {
        destinationAddress = symbolTable.getPidAddress(identifier->name1);
    }
    else if (idEnum == IdentifierEnum::PIDT)
    {
        destinationAddress = symbolTable.getTableAddress(identifier->name1, identifier->num);
    }
    else
    {
        asmCommands.push_back("    SET " + std::to_string(symbolTable.getTableAddress(identifier->name1)) + "  #Assign pid[pid]");
        asmCommands.push_back("    ADD " + std::to_string(symbolTable.getPidAddress(identifier->name2)));
        asmCommands.push_back("    STORE 15");
    }

    auto expEnum = expression->expEnum;
    
    switch (expEnum) {
    case ExpressionEnum::VALUE: {
        auto valueInstructions = makeAsmValue1(symbolTable);
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

        auto value2Instructions = makeAsmValue2(symbolTable);
        asmCommands.insert(asmCommands.end(), value2Instructions.begin(), value2Instructions.end());

        auto value1Instructions = makeAsmValue1(symbolTable);
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

        auto value2Instructions = makeAsmValue2(symbolTable);
        asmCommands.insert(asmCommands.end(), value2Instructions.begin(), value2Instructions.end());

        auto value1Instructions = makeAsmValue1(symbolTable);
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

std::vector<std::string> CommandIf::executeCommand(SymbolTable& symbolTable, std::vector<std::shared_ptr<Procedure>>& procedures)
{
    return executeIfCommand(symbolTable, *this, procedures);
}
std::vector<std::string> CommandIfElse::executeCommand(SymbolTable& symbolTable, std::vector<std::shared_ptr<Procedure>>& procedures)
{
    return executeIfElseCommand(symbolTable, *this, procedures);
}
std::vector<std::string> CommandWhile::executeCommand(SymbolTable& symbolTable, std::vector<std::shared_ptr<Procedure>>& procedures)
{
return std::vector<std::string>();
}
std::vector<std::string> CommandRepeat::executeCommand(SymbolTable& symbolTable, std::vector<std::shared_ptr<Procedure>>& procedures)
{
return std::vector<std::string>();
}
std::vector<std::string> CommandForTo::executeCommand(SymbolTable& symbolTable, std::vector<std::shared_ptr<Procedure>>& procedures)
{
return std::vector<std::string>();
}
std::vector<std::string> CommandDownTo::executeCommand(SymbolTable& symbolTable, std::vector<std::shared_ptr<Procedure>>& procedures)
{
return std::vector<std::string>();
}
std::vector<std::string> CommandProcCall::executeCommand(SymbolTable& symbolTable, std::vector<std::shared_ptr<Procedure>>& procedures)
{
return std::vector<std::string>();
}
std::vector<std::string> CommandRead::executeCommand(SymbolTable& symbolTable, std::vector<std::shared_ptr<Procedure>>& procedures) {
    std::vector<std::string> asmCommands;
    auto idName = identifier->name1;
    bool isDeclared;
    bool isArg;
    auto idEnum = identifier->idEnum;

    if(!isValidIdentifier(symbolTable, identifier))
        throw std::invalid_argument("Undeclared argument");


    if (identifier->idEnum == IdentifierEnum::PID) {
        asmCommands.push_back("    GET " + std::to_string(symbolTable.getPidAddress(idName)));
    } else if (identifier->idEnum == IdentifierEnum::PIDT) {
        asmCommands.push_back("    GET " + 
                                std::to_string(symbolTable.getTableAddress(identifier->name1, identifier->num)));
    } else if (identifier->idEnum == IdentifierEnum::PIDTPID) {


        asmCommands.push_back("    GET 2");
        asmCommands.push_back("    SET " + std::to_string(symbolTable.getTableAddress(identifier->name1)));
        asmCommands.push_back("    ADD " + std::to_string(symbolTable.getPidAddress(identifier->name2)));
        asmCommands.push_back("    STORE 1");
        asmCommands.push_back("    LOAD 2");
        asmCommands.push_back("    STOREI 1");
    } else {
        throw std::invalid_argument("Bad Identifier Enum");
    }

    return asmCommands;
}


std::vector<std::string> CommandWrite::executeCommand(SymbolTable& symbolTable, std::vector<std::shared_ptr<Procedure>>& procedures) {
    std::vector<std::string> asmCommands;

    if (value->valEnum == ValueEnum::NUM) {
        asmCommands.push_back("    SET " + std::to_string(value->value));
        asmCommands.push_back("    PUT 0");
        return asmCommands;
    }

    if(!isValidIdentifier(symbolTable, value->identifier))
        throw std::invalid_argument("Undeclared argument");


    if (value->identifier->idEnum == IdentifierEnum::PID) {
        asmCommands.push_back("    PUT " + std::to_string(symbolTable.getPidAddress(value->identifier->name1)));
    } 
    else if (value->identifier->idEnum == IdentifierEnum::PIDT) {

        asmCommands.push_back("    PUT " +
                              std::to_string(symbolTable.getTableAddress(value->identifier->name1, value->identifier->num)));
    } 
    else if (value->identifier->idEnum == IdentifierEnum::PIDTPID) {
        asmCommands.push_back("    SET " + std::to_string(symbolTable.getTableAddress(value->identifier->name1)));
        asmCommands.push_back("    ADD " + std::to_string(symbolTable.getPidAddress(value->identifier->name2)));
        asmCommands.push_back("    LOADI 0");
        asmCommands.push_back("    PUT 0");
    } else {
        throw std::invalid_argument("Invalid Identifier Enum");
    }

    return asmCommands;
}


std::vector<std::string> CommandAssign::makeAsmValue1(SymbolTable& symbolTable) {
    std::vector<std::string> asmCommands;


    if (expression->value1->valEnum == ValueEnum::NUM) {
        asmCommands.push_back("    SET " + std::to_string(expression->value1->value));
        return asmCommands;
    } 

    if(!isValidIdentifier(symbolTable, expression->value1->identifier))
        throw std::invalid_argument("Undeclared argument");

    if (expression->value1->identifier->idEnum == IdentifierEnum::PID) {
        asmCommands.push_back("    LOAD " + 
                              std::to_string(symbolTable.getPidAddress(expression->value1->identifier->name1)));
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
                              std::to_string(symbolTable.getPidAddress(expression->value1->identifier->name2)));
        asmCommands.push_back("    LOADI 0");
    } 

    return asmCommands;
}


std::vector<std::string> CommandAssign::makeAsmValue2(SymbolTable& symbolTable) {
    std::vector<std::string> asmCommands;

    if (expression->value2->valEnum == ValueEnum::NUM) {
        asmCommands.push_back("    SET " + std::to_string(expression->value2->value));
        asmCommands.push_back("    STORE 10");
        return asmCommands;
    }

    if(!isValidIdentifier(symbolTable, expression->value2->identifier))
        throw std::invalid_argument("Undeclared argument");

    if (expression->value2->identifier->idEnum == IdentifierEnum::PID) {

        asmCommands.push_back("    LOAD " + 
                              std::to_string(symbolTable.getPidAddress(expression->value2->identifier->name1)));
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
                              std::to_string(symbolTable.getPidAddress(expression->value2->identifier->name2)));
        asmCommands.push_back("    LOADI 0");
        asmCommands.push_back("    STORE 10");
    } 

    return asmCommands;
}



std::vector<std::string> CommandCondition::makeAsmValue1(SymbolTable& symbolTable) const
{
    std::vector<std::string> asmCommands;
    if (condition->value1->valEnum == ValueEnum::NUM) {
        asmCommands.push_back("    SET " + std::to_string(condition->value1->value));
        return asmCommands;
    } 

    if(!isValidIdentifier(symbolTable, condition->value1->identifier))
        throw std::invalid_argument("Undeclared argument");

    if (condition->value1->identifier->idEnum == IdentifierEnum::PID) {
        asmCommands.push_back("    LOAD " + 
                              std::to_string(symbolTable.getPidAddress(condition->value1->identifier->name1)));
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
                              std::to_string(symbolTable.getPidAddress(condition->value1->identifier->name2)));
        asmCommands.push_back("    LOADI 0");
    } 

    return asmCommands;
}
std::vector<std::string> CommandCondition::makeAsmValue2(SymbolTable& symbolTable) const
{
    std::vector<std::string> asmCommands;

    if (condition->value2->valEnum == ValueEnum::NUM) {
        asmCommands.push_back("    SET " + std::to_string(condition->value2->value));
        asmCommands.push_back("    STORE 10");
        return asmCommands;
    }

    if(!isValidIdentifier(symbolTable, condition->value2->identifier))
        throw std::invalid_argument("Undeclared argument");

    if (condition->value2->identifier->idEnum == IdentifierEnum::PID) {

        asmCommands.push_back("    LOAD " + 
                              std::to_string(symbolTable.getPidAddress(condition->value2->identifier->name1)));
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
                              std::to_string(symbolTable.getPidAddress(condition->value2->identifier->name2)));
        asmCommands.push_back("    LOADI 0");
        asmCommands.push_back("    STORE 10");
    } 

    return asmCommands;
}