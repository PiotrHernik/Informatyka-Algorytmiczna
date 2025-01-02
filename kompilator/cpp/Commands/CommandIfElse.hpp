#pragma once

#include "../SymbolTable.hpp"
#include "../ast.hpp"
#include <memory>
#include <vector>

std::vector<std::string> executeIfElseCommand(SymbolTable&, const CommandIfElse&, std::vector<std::shared_ptr<Procedure>>&);