#pragma once

#include <string>

#include <Identifier.hpp>

class IdentifierTNum : public Identifier
{
public:
    IdentifierTNum(const std::string&, const long long, const Location&);
    long long getNum() const;
    std::vector<std::string> getAddress() const override;
private:
    long long num_;
};
