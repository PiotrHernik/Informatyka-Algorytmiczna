#pragma once

#include "expressions/ExpressionWith2Val.hpp"

class ExpressionMult : public ExpressionWith2Val
{
public:
    ExpressionMult(std::shared_ptr<Value>, std::shared_ptr<Value>);
};