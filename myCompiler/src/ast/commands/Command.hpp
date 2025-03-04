#pragma once

#include "Location.hpp"

class Command
{
public:
    Command(const Location&);
private:
    Location location_;
};