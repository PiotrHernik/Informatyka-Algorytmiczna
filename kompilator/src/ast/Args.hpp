#pragma once

#include <string>
#include "Node.hpp"

struct Args : Node
{
    Args(std::string);
    std::string doAsm() const override;
    void setLocation(int, int) override;

    std::string name;
};

