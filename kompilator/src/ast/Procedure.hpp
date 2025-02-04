#pragma once


#include <string>
#include <vector>
#include <memory>

#include "Node.hpp"
#include "ProcHead.hpp"
#include "Enums.hpp"
#include "Command.hpp"
#include "Declaration.hpp"
#include "ProcCall.hpp"
#include "../SymbolTable/SymbolTable.hpp"

struct Command;
struct Declaration;


struct Procedure : Node 
{
    Procedure(std::shared_ptr<ProcHead>, std::vector<std::shared_ptr<Command>>, ProcedureEnum);
    Procedure(std::shared_ptr<ProcHead>, std::vector<std::shared_ptr<Declaration>>, std::vector<std::shared_ptr<Command>>, ProcedureEnum);
    void fillSymbolTable();
    void fillArgsAddress(SymbolTable&, std::shared_ptr<ProcCall>);
    std::vector<std::string> executeCommand(std::vector<std::shared_ptr<Procedure>>&, std::unordered_map<std::string, std::pair<int, int>>, int);
    std::vector<std::string> getProceduresNameCalled() const;
    int countAsmCommand(std::vector<std::shared_ptr<Procedure>>&);
    bool isMultiplication();
    bool isDivOrMod();
    void setLocation(int, int) override;

    std::shared_ptr<ProcHead> procHead;
    std::vector<std::shared_ptr<Declaration>> declarations;
    std::vector<std::shared_ptr<Command>> commands;
    ProcedureEnum procEnum;
    SymbolTable symbolTable;
    long long rntrAddress;
};