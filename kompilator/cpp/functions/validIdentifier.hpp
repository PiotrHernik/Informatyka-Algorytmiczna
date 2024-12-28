#pragma once

#include "../SymbolTable.hpp"
#include "../ast.hpp"
#include <memory>

bool isValidIdentifier(SymbolTable& symbolTable, std::shared_ptr<Identifier> identifier);

