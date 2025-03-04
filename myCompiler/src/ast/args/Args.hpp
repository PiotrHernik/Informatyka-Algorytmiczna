#pragma once

#include <string>
#include <utility>

#include "Location.hpp"

/*
    arguments in procCall
*/
class Args
{
public:
    Args(const std::string&, const Location&);

    const std::string& getName() const;
    std::pair<int, int> getLocation() const;
private:
    const std::string& name_;
    const Location& location_;
};

