#include <Identifier.hpp>

#include <string>
#include <utility>

Identifier::Identifier(const std::string& name, const Location& loc) : name_(name), location_(loc) {}

const std::string& Identifier::getName() const
{
    return name_;
}

std::pair<int,int> Identifier::getLocation() const
{
    return { location_.getLine(), location_.getColumn() };
}