#include <algorithm>
#include <iostream>

#include "Main.hpp"
#include "Enums.hpp"

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
    std::unordered_map<std::string, std::pair<int, int>> procedureStartEndInAssembly;
    std::vector<std::string> allCommands;
    std::vector<std::string> procedureCommands;
    std::vector<std::string> mainCommands;
    int asmCommandsInProcedures = 0;

    if (areMuliplyProcedure(procedures))
    {
        throw std::invalid_argument("The are few procedures with the same name");
    }

    for (auto& proc : procedures)
    {
        auto temp = proc->countAsmCommand(procedures);
        procedureStartEndInAssembly.insert({proc->procHead->name, std::make_pair<int, int>(asmCommandsInProcedures + 1, asmCommandsInProcedures + temp)});
        asmCommandsInProcedures += temp;
    }

    std::cout << " PO liczeniu____" <<std::endl;

    for(auto& command : commands)
    {
        auto tempVector = command->executeCommand(symbolTable, procedures, procedureStartEndInAssembly, asmCommandsInProcedures + mainCommands.size());
        mainCommands.insert(mainCommands.end(), tempVector.begin(), tempVector.end());
    }

    for(auto& proc : procedures)
    {
        auto tempVec = proc->executeCommand(procedures, procedureStartEndInAssembly, procedureStartEndInAssembly[proc->procHead->name].first - 1);
        procedureCommands.insert(procedureCommands.end(), tempVec.begin(), tempVec.end());
    }

    allCommands.push_back("    JUMP " + std::to_string(procedureCommands.size() + 1)); // jump after procedures - it is first command

    allCommands.insert(allCommands.end(), procedureCommands.begin(), procedureCommands.end());
    allCommands.insert(allCommands.end(), mainCommands.begin(), mainCommands.end());
    



    for (auto& line : allCommands)
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
    std::unordered_map<std::string, std::pair<int, int>> procedureStartEndInAssembly;
    std::vector<std::string> allCommands;
    std::vector<std::string> procedureCommands;
    std::vector<std::string> mainCommands;
    int asmCommandsInProcedures = 0;

    if (areMuliplyProcedure(procedures))
    {
        throw std::invalid_argument("The are few procedures with the same name");
    }

    for (auto& proc : procedures)
    {
        auto temp = proc->countAsmCommand(procedures);
        procedureStartEndInAssembly.insert({proc->procHead->name, std::make_pair<int, int>(asmCommandsInProcedures + 1, asmCommandsInProcedures + temp)});
        asmCommandsInProcedures += temp;
    }

    for(auto& command : commands)
    {
        auto tempVector = command->executeCommand(symbolTable, procedures, procedureStartEndInAssembly, asmCommandsInProcedures + mainCommands.size());
        mainCommands.insert(mainCommands.end(), tempVector.begin(), tempVector.end());
    }

    for(auto& proc : procedures)
    {
        auto tempVec = proc->executeCommand(procedures, procedureStartEndInAssembly, procedureStartEndInAssembly[proc->procHead->name].first - 1);
        procedureCommands.insert(procedureCommands.end(), tempVec.begin(), tempVec.end());
    }

    allCommands.push_back("    JUMP " + std::to_string(procedureCommands.size() + 1)); // jump after procedures - it is first command

    allCommands.insert(allCommands.end(), procedureCommands.begin(), procedureCommands.end());
    allCommands.insert(allCommands.end(), mainCommands.begin(), mainCommands.end());
    



    for (auto& line : allCommands)
    {
        symbolTable.outputFile << line << std::endl;
    }
    symbolTable.outputFile << "    HALT" << std::endl;
}

bool Main::areMuliplyProcedure(std::vector<std::shared_ptr<Procedure>>& procedures)
{
    for(auto i = 0; i < procedures.size(); i++)
    {
        auto proc = procedures[i];
        auto it = std::find(procedures.begin(), procedures.end(), proc);
        if (std::find(it+1, procedures.end(), proc) != procedures.end())
        {
            return true;
        } 
    }

    return false;
}