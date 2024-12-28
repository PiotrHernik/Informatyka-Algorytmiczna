#pragma once

#include "../SymbolTable.hpp"
#include "../ast.hpp"
#include <memory>
#include <vector>

std::vector<std::string> executeIfCommand(SymbolTable& symbolTable, 
                                        std::vector<std::shared_ptr<Command>>& commands, 
                                        std::vector<std::shared_ptr<Procedure>>& procedures);