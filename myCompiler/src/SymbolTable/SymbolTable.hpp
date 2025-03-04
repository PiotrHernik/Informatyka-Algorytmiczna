#pragma once

#include <set>
#include <vector>
#include <unordered_map>
#include <memory>
#include <string>
#include <fstream>

#include "Declaration.hpp"
#include "ArgDeclaration.hpp"

class SymbolTable
{
public:
    SymbolTable() = default;
    SymbolTable(std::string);
    SymbolTable(const SymbolTable&) = default;
    SymbolTable(SymbolTable&&) noexcept = default;
    SymbolTable& operator=(const SymbolTable&) = default;
    SymbolTable& operator=(SymbolTable&&) noexcept = default;
    ~SymbolTable() = default;

    static long long useFirstFreeAddress();
    static void setOutputFile(const char* outputFile);

    bool isPidDeclared(std::string&) const;
    bool isTableDeclared(std::string&) const;
    bool isPidArgument(std::string&) const;
    bool isTableArgument(std::string&) const;
    void addPidArg(std::shared_ptr<ArgDeclaration>);
    void addTableArg(std::shared_ptr<ArgDeclaration>);
    void addPidDecl(std::shared_ptr<Declaration>);
    void addTableDecl(std::shared_ptr<Declaration>);
    std::pair<long long, long long> addIterator(std::string);
    void delateIterator(std::string);
    bool isIterator(std::string);

    long long getPidAddress(std::string);
    long long getTableAddress(std::string, long long);
    long long getTableAddress(std::string);

    void addArgsPidAddress(std::string&, long long);
    void addArgsTableAddress(std::string&, long long);

    bool isInitialized(std::string);
    void setAsInitialized(std::string);

    bool wasArgsAdded() const;

private:
    std::set<std::string> declarations_;
    std::unordered_map<std::string, long long> declarationAdress_;
    std::set<std::string> declarationsTables_;
    std::unordered_map<std::string, long long> declarationTableAddress_;
    std::unordered_map<std::string, std::pair<long long, long long>> sizeAndOffsetTableDeclarations_;

    std::set<std::string> arguments_;
    std::unordered_map<std::string, long long> argumentAddress_;
    std::set<std::string> argumentsTables_;
    std::unordered_map<std::string, long long> argTabAddress_;

    std::set<std::string> iterators_;
    std::unordered_map<std::string, long long> interatorAddress_;

    std::unordered_map<std::string, bool> initializedDeclarations_;

    std::string currentProcedureName_;

    static long long firstFreeAddress_;
    static std::fstream outputFile_;

    bool wasArgsAdded_ = false;
    std::string membership_;
};




// #include <set>
// #include <vector>
// #include <unordered_map>
// #include <memory>
// #include <string>
// #include <fstream>

// enum class DeclarationEnum;

// struct ArgDeclaration;
// struct Declaration;
// struct Identifier;
// struct Procedure;


// class SymbolTable
// {
// public:
//     SymbolTable(std::string);
//     SymbolTable() = default;
//     SymbolTable(const SymbolTable&) = default;
//     SymbolTable(SymbolTable&&) noexcept = default;
//     SymbolTable& operator=(const SymbolTable&) = default;
//     SymbolTable& operator=(SymbolTable&&) noexcept = default;
//     ~SymbolTable() = default;

//     bool isInitialized(std::string);
//     void setAsInitialized(std::string);
    
//     bool isDeclared(std::string, DeclarationEnum);
//     bool isArgument(std::string, DeclarationEnum);
//     void addArgs(std::shared_ptr<ArgDeclaration>);
//     void addDeclarations(std::shared_ptr<Declaration>);
//     std::pair<long long, long long> addIterator(std::string);
//     void delateIterator(std::string);
//     bool isIterator(std::string);
//     void printAllDeclAndArgs();
//     long long getPidAddress(std::string, bool = false);
//     long long getTableAddress(std::string, long long);
//     long long getTableAddress(std::string);
//     long long getArgPidAddressForProcCall(std::string&);
//     long long getArgTableAddressForProcCall(std::string&);
//     long long getArgTableAddressForProcCall(std::string&, long long);
//     long long getFirstFreeAddress();
//     void increaseFirstFreeAddress();
//     void addArgsAddress(std::string&, long long, ArgsDeclarationEnum);
//     void setOutputFile(const char* outputFile);
//     void increasNumProcCall();
//     void increasCurrProcCall();

//     std::string getMembership(); 

//     static std::fstream outputFile;

// private:
//     std::set<std::string> declarations;
//     std::unordered_map<std::string, long long> declaration_adress;
//     std::set<std::string> declaration_tables;
//     std::unordered_map<std::string, long long> declaration_table_address;
//     std::unordered_map<long long, std::string> address_to_table_name;
//     std::unordered_map<std::string, std::pair<long long, long long>> size_and_offset_declaration_tables;

//     std::set<std::string> arguments;
//     std::unordered_map<std::string, long long> argument_address;
//     std::unordered_map<std::string, std::vector<long long>> argument_adress_for_procCall;
//     std::set<std::string> arguments_tables;
//     std::unordered_map<std::string, long long> arg_tab_address;
//     std::unordered_map<std::string, std::vector<long long>> argument_table_addres_for_procCall;

//     std::set<std::string> iterators;
//     std::unordered_map<std::string, long long> interator_address;

//     std::unordered_map<std::string, bool> initializedDeclarations;

//     std::string membership; // it's need to know if it is a main program or a procedure

//     int numProcCall = 0;
//     int currProcCall = 0;

//     static long long firstFreeAddress;

    
// };