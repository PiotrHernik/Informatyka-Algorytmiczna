#pragma once

#include <string>

#include <Identifier.hpp>

class IdentifierPid : public Identifier
{
public:
    IdentifierPid(const std::string&, const Location&);

    std::vector<std::string> getAddress() const override;
};

         