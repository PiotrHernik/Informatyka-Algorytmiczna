#pragma once

#include <utility>

#include "Location.hpp"

class Value
{
public:
    Value(const Location&);
    ~Value() = default;

    std::pair<int,int> getLocation() const;
private:
    const Location& location_;
};