#pragma once

#include "../SymbolTable.hpp"
#include "../ast.hpp"
#include <memory>
#include <vector>

std::vector<std::string> executeIfElseCommand(SymbolTable& symbolTable, 
                                            std::vector<std::shared_ptr<Command>>& commands1, 
                                            std::vector<std::shared_ptr<Command>>& commands2,
                                            std::vector<std::shared_ptr<Procedure>>& procedures);