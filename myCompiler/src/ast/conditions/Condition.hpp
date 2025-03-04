#pragma once

#include <string>
#include <memory>

#include "Value.hpp"

class Condition 
{
public:
    Condition(std::shared_ptr<Value> value1, std::shared_ptr<Value> value2);
    virtual ~Condition() = default;
private:  
    std::shared_ptr<Value> value1_;
    std::shared_ptr<Value> value2_;
    // bool conditionResult_;
};