#pragma once

#include "Declaration.hpp"

class DeclarationTable : public Declaration
{
public:
    DeclarationTable(const std::string&, const long long, const long long, const Location&);
private:
    const long long num1_;
    const long long num2_;
};