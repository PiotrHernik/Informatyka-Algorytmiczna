#include "DeclarationTable.hpp"

DeclarationTable::DeclarationTable(const std::string& name, const long long num1, const long long num2, const Location& loc)
    : Declaration(name, loc), num1_(num1), num2_(num2) {}