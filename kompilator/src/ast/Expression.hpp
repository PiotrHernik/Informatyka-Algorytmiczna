#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Node.hpp"
#include "Enums.hpp"
#include "Value.hpp"

struct Expression : Node 
{
    Expression(std::shared_ptr<Value>, ExpressionEnum);
    Expression(std::shared_ptr<Value>, std::shared_ptr<Value>, ExpressionEnum);
    std::string doAsm() const override;
    void setLocation(int, int) override;

    std::shared_ptr<Value> value1;
    std::shared_ptr<Value> value2;
    ExpressionEnum expEnum;
};