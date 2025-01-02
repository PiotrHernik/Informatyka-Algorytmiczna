#pragma once

#include <string>
#include "Node.hpp"

struct Args : Node
{
    Args(std::string);
    std::string doAsm() const override;

    std::string name;
};

