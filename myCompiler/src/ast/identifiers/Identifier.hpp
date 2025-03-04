#pragma once

#include <string>
#include <vector>

#include "Location.hpp"

class Identifier
{
public: 
    Identifier(const std::string&, const Location&);
    virtual ~Identifier() = default;

    virtual std::vector<std::string> getAddress() const = 0;
    
    const std::string& getName() const;
    std::pair<int,int> getLocation() const;

protected:
    const std::string name_;
    const Location location_;
};