#pragma once

#include "Condition.hpp"

class ConditionEq : public Condition
{
public:
    ConditionEq(std::shared_ptr<Value>, std::shared_ptr<Value>);
};