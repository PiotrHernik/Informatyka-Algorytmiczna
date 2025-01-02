#pragma once

#include <string>
#include <vector>
#include <memory>
#include <initializer_list>

#include "../ast/Procedure.hpp"
#include "../ast/Declaration.hpp"
#include "../ast/ProcHead.hpp"
#include "../ast/Command.hpp"
#include "../ast/Enums.hpp"

std::vector<std::shared_ptr<Procedure>> makeProcedures(
    std::vector<std::shared_ptr<Procedure>>
    , std::shared_ptr<ProcHead>
    , std::vector<std::shared_ptr<Declaration>>
    , std::vector<std::shared_ptr<Command>>
    , ProcedureEnum);


std::vector<std::shared_ptr<Procedure>> makeProcedures(
    std::vector<std::shared_ptr<Procedure>>
    , std::shared_ptr<ProcHead>
    , std::vector<std::shared_ptr<Command>>
    , ProcedureEnum);

std::vector<std::shared_ptr<Procedure>> makeProcedures();