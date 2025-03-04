#include "values/ValueNum.hpp"

ValueNum::ValueNum(long long value, const Location& loc) 
    : Value(loc), value_(value) {}