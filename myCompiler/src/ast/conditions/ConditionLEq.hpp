#pragma once

#include "Condition.hpp"

class ConditionLEq : public Condition
{
public:
    ConditionLEq(std::shared_ptr<Value>, std::shared_ptr<Value>);
};