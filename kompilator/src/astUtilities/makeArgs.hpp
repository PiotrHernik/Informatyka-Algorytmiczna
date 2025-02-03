#pragma once


#include <string>
#include <vector>
#include <memory>

#include "../ast/Args.hpp"


std::vector<std::shared_ptr<Args>> makeArgs(std::string&, int, int);
std::vector<std::shared_ptr<Args>> makeArgs(std::vector<std::shared_ptr<Args>>&, std::string&, int, int);