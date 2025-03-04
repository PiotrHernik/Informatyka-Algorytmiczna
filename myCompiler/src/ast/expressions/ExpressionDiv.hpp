#pragma once

#include "expressions/ExpressionWith2Val.hpp"

class ExpressionDiv : public ExpressionWith2Val
{
public:
    ExpressionDiv(std::shared_ptr<Value>, std::shared_ptr<Value>);
};