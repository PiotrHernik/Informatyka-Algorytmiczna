#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <vector>
#include <initializer_list>

#include "SymbolTable.hpp"

struct CommandIf;
struct CommandIfElse;

struct Node
{
    virtual ~Node() = default;
    virtual std::string doAsm()  const = 0;
};

enum class IdentifierEnum {
    PID,
    PIDT,
    PIDTPID
};

struct Identifier : Node {
    Identifier(std::string pid, IdentifierEnum idEnum);
    Identifier(std::string pid1, std::string pid2, IdentifierEnum idEnum);
    Identifier(std::string pid, long long num, IdentifierEnum idEnum);
    std::string doAsm() const override;
    IdentifierEnum idEnum;
    std::string name1;
    std::string name2;
    long long num;
};

std::shared_ptr<Identifier> makeIdentifier(std::string pid, IdentifierEnum idEnum);
std::shared_ptr<Identifier> makeIdentifier(std::string pid1, std::string pid2, IdentifierEnum idEnum);
std::shared_ptr<Identifier> makeIdentifier(std::string pid, long long num, IdentifierEnum idEnum);
enum class ValueEnum 
{
    NUM,
    ID
};


struct Value : Node 
{
    Value(std::shared_ptr<Identifier>, ValueEnum);
    Value(long long, ValueEnum);
    std::string doAsm() const override;
    ValueEnum valEnum;
    std::shared_ptr<Identifier> identifier;
    long long value;
};

enum class ConditionEnum 
{
    EQUAL,
    NOTEQUAL,
    MORE,
    LESS,
    MOREOREQUAL,
    LESSOREQUAL
};

struct Condition : Node 
{
    Condition(std::shared_ptr<Value> value1, std::shared_ptr<Value> value2, ConditionEnum condEnum);
    std::string doAsm() const override;
    
    ConditionEnum condEnum;
    std::shared_ptr<Value> value1;
    std::shared_ptr<Value> value2;
    bool conditionResult;
};

enum class ExpressionEnum
{
    VALUE,
    PLUS,
    MINUS,
    MULT,
    DIV,
    MOD
};

struct Expression : Node 
{
    Expression(std::shared_ptr<Value>, ExpressionEnum);
    Expression(std::shared_ptr<Value>, std::shared_ptr<Value>, ExpressionEnum);
    std::string doAsm() const override;

    std::shared_ptr<Value> value1;
    std::shared_ptr<Value> value2;
    ExpressionEnum expEnum;
};

struct Args : Node
{
    Args(std::string);
    std::string doAsm() const override;

    std::string name;
};

std::vector<std::shared_ptr<Args>> makeArgs(std::string&);
std::vector<std::shared_ptr<Args>> makeArgs(std::vector<std::shared_ptr<Args>>&, std::string&);

enum class ArgsDeclarationEnum 
{
    PID,
    TABLE
};

struct ArgsDeclaration : Node 
{
    ArgsDeclaration(std::string, ArgsDeclarationEnum);
    std::string doAsm() const override;

    std::string name;
    ArgsDeclarationEnum argsDecEnum;

};

std::vector<std::shared_ptr<ArgsDeclaration>> makeArgsDeclaration(std::vector<std::shared_ptr<ArgsDeclaration>>&, const std::string&, ArgsDeclarationEnum);
std::vector<std::shared_ptr<ArgsDeclaration>> makeArgsDeclaration(const std::string&, ArgsDeclarationEnum);


enum class DeclarationEnum
{
    PID,
    TABLE
};

struct Declaration : Node 
{
    Declaration(const std::string, DeclarationEnum);
    Declaration(const std::string, DeclarationEnum, long long num1, long long num2);
    std::string doAsm() const override;

    std::string name;
    DeclarationEnum decEnum;
    long long num1;
    long long num2;
};

std::vector<std::shared_ptr<Declaration>> makeDeclaration(const std::string, std::initializer_list<long long>);
std::vector<std::shared_ptr<Declaration>> makeDeclaration(std::vector<std::shared_ptr<Declaration>> vec, const std::string, std::initializer_list<long long>);



struct ProcHead : Node 
{
    ProcHead(std::string, std::vector<std::shared_ptr<ArgsDeclaration>>);
    std::string doAsm() const override;
    void fillSymbolTable(SymbolTable& symbTab);

    std::string name;
    std::vector<std::shared_ptr<ArgsDeclaration>> argsDecl;
};

