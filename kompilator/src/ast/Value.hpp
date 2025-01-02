#pragma once


#include <string>
#include <vector>
#include <memory>

#include "Node.hpp"
#include "Enums.hpp"
#include "../SymbolTable/SymbolTable.hpp"
#include "Identifier.hpp"

struct Value : Node 
{
    Value(std::shared_ptr<Identifier>, ValueEnum);
    Value(long long, ValueEnum);
    std::string doAsm() const override;
    ValueEnum valEnum;
    std::shared_ptr<Identifier> identifier;
    long long value;
};