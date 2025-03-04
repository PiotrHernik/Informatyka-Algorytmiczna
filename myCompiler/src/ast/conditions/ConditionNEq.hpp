#pragma once

#include "Condition.hpp"

class ConditionNEq : public Condition
{
public:
    ConditionNEq(std::shared_ptr<Value>, std::shared_ptr<Value>);
};