#include <iostream>

#include "SymbolTable.hpp"

long long SymbolTable::firstFreeAddress_ = 1000;
std::fstream SymbolTable::outputFile_("outputFile.txt");

SymbolTable::SymbolTable(std::string membership) : membership_(membership) {}

void SymbolTable::setOutputFile(const char* file){
    outputFile_.open(file, std::fstream::out);
    if(!outputFile_.is_open())
    {
        std::cerr << "Outputfile was not open" <<std::endl;
    }
}

long long SymbolTable::useFirstFreeAddress()
{
    return firstFreeAddress_++;
}

bool SymbolTable::isPidDeclared(std::string&) const
{ return true; }

bool SymbolTable::isTableDeclared(std::string&) const
{ return true; }

bool SymbolTable::isPidArgument(std::string&) const
{ return true; }
bool SymbolTable::isTableArgument(std::string&) const
{ return true; }
void SymbolTable::addPidArg(std::shared_ptr<ArgDeclaration>){}
void SymbolTable::addTableArg(std::shared_ptr<ArgDeclaration>){}
void SymbolTable::addPidDecl(std::shared_ptr<Declaration>){}
void SymbolTable::addTableDecl(std::shared_ptr<Declaration>){}

std::pair<long long, long long> SymbolTable::addIterator(std::string)
{return std::make_pair(0, 0);}
void SymbolTable::delateIterator(std::string){}
bool SymbolTable::isIterator(std::string){return true;}

long long SymbolTable::getPidAddress(std::string){ return 0; }
long long SymbolTable::getTableAddress(std::string, long long) { return 0; }
long long SymbolTable::getTableAddress(std::string) {   return 0; }

void SymbolTable::addArgsPidAddress(std::string&, long long){}
void SymbolTable::addArgsTableAddress(std::string&, long long){}

bool SymbolTable::isInitialized(std::string){ return true; }
void SymbolTable::setAsInitialized(std::string){}

bool SymbolTable::wasArgsAdded() const { return true; }