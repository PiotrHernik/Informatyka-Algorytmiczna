#pragma once


#include <string>
#include <vector>
#include <memory>

#include "../ast/Args.hpp"


std::vector<std::shared_ptr<Args>> makeArgs(std::string&);
std::vector<std::shared_ptr<Args>> makeArgs(std::vector<std::shared_ptr<Args>>&, std::string&);