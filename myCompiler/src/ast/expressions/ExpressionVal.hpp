#pragma once

#include "Expression.hpp"

class ExpressionVal : public Expression
{
public:
    ExpressionVal(std::shared_ptr<Value>);
};