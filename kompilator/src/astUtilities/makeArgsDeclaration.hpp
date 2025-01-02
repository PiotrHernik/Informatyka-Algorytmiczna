#pragma once

#include <string>
#include <vector>
#include <memory>

#include "../ast/ArgsDeclaration.hpp"
#include "../ast/Enums.hpp"


std::vector<std::shared_ptr<ArgsDeclaration>> makeArgsDeclaration(std::vector<std::shared_ptr<ArgsDeclaration>>&, const std::string&, ArgsDeclarationEnum);
std::vector<std::shared_ptr<ArgsDeclaration>> makeArgsDeclaration(const std::string&, ArgsDeclarationEnum);