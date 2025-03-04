#include "expressions/ExpressionWith2Val.hpp"

ExpressionWith2Val::ExpressionWith2Val(std::shared_ptr<Value> value1, std::shared_ptr<Value> value2)
    : Expression(value1), value2_(value2) {}

    