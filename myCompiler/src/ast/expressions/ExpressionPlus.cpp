#include "expressions/ExpressionPlus.hpp"

ExpressionPlus::ExpressionPlus(std::shared_ptr<Value> value1, std::shared_ptr<Value> value2)
    : ExpressionWith2Val(value1, value2) {}