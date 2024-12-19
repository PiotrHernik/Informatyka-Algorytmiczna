#include <iostream>

#include "ast.hpp"


Identifier::Identifier(std::string pid, IdentifierEnum idEnum) : name1(pid), idEnum(idEnum)
{
    std::cout <<"Kontruktor Identifier: " <<name1 <<std::endl;
}
Identifier::Identifier(std::string pid1, std::string pid2, IdentifierEnum idEnum) : name1(pid1), name2(pid2), idEnum(idEnum)
{
}
Identifier::Identifier(std::string pid, long long num, IdentifierEnum idEnum) : name1(pid), num(num), idEnum(idEnum)
{
}
std::string Identifier::doAsm() const{
    return std::string("Identifier");
}

std::unique_ptr<Identifier> makeIdentifier(std::string name, IdentifierEnum idEnum) {
    std::cout <<"tworzę Identifier pid" <<std::endl;
    auto id = std::make_unique<Identifier>(name, idEnum);
    return std::move(id);
}

std::unique_ptr<Identifier> makeIdentifier(std::string pid1, std::string pid2, IdentifierEnum idEnum) {
    std::cout <<"tworzę Identifier pid[pid]" <<std::endl;
    auto id = std::make_unique<Identifier>(pid1, pid2, idEnum);
    return std::move(id);
}

std::unique_ptr<Identifier> makeIdentifier(std::string pid, long long num, IdentifierEnum idEnum) {
    std::cout <<"tworzę Identifier pid[num]" <<std::endl;
    auto id = std::make_unique<Identifier>(pid, num, idEnum);
    return std::move(id);
}


Value::Value(std::unique_ptr<Identifier> id, ValueEnum valEnum) : identifier(std::move(id)), valEnum(valEnum){}

Value::Value(long long num, ValueEnum valEnum) : value(num), valEnum(valEnum){}

std::string Value::doAsm() const{
    return std::string("Value");
}


// void readIdentifier(std::unique_ptr<Identifier> id, IdentifierEnum idEnum){
//     std::string pid1;
//     std::string pid2;
//     long long num;
//     switch(idEnum){
//         case PID:
//             pid1 = id->name1;
//     }
// }