#include "CommandWrite.hpp"

CommandWrite::CommandWrite(std::shared_ptr<Value> value, const Location& loc)
    : Command(loc), value_(value) {}