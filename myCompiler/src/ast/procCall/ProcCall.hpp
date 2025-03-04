#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Location.hpp"
#include "Args.hpp"

class ProcCall
{
public:
    ProcCall(std::string&, std::vector<std::shared_ptr<Args>>, Location&);

    std::pair<int,int> getLocation() const;
private:
    std::string name_;
    std::vector<std::shared_ptr<Args>> args_;
    Location location_;
};