#include <algorithm>
#include <iostream>

#include "Main.hpp"
#include "Enums.hpp"
#include "../functions/arithmetics.hpp"
#include "../ErrorClass/Error.hpp"

MainWithDecl::MainWithDecl(std::vector<std::shared_ptr<Declaration>> declarations, std::vector<std::shared_ptr<Command>> commands)
    : declarations(declarations)
{
    this->commands = commands;
    this->symbolTable = SymbolTable("Main");
}

std::string MainWithDecl::doAsm() const 
{
    for(auto comm : commands)
    {
        comm->doAsm();
    }
    return std::string("MainwithDecl");
}

void MainWithDecl::fillSymbolTable() {
    for (const auto& decl : declarations) {
        symbolTable.addDeclarations(decl);
    }
}

    

void Main::executeCommand(std::vector<std::shared_ptr<Procedure>>& procedures)
{
    std::unordered_map<std::string, std::pair<int, int>> procedureStartEndInAssembly;
    std::vector<std::string> allCommands;
    std::vector<std::string> procedureCommands;
    std::vector<std::string> mainCommands;
    int asmCommandsInProcedures = 0;

    if (areMuliplyProcedure(procedures))
    {
        std::string errMsg = "There are few procedures with the same name";
        Error err(errMsg);
        err.notifyError();
    }

    auto proceduresCallInMain = findProcedureCallName();
    auto proceduresGraph = makeProceduresGraph(procedures, proceduresCallInMain);

    bool isMultiply = false;
    bool isDivOrMod = false;
    //counting asmCommand in procedures
    for (auto& procName : proceduresGraph)
    {
        const auto& it = std::find_if(procedures.begin(), procedures.end(), [&procName](std::shared_ptr<Procedure> proc){ return procName == proc->procHead->name; });
        auto&& amountAsmCmndInProc = (*it)->countAsmCommand(procedures);
        procedureStartEndInAssembly.insert({(*it)->procHead->name, std::make_pair<int, int>(asmCommandsInProcedures + 1, asmCommandsInProcedures + amountAsmCmndInProc)});
        asmCommandsInProcedures += amountAsmCmndInProc;

        if ((*it)->isMultiplication())
        {
            isMultiply = true;
        }
        if ((*it)->isDivOrMod())
        {
            isDivOrMod = true;
        }
    }

    for(auto& command : commands)
    {
        if (command->isMultiplication())
        {
            isMultiply = true;
        }
        if (command->isDivOrMod())
        {
            isDivOrMod = true;
        }
    }

    if (isMultiply)
    {
        Arithmetics::rtntAddressMultiply = symbolTable.getFirstFreeAddress();
        symbolTable.increaseFirstFreeAddress();
        procedureStartEndInAssembly.insert({"multiply", std::make_pair<int, int>(asmCommandsInProcedures + 1, asmCommandsInProcedures +  Arithmetics::asmMultiplySize)});
        asmCommandsInProcedures += Arithmetics::asmMultiplySize;
    }
    if (isDivOrMod)
    {
        Arithmetics::rtntAddressDivide = symbolTable.getFirstFreeAddress();
        symbolTable.increaseFirstFreeAddress();
        procedureStartEndInAssembly.insert({"divide", std::make_pair<int, int>(asmCommandsInProcedures + 1, asmCommandsInProcedures +  Arithmetics::asmDivideSize)});
        asmCommandsInProcedures += Arithmetics::asmDivideSize;
    }

    // executeing commands in program
    for(auto& command : commands)
    {
        auto tempVec = command->executeCommand(symbolTable, procedures, procedureStartEndInAssembly, asmCommandsInProcedures + mainCommands.size());
        mainCommands.insert(mainCommands.end(), std::make_move_iterator(tempVec.begin()), std::make_move_iterator(tempVec.end()));
    }

    // executing commands in procedures
    for(auto& proc : proceduresGraph)
    {
        const auto& it = std::find_if(procedures.begin(), procedures.end(), [&proc](std::shared_ptr<Procedure> procedure){ return procedure->procHead->name == proc; });
        auto&& tempVec = (*it)->executeCommand(procedures, procedureStartEndInAssembly, procedureStartEndInAssembly[(*it)->procHead->name].first - 1);
        procedureCommands.insert(procedureCommands.end(), std::make_move_iterator(tempVec.begin()), std::make_move_iterator(tempVec.end()));
    }


    if (isMultiply)
    {
        auto tempVec = Arithmetics::multiply();
        procedureCommands.insert(procedureCommands.end(), std::make_move_iterator(tempVec.begin()), std::make_move_iterator(tempVec.end()));
    }
    if (isDivOrMod)
    {
        auto tempVec = Arithmetics::divide();
        procedureCommands.insert(procedureCommands.end(), std::make_move_iterator(tempVec.begin()), std::make_move_iterator(tempVec.end()));
    }
    

    allCommands.push_back("    JUMP " + std::to_string(procedureCommands.size() + 1)); // jump after procedures - it is first command

    allCommands.insert(allCommands.end(), std::make_move_iterator(procedureCommands.begin()), std::make_move_iterator(procedureCommands.end()));
    allCommands.insert(allCommands.end(), std::make_move_iterator(mainCommands.begin()), std::make_move_iterator(mainCommands.end()));
    



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

bool Main::areMuliplyProcedure(std::vector<std::shared_ptr<Procedure>>& procedures) const
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

std::vector<std::string> Main::findProcedureCallName() const
{
    std::vector<std::string> proceduresCallInMain;

    for(const auto& command : commands)
    {
        auto procCallName = command->ifIsProcCallGetName();
        if (procCallName != "")
        {
            if (std::find(proceduresCallInMain.begin(), proceduresCallInMain.end(), procCallName) == proceduresCallInMain.end())
                proceduresCallInMain.emplace_back(procCallName);
        }
    }
    return proceduresCallInMain;
}

std::vector<std::string> Main::makeProceduresGraph(std::vector<std::shared_ptr<Procedure>>& procedures, std::vector<std::string>& proceduresInMain) const
{
    std::vector<std::string> proceduresGraph(proceduresInMain);
    for(auto i = 0; i < proceduresGraph.size(); i++)
    {
        auto& procInMain = proceduresGraph[i];
        auto it = std::find_if(procedures.begin(), procedures.end(), [&procInMain](std::shared_ptr<Procedure> proc){ return procInMain ==  proc->procHead->name; });
        if (it == procedures.end())
        {
            std::string errMsg = "there is no procedure with that name " + procInMain;
            Error err(errMsg);
            err.notifyError();
        }
        auto&& proceduresCalledInProcedure = (*it)->getProceduresNameCalled();
        
        for(auto& procName : proceduresCalledInProcedure)
        {
            if (std::find(proceduresGraph.begin(), proceduresGraph.end(), procName) == proceduresGraph.end())
            {
                proceduresGraph.emplace_back(procName);
            }
        }

    }

    return proceduresGraph;
}

void Main::setLocation(int lin, int col)
{
    line = lin;
    column = col;
}

