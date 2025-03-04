#pragma once

#include "expressions/ExpressionWith2Val.hpp"

class ExpressionPlus : public ExpressionWith2Val
{
public:
    ExpressionPlus(std::shared_ptr<Value>, std::shared_ptr<Value>);
};