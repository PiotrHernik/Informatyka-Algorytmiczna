#pragma once

#include <string>
#include <vector>
#include <memory>
#include <initializer_list>

#include "../ast/Identifier.hpp"
#include "../ast/Enums.hpp"

std::shared_ptr<Identifier> makeIdentifier(std::string pid, IdentifierEnum idEnum);
std::shared_ptr<Identifier> makeIdentifier(std::string pid1, std::string pid2, IdentifierEnum idEnum);
std::shared_ptr<Identifier> makeIdentifier(std::string pid, long long num, IdentifierEnum idEnum);