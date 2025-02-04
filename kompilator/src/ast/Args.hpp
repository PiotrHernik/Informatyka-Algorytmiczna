#pragma once

#include <string>
#include "Node.hpp"

struct Args : Node
{
    Args(std::string);
    void setLocation(int, int) override;

    std::string name;
};