std::shared_ptr<ProcHead> makeProcHead(std::string, std::vector<std::shared_ptr<ArgsDeclaration>>);

struct ProcCall : Node 
{
    ProcCall(std::string, std::vector<std::shared_ptr<Args>>);
    std::string doAsm() const override;

    std::string name;
    std::vector<std::shared_ptr<Args>> args;
};

std::shared_ptr<ProcCall> makeProcCall(std::string, std::vector<std::shared_ptr<Args>>);

enum class CommandEnum
{
    ASSIGN,
    IFELSE,
    IF,
    WHILE,
    REPEAT,
    FORTO,
    FORDOWNTO,
    PROCCALL,
    READ,
    WRITE
};

struct Command : Node
{
    virtual std::vector<std::string> executeCommand(SymbolTable&, std::vector<std::shared_ptr<Procedure>>&) = 0;
    CommandEnum commandEnum;
};


struct CommandAssign : Command
{
    CommandAssign(std::shared_ptr<Identifier>, std::shared_ptr<Expression>);
    std::string doAsm() const override;
    std::vector<std::string> executeCommand(SymbolTable&, std::vector<std::shared_ptr<Procedure>>&) override;
    std::vector<std::string> makeAsmValue1(SymbolTable&);
    std::vector<std::string> makeAsmValue2(SymbolTable&);

    std::shared_ptr<Identifier> identifier;
    std::shared_ptr<Expression> expression;
};

struct CommandCondition : Command
{
protected:
    std::vector<std::string> makeAsmValue1(SymbolTable&) const;
    std::vector<std::string> makeAsmValue2(SymbolTable&) const;

    std::shared_ptr<Condition> condition;

    friend std::vector<std::string> executeIfCommand(SymbolTable&, const CommandIf&, std::vector<std::shared_ptr<Procedure>>&);
    friend std::vector<std::string> executeIfElseCommand(SymbolTable&, const CommandIfElse&, std::vector<std::shared_ptr<Procedure>>&);
};

struct CommandIfElse : CommandCondition
{
    CommandIfElse(std::shared_ptr<Condition>, std::vector<std::shared_ptr<Command>>, std::vector<std::shared_ptr<Command>>);
    std::string doAsm() const override;
    std::vector<std::string> executeCommand(SymbolTable&, std::vector<std::shared_ptr<Procedure>>&) override;

    std::vector<std::shared_ptr<Command>> commands1;
    std::vector<std::shared_ptr<Command>> commands2;
};

struct CommandIf : CommandCondition
{
    CommandIf(std::shared_ptr<Condition>, std::vector<std::shared_ptr<Command>>);
    std::string doAsm() const override;
    std::vector<std::string> executeCommand(SymbolTable&, std::vector<std::shared_ptr<Procedure>>&) override;

    std::vector<std::shared_ptr<Command>> commands;
};

struct CommandWhile : Command
{
    CommandWhile(std::shared_ptr<Condition>, std::vector<std::shared_ptr<Command>>);
    std::string doAsm() const override;
    std::vector<std::string> executeCommand(SymbolTable&, std::vector<std::shared_ptr<Procedure>>&) override;

    std::shared_ptr<Condition> condition;
    std::vector<std::shared_ptr<Command>> commands;
};

struct CommandRepeat : Command
{
    CommandRepeat(std::vector<std::shared_ptr<Command>>, std::shared_ptr<Condition>);
    std::string doAsm() const override;
    std::vector<std::string> executeCommand(SymbolTable&, std::vector<std::shared_ptr<Procedure>>&) override;

    std::vector<std::shared_ptr<Command>> commands;
    std::shared_ptr<Condition> condition;
};

struct CommandForTo : Command
{
    CommandForTo(std::string, std::shared_ptr<Value>, std::shared_ptr<Value>, std::vector<std::shared_ptr<Command>>);
    std::string doAsm() const override;
    std::vector<std::string> executeCommand(SymbolTable&, std::vector<std::shared_ptr<Procedure>>&) override;

    std::string pid;
    std::shared_ptr<Value> value1;
    std::shared_ptr<Value> value2;
    std::vector<std::shared_ptr<Command>> commands;
};

struct CommandDownTo : Command
{
    CommandDownTo(std::string, std::shared_ptr<Value>, std::shared_ptr<Value>, std::vector<std::shared_ptr<Command>>);
    std::string doAsm() const override;
    std::vector<std::string> executeCommand(SymbolTable&, std::vector<std::shared_ptr<Procedure>>&) override;

