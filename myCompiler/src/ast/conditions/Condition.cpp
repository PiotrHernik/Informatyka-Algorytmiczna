#include "Condition.hpp"

Condition::Condition(std::shared_ptr<Value> value1, std::shared_ptr<Value> value2) 
    : value1_(value1), value2_(value2) {}

