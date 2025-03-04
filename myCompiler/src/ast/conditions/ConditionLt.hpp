#pragma once

#include "Condition.hpp"

class ConditionLt : public Condition
{
public:
    ConditionLt(std::shared_ptr<Value>, std::shared_ptr<Value>);
};