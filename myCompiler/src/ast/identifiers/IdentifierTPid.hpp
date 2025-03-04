#pragma once

#include <string>
#include <vector>

#include <Identifier.hpp>

class IdentifierTPid : public Identifier
{
    public:
    IdentifierTPid(const std::string&, const std::string&, const Location&);
    std::string getName2() const;
    std::vector<std::string> getAddress() const override;
private:
    std::string name2_;
};