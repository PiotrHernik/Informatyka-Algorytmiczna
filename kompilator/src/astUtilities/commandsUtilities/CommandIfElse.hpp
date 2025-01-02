#pragma once

#include "../../SymbolTable/SymbolTable.hpp"
#include "../../ast/Procedure.hpp"
#include "../../ast/Command.hpp"
#include <memory>
#include <vector>

std::vector<std::string> executeIfElseCommand(SymbolTable&, const CommandIfElse&, std::vector<std::shared_ptr<Procedure>>&, bool);