#pragma once

#include <string>

#include "Declaration.hpp"
#include "Location.hpp"

class DeclarationPid : public Declaration
{
public:
    DeclarationPid(const std::string&, const Location&);
};