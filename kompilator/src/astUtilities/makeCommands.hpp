#pragma once

#include <string>
#include <vector>
#include <memory>

#include "../ast/Command.hpp"
#include "../ast/Enums.hpp"


std::vector<std::shared_ptr<Command>> makeCommands(std::shared_ptr<Command>);
std::vector<std::shared_ptr<Command>> makeCommands(std::vector<std::shared_ptr<Command>>, std::shared_ptr<Command>);
