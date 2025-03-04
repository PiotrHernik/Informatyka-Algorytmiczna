#include "Declaration.hpp"

Declaration::Declaration(const std::string& name, const Location& loc)
    : name_(name), location_(loc) {}

std::pair<int,int> Declaration::getLocation() const
{
    return { location_.getLine(), location_.getColumn() };
}