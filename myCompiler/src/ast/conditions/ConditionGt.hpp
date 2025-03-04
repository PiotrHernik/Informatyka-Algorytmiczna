#pragma once

#include "Condition.hpp"

class ConditionGt : public Condition
{
public:
    ConditionGt(std::shared_ptr<Value>, std::shared_ptr<Value>);
};