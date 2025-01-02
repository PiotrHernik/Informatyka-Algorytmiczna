#pragma once

#include <memory>
#include "../SymbolTable/SymbolTable.hpp"
#include "../ast/Identifier.hpp"
#include "../ast/Enums.hpp"

bool isValidIdentifier(SymbolTable& symbolTable, std::shared_ptr<Identifier> identifier);

