#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Args.hpp"
#include "Location.hpp"


inline std::vector<std::shared_ptr<Args>> makeArgs(const std::string& arg, Location& loc)
{
    auto argumnet = std::make_shared<Args>(arg, loc);
    return std::vector<std::shared_ptr<Args>>({argumnet});
}

inline std::vector<std::shared_ptr<Args>> makeArgs(std::vector<std::shared_ptr<Args>>& args, std::string& arg, Location& loc)
{
    auto argumnet = std::make_shared<Args>(arg, loc);
    args.push_back(argumnet);
    return args;
}