#include "Condition.hpp"

Condition::Condition(std::shared_ptr<Value> val1, std::shared_ptr<Value> val2, ConditionEnum condEnum) 
    : value1(std::move(val1)), value2(std::move(val2)), condEnum(condEnum){}

std::string Condition::doAsm() const{
    return std::string("Condition");
}