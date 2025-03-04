#pragma once

#include "Expression.hpp"

class ExpressionWith2Val : public Expression
{
public:
    ExpressionWith2Val(std::shared_ptr<Value>, std::shared_ptr<Value>);
private:
    std::shared_ptr<Value> value2_;
};