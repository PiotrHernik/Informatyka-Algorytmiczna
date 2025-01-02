#include "makeProcCall.hpp" 

std::shared_ptr<ProcCall> makeProcCall(std::string name, std::vector<std::shared_ptr<Args>> args)
{
    return std::make_shared<ProcCall>(name, args);
}