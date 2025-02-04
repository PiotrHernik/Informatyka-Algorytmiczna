#include "ProcCall.hpp"

ProcCall::ProcCall(std::string name, std::vector<std::shared_ptr<Args>> args)
    : name(name), args(args){}

void ProcCall::setLocation(int lin, int col)
{
    line = lin;
    column = col;
}