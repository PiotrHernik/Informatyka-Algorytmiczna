#include <iostream>
#include "Error.hpp"

Error::Error(const std::string& errMsg) :errMsg(errMsg){}

void Error::notifyError()
{
    std::cout<< errMsg << std::endl;
    exit(1);
}