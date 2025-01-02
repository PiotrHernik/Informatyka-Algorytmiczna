#pragma once

#include <string>
#include <vector>
#include <memory>

#include "../ast/ArgsDeclaration.hpp"
#include "../ast/Enums.hpp"

std::shared_ptr<ProcHead> makeProcHead(std::string, std::vector<std::shared_ptr<ArgsDeclaration>>);
