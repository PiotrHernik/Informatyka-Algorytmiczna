#pragma once

#include <string>
#include <iostream>
#include <variant>
#include <vector>

enum IdentifierEnum {
    Pid,
    PidTnum,
    PidTpid
};

struct Identifier
{
    Identifier(std::string name, IdentifierEnum idEnum) : name(name), idEnum(idEnum){}
    std::string name;
    IdentifierEnum idEnum;
};

// struct IdentifierOnly : Identifier{};

// struct IdentifierTNum : Identifier{};

// struct IdentifierTPid : Identifier{};

enum ValueEnum {
    NUM,
    Identif
};

struct Value{
    Value(ValueEnum valEnum) : valEnum(valEnum){}
    ValueEnum valEnum;
};

// struct ValueNum : Value{};

// struct ValueIdent : Value{};

enum ConditionEnum {
    CEQ,
    CNEQ,
    CMORE,
    CLESS,
    CMEQ,
    CLEQ
};

struct Condition {
    Condition(ConditionEnum en) : condEnum(en){}
    ConditionEnum condEnum;

};

// struct ConditionEQ : Condition {};

// struct ConditionNEQ : Condition {};

// struct ConditionMore : Condition {};

// struct ConditionLess : Condition {};

// struct ConditionMEQ : Condition {};

// struct ConditionLEQ : Condition {};

enum ExpressionEnum{
    EVALUE,
    EPLUS,
    EMINUS,
    EMULT,
    EDIV,
    EMOD
};

struct Expression {
    Expression(ExpressionEnum expEnum) : expEnum(expEnum){}
    ExpressionEnum expEnum;
};

// struct ExpressionValue : Expression {};

// struct ExpressionPlus : Expression {};

// struct ExpressionMinus : Expression {};

// struct ExpressionMult : Expression {};

// struct ExpressionDiv : Expression {};

// struct ExpressionMod : Expression {};

enum DeclarationEnum {
    PID,
    PIDT
};

struct Declaration {
    Declaration(DeclarationEnum decEnum) : decEnum(decEnum){}
    DeclarationEnum decEnum;
};

enum ProcedureEnum{
    WITHDECLARATION,
    WITHOUTPROCEDURE
};

struct Procedure {
    Procedure(ProcedureEnum procEnum) : procEnum(procEnum){}
    ProcedureEnum procEnum;
    std::vector<Declaration> declarations;
};

enum MainEnum{
    WITHDEC,
    WITHOUT
};

struct SMain{
    SMain(MainEnum mainEnum) : mainEnum(mainEnum){}
    MainEnum mainEnum;
};



struct ProgramAll {
    std::vector<Procedure> procedures;

};

struct Command {};


struct CommandAssign : Command {};
struct CommandIfElse : Command {};
struct CommandIf : Command {};
struct CommandWhile : Command {};
struct CommandRepeat : Command {};
struct CommandForTo : Command {};
struct CommandForDownto : Command {};
struct CommandProcCall : Command {};
struct CommandRead : Command {};
struct CommandWrite : Command {};

enum ArgsDeclarationEnum {
    PIDENTIFIER,
    PIDENTIFIERT
};

struct ArgsDeclaration {
    ArgsDeclaration(ArgsDeclarationEnum argsDecEnum) : argsDecEnum(argsDecEnum){}
    ArgsDeclarationEnum argsDecEnum;
};

struct ProcedureHead {
    std::vector<ArgsDeclaration> argsDecs;
};


