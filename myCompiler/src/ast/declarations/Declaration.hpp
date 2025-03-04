#pragma once

#include <string>
#include <utility>

#include "Location.hpp"

class Declaration 
{
public:
    Declaration(const std::string&, const Location&);
    virtual ~Declaration() = default;
    std::pair<int,int> getLocation() const; 
private:
    const std::string name_;
    const Location location_;
};