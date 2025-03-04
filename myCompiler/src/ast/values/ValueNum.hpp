#include "Value.hpp"

class ValueNum : public Value
{
public:
    ValueNum(long long, const Location&);
private:
    long long value_;
};