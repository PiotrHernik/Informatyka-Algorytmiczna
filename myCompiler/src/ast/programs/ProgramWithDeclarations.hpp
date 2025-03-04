#pragma once

#include "Program.hpp"

class ProgramWithDeclarations : public Program
{
public:
    ProgramWithDeclarations(std::vector<std::shared_ptr<Declaration>>, std::vector<std::shared_ptr<Command>>, const Location&);
private:
    std::vector<std::shared_ptr<Declaration>> declarations_;
};