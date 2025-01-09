#include "Procedure.hpp"
#include <iostream>

Procedure::Procedure(
        std::shared_ptr<ProcHead> procHead, 
        std::vector<std::shared_ptr<Declaration>> declarations, 
        std::vector<std::shared_ptr<Command>> commands,
        ProcedureEnum procEnum)
    : procHead(procHead), declarations(declarations), commands(commands), procEnum(procEnum), symbolTable(SymbolTable(procHead->name))
    {
        rntrAddress = symbolTable.getFirstFreeAddress();
        symbolTable.increaseFirstFreeAddress();
    }

Procedure::Procedure(
    std::shared_ptr<ProcHead> procHead,
    std::vector<std::shared_ptr<Command>> commands,
    ProcedureEnum procEnum)
    : procHead(procHead), declarations({}), commands(commands), procEnum(procEnum), symbolTable(SymbolTable(procHead->name))
    {
        rntrAddress = symbolTable.getFirstFreeAddress();
        symbolTable.increaseFirstFreeAddress();
    }

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
    std::cout << "DUPAA: " << procCall->name <<std::endl;
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

int Procedure::countAsmCommand(std::vector<std::shared_ptr<Procedure>>& procedures)
{
    std::vector<std::string> tempCommands;
    std::unordered_map<std::string, std::pair<int, int>> fakeMap;

    for(auto& comm : commands)
    {
        auto tempVec = comm->executeCommand(symbolTable, procedures, fakeMap);
        tempCommands.insert(tempCommands.end(), tempVec.begin(), tempVec.end());
    }
    // Will be add RTNR, that's why +1
    return tempCommands.size() + 1;
}

std::vector<std::string> Procedure::executeCommand(std::vector<std::shared_ptr<Procedure>>& procedures, 
        std::unordered_map<std::string, std::pair<int, int>> procedureStartEndInAssembly,
        int howManyAsmCommand) 
{
    std::vector<std::string> asmCommands;

    for(auto& comm : commands)
    {
        auto tempVec = comm->executeCommand(symbolTable, procedures, procedureStartEndInAssembly, howManyAsmCommand + asmCommands.size());
        asmCommands.insert(asmCommands.end(), tempVec.begin(), tempVec.end());
    }

    asmCommands.push_back("    RTRN " + std::to_string(rntrAddress));

    return asmCommands;
}
