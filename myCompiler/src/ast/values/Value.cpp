#include "Value.hpp"

Value::Value(const Location& loc) : location_(loc) {}

std::pair<int, int> Value::getLocation() const
{
    return { location_.getLine(), location_.getColumn() };
}