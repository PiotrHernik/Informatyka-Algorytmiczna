#pragma once

#include "expressions/ExpressionWith2Val.hpp"

class ExpressionMinus : public ExpressionWith2Val
{
public:
    ExpressionMinus(std::shared_ptr<Value>, std::shared_ptr<Value>);
};