#pragma once


#include <string>
#include <vector>
#include <memory>

#include "Node.hpp"
#include "Procedure.hpp"
#include "Enums.hpp"
#include "Command.hpp"
#include "Declaration.hpp"

struct Main : Node{
    virtual ~Main() = default;
    virtual void fillSymbolTable() = 0;
    virtual void executeCommand(std::vector<std::shared_ptr<Procedure>>&);
    bool areMuliplyProcedure(std::vector<std::shared_ptr<Procedure>>&) const;
    void setLocation(int, int) override;
    std::vector<std::string> findProcedureCallName() const;
    std::vector<std::string> makeProceduresGraph(std::vector<std::shared_ptr<Procedure>>&, std::vector<std::string>&) const;
    std::vector<std::shared_ptr<Command>> commands;
    SymbolTable symbolTable;
};

struct MainWithDecl : Main 
{
    MainWithDecl(std::vector<std::shared_ptr<Declaration>>, std::vector<std::shared_ptr<Command>>);
    void fillSymbolTable() override;

    std::vector<std::shared_ptr<Declaration>> declarations; 
};

struct MainWithoutDecl : Main 
{
    MainWithoutDecl(std::vector<std::shared_ptr<Command>>);
    void fillSymbolTable() override;
    
};