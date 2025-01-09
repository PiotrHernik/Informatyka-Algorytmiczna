#include <iostream>

#include "makeIdentifier.hpp"

std::shared_ptr<Identifier> makeIdentifier(std::string name, IdentifierEnum idEnum) {
    auto id = std::make_shared<Identifier>(name, idEnum);
    return std::move(id);
}

std::shared_ptr<Identifier> makeIdentifier(std::string pid1, std::string pid2, IdentifierEnum idEnum) {
    auto id = std::make_shared<Identifier>(pid1, pid2, idEnum);
    return std::move(id);
}

std::shared_ptr<Identifier> makeIdentifier(std::string pid, long long num, IdentifierEnum idEnum) {
    auto id = std::make_shared<Identifier>(pid, num, idEnum);
    return std::move(id);
}