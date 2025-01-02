#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Node.hpp"
#include "Args.hpp"

struct ProcCall : Node 
{
    ProcCall(std::string, std::vector<std::shared_ptr<Args>>);
    std::string doAsm() const override;

    std::string name;
    std::vector<std::shared_ptr<Args>> args;
};