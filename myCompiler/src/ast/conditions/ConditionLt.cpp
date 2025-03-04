#include "ConditionLt.hpp"

ConditionLt::ConditionLt(std::shared_ptr<Value> value1, std::shared_ptr<Value> value2)
    : Condition(value1, value2) {}