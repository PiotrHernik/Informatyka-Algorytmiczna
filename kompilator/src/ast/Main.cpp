#include <iostream>

#include "Main.hpp"

MainWithDecl::MainWithDecl(std::vector<std::shared_ptr<Declaration>> declarations, std::vector<std::shared_ptr<Command>> commands)
    : declarations(declarations)
{
    this->commands = commands;
    this->symbolTable = SymbolTable("Main");
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
    std::string membership("Main");
    this->commands = commands;
    this->symbolTable = SymbolTable(membership);
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