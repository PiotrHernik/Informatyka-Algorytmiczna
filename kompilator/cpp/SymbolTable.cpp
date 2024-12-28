

#include "SymbolTable.hpp"
#include "ast.hpp"

long long SymbolTable::firstFreeAddress = 100;
std::fstream SymbolTable::outputFile("teeest.txt");

void SymbolTable::setOutputFile(const char* file){
    outputFile.open(file, std::fstream::out);
    if(!outputFile.is_open())
    {
        std::cerr << "Outputfile was not open" <<std::endl;
    }
}


bool SymbolTable::isArgument(std::string name, DeclarationEnum declEnum)
{
    if (declEnum == DeclarationEnum::PID)
    {
        if (arguments.find(name) == arguments.end())
        {
            return false;
        }
    }
    else if (declEnum == DeclarationEnum::TABLE)
    {
        if (arguments_tables.find(name) == arguments_tables.end())
        {
            return false;
        }
    }
    
    
    return true;
}


bool SymbolTable::isDeclared(std::string name, DeclarationEnum declEnum)
{
    if (declEnum == DeclarationEnum::PID)
    {
        if (declarations.find(name) == declarations.end())
        {
            return false;
        }
    }
    else if (declEnum == DeclarationEnum::TABLE)
    {
        if (declaration_tables.find(name) == declaration_tables.end())
        {
            return false;
        }
    }
    
    
    return true;
}

bool SymbolTable::isInitialized(std::string) {return false;}

void SymbolTable::addDeclarations(std::shared_ptr<Declaration> decl)
{
    if( decl->decEnum == DeclarationEnum::PID)
    {
        if (declarations.find(decl->name) != declarations.end() || 
            arguments.find(decl->name) != arguments.end())
        {
            throw std::invalid_argument("Redeclaration second in declaration");
        }

        declarations.insert(decl->name);
        declaration_adress.insert({decl->name, firstFreeAddress});
        firstFreeAddress++;
    }
    else if(decl->decEnum == DeclarationEnum::TABLE)
    {
        if (declaration_tables.find(decl->name) != declaration_tables.end() || 
            arguments_tables.find(decl->name) != arguments_tables.end())
        {
            throw std::invalid_argument("Redeclaration second in declaration");
        }

        auto size = decl->num2 - decl->num1 + 1;
        auto offset = decl->num1;
        declaration_tables.insert(decl->name);
        declaration_table_address.insert({decl->name, firstFreeAddress});
        address_to_table_name.insert({firstFreeAddress, decl->name});
        size_and_offset_declaration_tables.insert({decl->name, std::make_pair(size, offset)});
        firstFreeAddress += size;
    }
    else throw std::invalid_argument("Type of Declaration is wrong");
}

void SymbolTable::addArgs(std::shared_ptr<ArgsDeclaration> argsDecl)
{    
    if( argsDecl->argsDecEnum == ArgsDeclarationEnum::PID)
    {
        if (arguments.find(argsDecl->name) != arguments.end())
        {
            throw std::invalid_argument("Redeclaration");
        }
        
        arguments.insert(argsDecl->name);
    }
    else if(argsDecl->argsDecEnum == ArgsDeclarationEnum::TABLE)
    {
        if (arguments_tables.find(argsDecl->name) != arguments_tables.end())
        {
            throw std::invalid_argument("Redeclaration");
        }

        arguments_tables.insert(argsDecl->name);
    }
    else throw std::invalid_argument("Type of Declaration is wrong");
}

void SymbolTable::printAllDeclAndArgs()
{
    for(auto decl : declarations)
    {
        std::cout << "Dec Name: " <<decl << " , memory address: " << declaration_adress[decl] << std::endl;
    }
    for(auto tab : declaration_tables)
    {
        std::cout << "Dec Tab name: " <<tab <<" , memort address: " << declaration_table_address[tab] 
        << " , size: " << size_and_offset_declaration_tables[tab].first << " , offset: " << size_and_offset_declaration_tables[tab].second <<std::endl;
    }

    for(auto arg : arguments)
    {
        std::cout << "Argument Name: " << arg << std::endl;
    }

}

long long SymbolTable::getPidAddress(std::string name)
{
    if (isDeclared(name, DeclarationEnum::PID))
    {
        return declaration_adress[name];
    }
    else
    {
        return arguments_adress[name];
    }
    
    
}

long long SymbolTable::getTableAddress(std::string name, long long num)
{
    if (isDeclared(name, DeclarationEnum::TABLE))
    {
        auto tableBegin = declaration_table_address[name];
        auto [size, offset] = size_and_offset_declaration_tables[name];
        if (num < offset)
        {
            throw std::invalid_argument("Out of downbound");
        }
        else if (num > size + offset - 1)
        {
            throw std::invalid_argument("Out of upperbound");
        }
        return tableBegin - offset + num;
    }
    else
    {
        auto tableBegin = argument_table_address[name];
        auto [size, offset] = size_and_offset_argument_tables[name];
        if (num < offset)
        {
            throw std::invalid_argument("Out of downbound");
        }
        else if (num > size + offset - 1)
        {
            throw std::invalid_argument("Out of upperbound");
        }
        return tableBegin - offset + num;
    }
}

long long SymbolTable::getTableAddress(std::string name)
{
    long long tableBegin;
    long long size = 0, offset = 0;
    if (isDeclared(name, DeclarationEnum::TABLE))
    {
        tableBegin = declaration_table_address[name];
        auto [tempSize, tempOffset] = size_and_offset_declaration_tables[name];
        size = tempSize;
        offset = tempOffset;
    }
    else if (isArgument(name, DeclarationEnum::TABLE))
    {
        tableBegin = argument_table_address[name];
        auto [tempSize, tempOffset] = size_and_offset_argument_tables[name];
        size = tempSize;
        offset = tempOffset;
    }

    return tableBegin - offset;
}
