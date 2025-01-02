#pragma once

#include "../SymbolTable.hpp"
#include "../ast.hpp"
#include <memory>
#include <vector>

std::vector<std::string> executeIfCommand(SymbolTable&, const CommandIf&, std::vector<std::shared_ptr<Procedure>>&);