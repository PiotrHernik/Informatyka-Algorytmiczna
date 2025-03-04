#pragma once

#include "expressions/ExpressionWith2Val.hpp"

class ExpressionMod : public ExpressionWith2Val
{
public:
    ExpressionMod(std::shared_ptr<Value>, std::shared_ptr<Value>);
};