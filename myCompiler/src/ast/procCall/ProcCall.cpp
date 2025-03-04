#include "procCall/ProcCall.hpp"

ProcCall::ProcCall(std::string& name, std::vector<std::shared_ptr<Args>> args, Location& loc)
    : name_(name), args_(args), location_(loc) {}

std::pair<int,int> ProcCall::getLocation() const
{
    return { location_.getLine(), location_.getColumn() };
}