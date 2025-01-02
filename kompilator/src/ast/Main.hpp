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