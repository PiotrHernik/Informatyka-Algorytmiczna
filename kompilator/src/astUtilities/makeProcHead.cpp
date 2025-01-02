#include "makeProcCall.hpp"
#include "../ast/ProcHead.hpp"
#include "../ast/ArgsDeclaration.hpp"

std::shared_ptr<ProcHead> makeProcHead(std::string name, std::vector<std::shared_ptr<ArgsDeclaration>> argsDecl)
{
    return std::make_shared<ProcHead>(name, argsDecl);
}
