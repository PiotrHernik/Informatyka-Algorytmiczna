#pragma once

#include <memory>

#include "Value.hpp"

class Expression
{
public:
    Expression(std::shared_ptr<Value>);
    virtual ~Expression() = default;
private:
    std::shared_ptr<Value> value1_;
};

enum class ExpressionEnum
{
    VALUE,
    PLUS,
    MINUS,
    MULT,
    DIV,
    MOD
};