    std::string pid;
    std::shared_ptr<Value> value1;
    std::shared_ptr<Value> value2;
    std::vector<std::shared_ptr<Command>> commands;
};

struct CommandProcCall : Command
{
    CommandProcCall(std::shared_ptr<ProcCall>);
    std::string doAsm() const override;
    std::vector<std::string> executeCommand(SymbolTable&, std::vector<std::shared_ptr<Procedure>>&) override;

    std::shared_ptr<ProcCall> procCall;
};

struct CommandRead : Command
{
    CommandRead(std::shared_ptr<Identifier>);
    std::string doAsm() const override;
    std::vector<std::string> executeCommand(SymbolTable&, std::vector<std::shared_ptr<Procedure>>&) override;

    std::shared_ptr<Identifier> identifier;
};

struct CommandWrite : Command
{
    CommandWrite(std::shared_ptr<Value>);
    std::string doAsm() const override;
    std::vector<std::string> executeCommand(SymbolTable&, std::vector<std::shared_ptr<Procedure>>&) override;

    std::shared_ptr<Value> value;
};

std::vector<std::shared_ptr<Command>> makeCommands(std::shared_ptr<Command>);
std::vector<std::shared_ptr<Command>> makeCommands(std::vector<std::shared_ptr<Command>>, std::shared_ptr<Command>);


enum class ProcedureEnum
{
    WITHDECLARATION,
    WITHOUTDECLARATION
};

struct Procedure : Node 
{
    Procedure(std::shared_ptr<ProcHead>, std::vector<std::shared_ptr<Command>>, ProcedureEnum);
    Procedure(std::shared_ptr<ProcHead>, std::vector<std::shared_ptr<Declaration>>, std::vector<std::shared_ptr<Command>>, ProcedureEnum);
    std::string doAsm() const override;
    void fillSymbolTable();

    std::shared_ptr<ProcHead> procHead;
    std::vector<std::shared_ptr<Declaration>> declarations;
    std::vector<std::shared_ptr<Command>> commands;
    ProcedureEnum procEnum;
    SymbolTable symbolTable;
};

std::vector<std::shared_ptr<Procedure>> makeProcedures(
    std::vector<std::shared_ptr<Procedure>>
    , std::shared_ptr<ProcHead>
    , std::vector<std::shared_ptr<Declaration>>
    , std::vector<std::shared_ptr<Command>>
    , ProcedureEnum);


std::vector<std::shared_ptr<Procedure>> makeProcedures(
    std::vector<std::shared_ptr<Procedure>>
    , std::shared_ptr<ProcHead>
    , std::vector<std::shared_ptr<Command>>
    , ProcedureEnum);

std::vector<std::shared_ptr<Procedure>> makeProcedures();


struct Main : Node{
    virtual ~Main() = default;
    virtual void fillSymbolTable() = 0;
    virtual void executeCommand(std::vector<std::shared_ptr<Procedure>>&) = 0;
    std::vector<std::shared_ptr<Command>> commands;
    SymbolTable symbolTable;
};

struct MainWithDecl : Main 
{
    MainWithDecl(std::vector<std::shared_ptr<Declaration>>, std::vector<std::shared_ptr<Command>>);
    std::string doAsm() const override;
    void fillSymbolTable() override;
    void executeCommand(std::vector<std::shared_ptr<Procedure>>&) override;

    std::vector<std::shared_ptr<Declaration>> declarations; 
};

struct MainWithoutDecl : Main 
{
    MainWithoutDecl(std::vector<std::shared_ptr<Command>>);
    std::string doAsm() const override;
    void fillSymbolTable() override;
    void executeCommand(std::vector<std::shared_ptr<Procedure>>&) override;

    
};

void mainProgram(std::vector<std::shared_ptr<Procedure>>&, std::shared_ptr<Main>);










// template <typename... Args>
// std::vector<std::shared_ptr<Declaration>> makeDeclaration(std::vector<std::shared_ptr<Declaration>> vec, const std::string name, Args... args){
//     if(sizeof...(args) == 0) 
//         vec.push_back(std::make_shared<Declaration>(name, DeclarationEnum::PID));
//     else if(sizeof...(args) == 2) 
//         vec.push_back(std::make_shared<Declaration>(name, DeclarationEnum::TABLE, args...));
//     else 
//         throw std::invalid_argument("Invalid number of argument");
//     return vec;
// }