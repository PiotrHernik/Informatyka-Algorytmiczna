#pragma once

#include <memory>
#include <string>
#include <iostream>

struct Node
{
    virtual ~Node() = default;
    virtual std::string doAsm()  const = 0;
};

using ast_type = std::unique_ptr<Node>;

// struct Value : Node {};

enum class IdentifierEnum {
    PID,
    PIDT,
    PIDTPID
};

struct Identifier : Node {
    Identifier(std::string pid, IdentifierEnum idEnum);
    Identifier(std::string pid1, std::string pid2, IdentifierEnum idEnum);
    Identifier(std::string pid, long long num, IdentifierEnum idEnum);
    std::string doAsm() const override;
    IdentifierEnum idEnum;
    std::string name1;
    std::string name2;
    long long num;
};

enum class ValueEnum 
{
    NUM,
    ID
};

struct Value : Node 
{
    Value(std::unique_ptr<Identifier>, ValueEnum);
    Value(long long, ValueEnum);
    std::string doAsm() const override;
    ValueEnum valEnum;
    std::unique_ptr<Identifier> identifier;
    long long value;
};

std::unique_ptr<Identifier> makeIdentifier(std::string pid, IdentifierEnum idEnum);
std::unique_ptr<Identifier> makeIdentifier(std::string pid1, std::string pid2, IdentifierEnum idEnum);
std::unique_ptr<Identifier> makeIdentifier(std::string pid, long long num, IdentifierEnum idEnum);

// void readIdentifier(std::unique_ptr<Identifier> id, IdentifierEnum idEnum);