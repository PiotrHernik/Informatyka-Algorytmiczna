#pragma once

#include "Procedure.hpp"

class ProcedureWithoutDecl : public Procedure
{
public:
    ProcedureWithoutDecl(std::shared_ptr<ProcHead>, std::vector<std::shared_ptr<Command>>);
};