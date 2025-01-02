#pragma once

#include "../../SymbolTable/SymbolTable.hpp"
#include "../../ast/Procedure.hpp"
#include "../../ast/Command.hpp"
#include <memory>
#include <vector>

std::vector<std::string> executeIfCommand(SymbolTable&, const CommandIf&, std::vector<std::shared_ptr<Procedure>>&, bool);