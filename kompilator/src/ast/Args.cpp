#include "Args.hpp"

Args::Args(std::string name) : name(name){}

void Args::setLocation(int lin, int col)
{
    line = lin;
    column = col;
}