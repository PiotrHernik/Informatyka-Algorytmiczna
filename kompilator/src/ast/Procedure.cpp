#include "Procedure.hpp"
#include <iostream>

Procedure::Procedure(
        std::shared_ptr<ProcHead> procHead, 
        std::vector<std::shared_ptr<Declaration>> declarations, 
        std::vector<std::shared_ptr<Command>> commands,
        ProcedureEnum procEnum)
    : procHead(procHead), declarations(declarations), commands(commands), procEnum(procEnum), symbolTable(SymbolTable(procHead->name))
    {
    }

Procedure::Procedure(
    std::shared_ptr<ProcHead> procHead,
    std::vector<std::shared_ptr<Command>> commands,
    ProcedureEnum procEnum)
: procHead(procHead), declarations({}), commands(commands), procEnum(procEnum), symbolTable(SymbolTable(procHead->name)){}

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

void Procedure::fillArgsAddress(SymbolTable& externSymbolTable, std::shared_ptr<ProcCall> procCall)
{
    for (size_t i = 0; i < procHead->argsDecl.size(); i++)
    {
        auto argProcCall = procCall->args[i];
        auto declArg = procHead->argsDecl[i];
        if (declArg->argsDecEnum == ArgsDeclarationEnum::PID)
        {
            symbolTable.addArgsAddress(declArg->name, externSymbolTable.getPidAddress(argProcCall->name), ArgsDeclarationEnum::PID);
        }
        else
        {
            symbolTable.addArgsAddress(declArg->name, externSymbolTable.getTableAddress(argProcCall->name), ArgsDeclarationEnum::TABLE);
        }
    }
}