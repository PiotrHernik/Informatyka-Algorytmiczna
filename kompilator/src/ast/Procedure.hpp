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
    std::string doAsm() const override;
    void fillSymbolTable();
    void fillArgsAddress(SymbolTable&, std::shared_ptr<ProcCall>);

    std::shared_ptr<ProcHead> procHead;
    std::vector<std::shared_ptr<Declaration>> declarations;
    std::vector<std::shared_ptr<Command>> commands;
    ProcedureEnum procEnum;
    SymbolTable symbolTable;
};