#include "Value.hpp"

Value::Value(std::shared_ptr<Identifier> id, ValueEnum valEnum) : identifier(std::move(id)), valEnum(valEnum){}

Value::Value(long long num, ValueEnum valEnum) : value(num), valEnum(valEnum){}

void Value::setLocation(int lin, int col)
{
    line = lin;
    column = col;
}
