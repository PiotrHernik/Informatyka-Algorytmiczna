#pragma once


#include <string>
#include <vector>
#include <memory>

#include "../ast/Args.hpp"
#include "../ast/ProcCall.hpp"
#include "../ast/Enums.hpp"

std::shared_ptr<ProcCall> makeProcCall(std::string, std::vector<std::shared_ptr<Args>>);
