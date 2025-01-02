#include "makeArgs.hpp"

std::vector<std::shared_ptr<Args>> makeArgs(std::string& arg)
{
    return std::vector<std::shared_ptr<Args>>({std::make_shared<Args>(arg)});
}

std::vector<std::shared_ptr<Args>> makeArgs(std::vector<std::shared_ptr<Args>>& vec, std::string& arg)
{
    vec.push_back(std::make_shared<Args>(arg));
    return vec;
}