#include "Procedure.hpp"

class ProcedureWithDeclaration : public Procedure
{
public:
    ProcedureWithDeclaration(std::shared_ptr<ProcHead>, std::vector<std::shared_ptr<Declaration>>, std::vector<std::shared_ptr<Command>>);
private:
    std::vector<std::shared_ptr<Declaration>> declarations_;
};