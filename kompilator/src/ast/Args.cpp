#include "Args.hpp"

Args::Args(std::string name) : name(name){}

std::string Args::doAsm() const 
{
    return std::string("Args");
}