#include "arithmetics.hpp"

#include <vector>
#include <string>

int Arithmetics::rtntAddressMultiply = 0;

std::vector<std::string> Arithmetics::multiply()
{
    std::vector<std::string> asmCommands;

    
    asmCommands.push_back("    SET 1"); // VALUE1
    asmCommands.push_back("    STORE 21"); // VALUE1
    asmCommands.push_back("    LOAD 11"); // VALUE1
    asmCommands.push_back("    JNEG 11"); //JUMPX
    asmCommands.push_back("    LOAD 10"); //VALUE2
    asmCommands.push_back("    JPOS 6"); //jump aa
    asmCommands.push_back("    LOAD 21");
    asmCommands.push_back("    SUB 21");
    asmCommands.push_back("    SUB 21");
    asmCommands.push_back("    STORE 12"); //ZNAK
    asmCommands.push_back("    JUMP 13"); //JUMP Y
    asmCommands.push_back("    LOAD 21");//aa
    asmCommands.push_back("    STORE 12");
    asmCommands.push_back("    JUMP 10"); //JUMP Y
    asmCommands.push_back("    LOAD 10"); //X
    asmCommands.push_back("    JNEG 6");//jumb bb
    asmCommands.push_back("    LOAD 21");
    asmCommands.push_back("    SUB 21");
    asmCommands.push_back("    SUB 21");
    asmCommands.push_back("    STORE 12");
    asmCommands.push_back("    JUMP 3"); //JUMP Y
    asmCommands.push_back("    LOAD 21"); //bb
    asmCommands.push_back("    STORE 12");
    asmCommands.push_back("    LOAD 10");//Y
    asmCommands.push_back("    JPOS 3"); //jump a
    asmCommands.push_back("    SUB 10");
    asmCommands.push_back("    SUB 10");
    asmCommands.push_back("    STORE 1");//a
    asmCommands.push_back("    LOAD 11");
    asmCommands.push_back("    JPOS 3"); //JUMP B
    asmCommands.push_back("    SUB 11");
    asmCommands.push_back("    SUB 11");
    asmCommands.push_back("    STORE 2");//B
    asmCommands.push_back("    SUB 1");
    asmCommands.push_back("    JNEG 8"); //jump C
    asmCommands.push_back("    LOAD 1");
    asmCommands.push_back("    SUB 21");
    asmCommands.push_back("    STORE 8");
    asmCommands.push_back("    LOAD 2");
    asmCommands.push_back("    STORE 9");
    asmCommands.push_back("    STORE 7");
    asmCommands.push_back("    JUMP 8"); //JUMP D
    asmCommands.push_back("    LOAD 1");//C
    asmCommands.push_back("    STORE 9");
    asmCommands.push_back("    STORE 7");
    asmCommands.push_back("    LOAD 2");
    asmCommands.push_back("    SUB 21");
    asmCommands.push_back("    STORE 8");
    asmCommands.push_back("    LOAD 8"); //F
    asmCommands.push_back("    HALF");//D
    asmCommands.push_back("    ADD 0");
    asmCommands.push_back("    SUB 8");
    asmCommands.push_back("    JZERO 7"); //JUMP E
    asmCommands.push_back("    LOAD 7");
    asmCommands.push_back("    ADD 9");
    asmCommands.push_back("    STORE 7");
    asmCommands.push_back("    LOAD 8");
    asmCommands.push_back("    SUB 21");
    asmCommands.push_back("    JZERO 8"); //JUMP G
    asmCommands.push_back("    LOAD 8");//E
    asmCommands.push_back("    HALF");
    asmCommands.push_back("    STORE 8");
    asmCommands.push_back("    LOAD 7");
    asmCommands.push_back("    ADD 0");
    asmCommands.push_back("    STORE 7");
    asmCommands.push_back("    JUMP -17"); //JUMP F 
    asmCommands.push_back("    LOAD 12"); // G
    asmCommands.push_back("    JPOS 5"); // JUMP END
    asmCommands.push_back("    LOAD 7");
    asmCommands.push_back("    SUB 7");
    asmCommands.push_back("    SUB 7");
    asmCommands.push_back("    JUMP 2"); //JUMP END +1
    asmCommands.push_back("    LOAD 7");//END
    asmCommands.push_back("    RTRN " + std::to_string(rtntAddressMultiply));

    return asmCommands;
}