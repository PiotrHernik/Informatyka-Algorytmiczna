#include "makeArgs.hpp"

std::vector<std::shared_ptr<Args>> makeArgs(std::string& arg, int line, int column)
{
    auto argumnet = std::make_shared<Args>(arg);
    argumnet->setLocation(line, column);
    return std::vector<std::shared_ptr<Args>>({argumnet});
}

std::vector<std::shared_ptr<Args>> makeArgs(std::vector<std::shared_ptr<Args>>& vec, std::string& arg, int line, int column)
{
    auto argumnet = std::make_shared<Args>(arg);
    argumnet->setLocation(line, column);
    vec.push_back(argumnet);
    return vec;
}