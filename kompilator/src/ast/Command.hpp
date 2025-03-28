#pragma once

#include <string>
#include <vector>
#include "memory"

#include "Node.hpp"
#include "Procedure.hpp"
#include "Expression.hpp"
#include "Condition.hpp"
#include "../SymbolTable/SymbolTable.hpp"
#include "Identifier.hpp"
#include "ProcCall.hpp"
#include "Enums.hpp"

struct CommandIf;
struct CommandIfElse;

struct Command : Node
{
    virtual std::vector<std::string> executeCommand(SymbolTable&, std::vector<std::shared_ptr<Procedure>>&, std::unordered_map<std::string, std::pair<int, int>>, int = 0, bool = false) = 0;
    DeclarationEnum convertIdEnToDeclEn(IdentifierEnum&);
    virtual ~Command() = default;
    virtual bool isMultiplication() = 0;
    virtual bool isDivOrMod() = 0;
    virtual std::string ifIsProcCallGetName() = 0;
    void setLocation(int, int) override;

    CommandEnum commandEnum;
};


struct CommandAssign : Command
{
    CommandAssign(std::shared_ptr<Identifier>, std::shared_ptr<Expression>);
    std::vector<std::string> executeCommand(SymbolTable&, std::vector<std::shared_ptr<Procedure>>&, std::unordered_map<std::string, std::pair<int, int>>, int = 0, bool = false) override;
    bool isMultiplication() override;
    bool isDivOrMod() override;
    std::string ifIsProcCallGetName() override;

    std::shared_ptr<Identifier> identifier;
    std::shared_ptr<Expression> expression;
    static const int multiplyAsmCommandSize = 0;
};

struct CommandCondition : Command
{
protected:

    std::shared_ptr<Condition> condition;
};

struct CommandIfElse : CommandCondition
{
    CommandIfElse(std::shared_ptr<Condition>, std::vector<std::shared_ptr<Command>>, std::vector<std::shared_ptr<Command>>);
    std::vector<std::string> executeCommand(SymbolTable&, std::vector<std::shared_ptr<Procedure>>&, std::unordered_map<std::string, std::pair<int, int>>, int = 0, bool = false) override;
    bool isMultiplication() override;
    bool isDivOrMod() override;
    std::string ifIsProcCallGetName() override;

    std::vector<std::shared_ptr<Command>> commands1;
    std::vector<std::shared_ptr<Command>> commands2;
};

struct CommandIf : CommandCondition
{
    CommandIf(std::shared_ptr<Condition>, std::vector<std::shared_ptr<Command>>);
    std::vector<std::string> executeCommand(SymbolTable&, std::vector<std::shared_ptr<Procedure>>&, std::unordered_map<std::string, std::pair<int, int>>, int = 0, bool = false) override;
    bool isMultiplication() override;
    bool isDivOrMod() override;
    std::string ifIsProcCallGetName() override;

    std::vector<std::shared_ptr<Command>> commands;
};

struct CommandWhile : CommandCondition
{
    CommandWhile(std::shared_ptr<Condition>, std::vector<std::shared_ptr<Command>>);
    std::vector<std::string> executeCommand(SymbolTable&, std::vector<std::shared_ptr<Procedure>>&, std::unordered_map<std::string, std::pair<int, int>>, int = 0, bool = false) override;
    bool isMultiplication() override;
    bool isDivOrMod() override;
    std::string ifIsProcCallGetName() override;

    std::vector<std::shared_ptr<Command>> commands;
};

struct CommandRepeat : CommandCondition
{
    CommandRepeat(std::vector<std::shared_ptr<Command>>, std::shared_ptr<Condition>);
    std::vector<std::string> executeCommand(SymbolTable&, std::vector<std::shared_ptr<Procedure>>&, std::unordered_map<std::string, std::pair<int, int>>, int = 0, bool = false) override;
    bool isMultiplication() override;
    bool isDivOrMod() override;
    std::string ifIsProcCallGetName() override;

    std::vector<std::shared_ptr<Command>> commands;
};

struct CommandForTo : Command
{
    CommandForTo(std::string, std::shared_ptr<Value>, std::shared_ptr<Value>, std::vector<std::shared_ptr<Command>>);
    std::vector<std::string> executeCommand(SymbolTable&, std::vector<std::shared_ptr<Procedure>>&, std::unordered_map<std::string, std::pair<int, int>>, int = 0, bool = false) override;
    bool isMultiplication() override;
    bool isDivOrMod() override;
    std::string ifIsProcCallGetName() override;

    std::string pid;
    std::shared_ptr<Value> value1;
    std::shared_ptr<Value> value2;
    std::vector<std::shared_ptr<Command>> commands;
};

struct CommandDownTo : Command
{
    CommandDownTo(std::string, std::shared_ptr<Value>, std::shared_ptr<Value>, std::vector<std::shared_ptr<Command>>);
    std::vector<std::string> executeCommand(SymbolTable&, std::vector<std::shared_ptr<Procedure>>&, std::unordered_map<std::string, std::pair<int, int>>, int = 0, bool = false) override;
    bool isMultiplication() override;
    bool isDivOrMod() override;
    std::string ifIsProcCallGetName() override;

    std::string pid;
    std::shared_ptr<Value> value1;
    std::shared_ptr<Value> value2;
    std::vector<std::shared_ptr<Command>> commands;
};

struct CommandProcCall : Command
{
    CommandProcCall(std::shared_ptr<ProcCall>);
    std::vector<std::string> executeCommand(SymbolTable&, std::vector<std::shared_ptr<Procedure>>&, std::unordered_map<std::string, std::pair<int, int>>, int = 0, bool = false) override;
    std::string getProcedureName() const;
    bool isValidDeclared(SymbolTable& symbolTable, std::vector<std::shared_ptr<Procedure>>& procedures, std::string procCallName);
    bool areArgsValid(SymbolTable& symbolTable, 
                    std::vector<std::shared_ptr<Procedure>>& procedures, 
                    std::string procCallName, 
                    std::vector<std::shared_ptr<Args>> args);
    bool isMultiplication() override;
    bool isDivOrMod() override;
    std::string ifIsProcCallGetName() override;

    std::shared_ptr<ProcCall> procCall;
};

struct CommandRead : Command
{
    CommandRead(std::shared_ptr<Identifier>);
    std::vector<std::string> executeCommand(SymbolTable&, std::vector<std::shared_ptr<Procedure>>&, std::unordered_map<std::string, std::pair<int, int>>, int = 0, bool = false) override;
    bool isMultiplication() override;
    bool isDivOrMod() override;
    std::string ifIsProcCallGetName() override;

    std::shared_ptr<Identifier> identifier;
};

struct CommandWrite : Command
{
    CommandWrite(std::shared_ptr<Value>);
    std::vector<std::string> executeCommand(SymbolTable&, std::vector<std::shared_ptr<Procedure>>&, std::unordered_map<std::string, std::pair<int, int>>, int = 0, bool = false) override;
    bool isMultiplication() override;
    bool isDivOrMod() override;
    std::string ifIsProcCallGetName() override;
    
    std::shared_ptr<Value> value;
};