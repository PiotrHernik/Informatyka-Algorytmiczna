#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Node.hpp"
#include "Enums.hpp"
#include "Value.hpp"

struct Condition : Node 
{
    Condition(std::shared_ptr<Value> value1, std::shared_ptr<Value> value2, ConditionEnum condEnum);
    std::string doAsm() const override;
    
    ConditionEnum condEnum;
    std::shared_ptr<Value> value1;
    std::shared_ptr<Value> value2;
    bool conditionResult;
};