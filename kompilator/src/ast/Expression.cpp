#include "Expression.hpp"

Expression::Expression(std::shared_ptr<Value> value, ExpressionEnum expEnum)
    : value1(std::move(value)), expEnum(expEnum){} 

Expression::Expression(std::shared_ptr<Value> value1, std::shared_ptr<Value> value2, ExpressionEnum expEnum)
    : value1(std::move(value1)), value2(std::move(value2)), expEnum(expEnum){}

std::string Expression::doAsm() const{
    return std::string("Expression");
}

void Expression::setLocation(int lin, int col)
{
    line = lin;
    column = col;
}