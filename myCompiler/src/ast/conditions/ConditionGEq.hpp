#pragma once

#include "Condition.hpp"

class ConditionGEq : public Condition
{
public:
    ConditionGEq(std::shared_ptr<Value>, std::shared_ptr<Value>);
};