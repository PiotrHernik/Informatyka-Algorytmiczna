#pragma once
#include <string>


class Error
{
public:
    Error(const std::string&);
    void notifyError();

private:
    std::string errMsg;
};