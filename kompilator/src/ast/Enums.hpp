#pragma once

enum class IdentifierEnum {
    PID,
    PIDT,
    PIDTPID
};

enum class ArgsDeclarationEnum 
{
    PID,
    TABLE
};

enum class ValueEnum 
{
    NUM,
    ID
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

enum class ExpressionEnum
{
    VALUE,
    PLUS,
    MINUS,
    MULT,
    DIV,
    MOD
};


enum class DeclarationEnum
{
    PID,
    TABLE
};

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


enum class ProcedureEnum
{
    WITHDECLARATION,
    WITHOUTDECLARATION
};

