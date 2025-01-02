#pragma once


#include <string>
#include <vector>
#include <memory>
#include <initializer_list>

#include "../ast/Declaration.hpp"
#include "../ast/Enums.hpp"

std::vector<std::shared_ptr<Declaration>> makeDeclaration(const std::string, std::initializer_list<long long>);
std::vector<std::shared_ptr<Declaration>> makeDeclaration(std::vector<std::shared_ptr<Declaration>> vec, const std::string, std::initializer_list<long long>);
