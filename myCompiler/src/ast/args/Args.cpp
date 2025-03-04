#include "Args.hpp"

Args::Args(const std::string& name, const Location& loc) : name_(name), location_(loc) {}

const std::string& Args::getName() const
{
    return name_;
}

std::pair<int, int> Args::getLocation() const
{
    return { location_.getLine(), location_.getColumn() };
}