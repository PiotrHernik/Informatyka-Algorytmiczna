#pragma once

#include <set>
#include <vector>
#include <unordered_map>
#include <memory>
#include <string>
#include <fstream>

enum class DeclarationEnum;
enum class IdentifierEnum;
enum class ArgsDeclarationEnum;
struct ArgsDeclaration;
struct Declaration;
struct Identifier;
struct Procedure;


class SymbolTable
{
public:
    SymbolTable(std::string);
    SymbolTable() = default;
    SymbolTable(const SymbolTable&) = default; // Konstruktor kopiujący
    SymbolTable(SymbolTable&&) noexcept = default; // Konstruktor przenoszący
    SymbolTable& operator=(const SymbolTable&) = default; // Operator przypisania kopiującego
    SymbolTable& operator=(SymbolTable&&) noexcept = default; // Operator przypisania przenoszącego
    bool isInitialized(std::string);
    void setAsInitialized(std::string);
    
    bool isDeclared(std::string, DeclarationEnum);
    bool isArgument(std::string, DeclarationEnum);
    void addArgs(std::shared_ptr<ArgsDeclaration>);
    void addDeclarations(std::shared_ptr<Declaration>);
    std::pair<long long, long long> addIterator(std::string);
    void delateIterator(std::string);
    bool isIterator(std::string);
    void printAllDeclAndArgs();
    long long getPidAddress(std::string, bool = false);
    long long getTableAddress(std::string, long long);
    long long getTableAddress(std::string);
    long long getArgPidAddressForProcCall(std::string&);
    long long getArgTableAddressForProcCall(std::string&);
    long long getArgTableAddressForProcCall(std::string&, long long);
    long long getFirstFreeAddress();
    void increaseFirstFreeAddress();
    void addArgsAddress(std::string&, long long, ArgsDeclarationEnum);
    void setOutputFile(const char* outputFile);
    void increasNumProcCall();
    void increasCurrProcCall();

    std::string getMembership(); 

    static std::fstream outputFile;

private:
    std::set<std::string> declarations;
    std::unordered_map<std::string, long long> declaration_adress;
    std::set<std::string> declaration_tables;
    std::unordered_map<std::string, long long> declaration_table_address;
    std::unordered_map<long long, std::string> address_to_table_name;
    std::unordered_map<std::string, std::pair<long long, long long>> size_and_offset_declaration_tables;

    std::set<std::string> arguments;
    std::unordered_map<std::string, long long> argument_address;
    std::unordered_map<std::string, std::vector<long long>> argument_adress_for_procCall;
    std::set<std::string> arguments_tables;
    std::unordered_map<std::string, long long> arg_tab_address;
    std::unordered_map<std::string, std::vector<long long>> argument_table_addres_for_procCall;

    std::set<std::string> iterators;
    std::unordered_map<std::string, long long> interator_address;

    std::unordered_map<std::string, bool> initializedDeclarations;

    std::string membership; // it's need to know if it is a main program or a procedure

    int numProcCall = 0;
    int currProcCall = 0;

    static long long firstFreeAddress;

    
};