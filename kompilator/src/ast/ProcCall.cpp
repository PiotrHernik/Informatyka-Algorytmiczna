#include "ProcCall.hpp"

ProcCall::ProcCall(std::string name, std::vector<std::shared_ptr<Args>> args)
    : name(name), args(args){}

std::string ProcCall::doAsm() const 
{
    return std::string("Proc_call");
}