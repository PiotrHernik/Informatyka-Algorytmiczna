#include "arithmetics.hpp"

#include <vector>
#include <string>

int Arithmetics::rtntAddressMultiply = 0;
int Arithmetics::rtntAddressDivide = 0;


std::vector<std::string> Arithmetics::multiply()
{
    std::vector<std::string> asmCommands;

    asmCommands.push_back("    SET 1"); 
    asmCommands.push_back("    STORE 21");
    asmCommands.push_back("    SET 0"); 
    asmCommands.push_back("    STORE 7");
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
    asmCommands.push_back("    JNEG 7"); //jump C
    asmCommands.push_back("    LOAD 1");
    asmCommands.push_back("    STORE 8");
    asmCommands.push_back("    LOAD 2");
    asmCommands.push_back("    STORE 9");
    asmCommands.push_back("    STORE 6");
    asmCommands.push_back("    JUMP 6"); //JUMP F
    asmCommands.push_back("    LOAD 1");//C
    asmCommands.push_back("    STORE 9");
    asmCommands.push_back("    STORE 6");
    asmCommands.push_back("    LOAD 2");// od tą trzeba zmienić 
    asmCommands.push_back("    STORE 8");
    asmCommands.push_back("    LOAD 8"); //F
    asmCommands.push_back("    HALF");//D
    asmCommands.push_back("    ADD 0");
    asmCommands.push_back("    SUB 8");
    asmCommands.push_back("    JZERO 8"); //JUMP E
    asmCommands.push_back("    LOAD 7");
    asmCommands.push_back("    ADD 6");
    asmCommands.push_back("    STORE 7");
    asmCommands.push_back("    LOAD 8");
    asmCommands.push_back("    SUB 21");
    asmCommands.push_back("    STORE 8"); //++
    asmCommands.push_back("    JZERO 8"); //JUMP G
    asmCommands.push_back("    LOAD 8");//E
    asmCommands.push_back("    HALF");
    asmCommands.push_back("    STORE 8");
    asmCommands.push_back("    LOAD 6");
    asmCommands.push_back("    ADD 0");
    asmCommands.push_back("    STORE 6");
    asmCommands.push_back("    JUMP -18"); //JUMP F 
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

std::vector<std::string> Arithmetics::divide()
{
    std::vector<std::string> asmCommands;


    asmCommands.push_back("    LOAD 11");
    asmCommands.push_back("    JZERO 103"); //JUMP ENDZERO
    asmCommands.push_back("    LOAD 10");
    asmCommands.push_back("    JZERO 100"); //JUMP ENDZERO
    asmCommands.push_back("    JNEG 6"); //JUMP X
    asmCommands.push_back("    STORE 9");
    asmCommands.push_back("    LOAD 21");
    asmCommands.push_back("    STORE 7");
    asmCommands.push_back("    JUMP 9");//JUMP Y
    asmCommands.push_back("    LOAD 10");
    asmCommands.push_back("    SUB 10"); //X - JEŚLI VALUE 2 JEST UJEMNA
    asmCommands.push_back("    SUB 10");
    asmCommands.push_back("    STORE 9");
    asmCommands.push_back("    LOAD 21");
    asmCommands.push_back("    SUB 21");
    asmCommands.push_back("    SUB 21");
    asmCommands.push_back("    STORE 7");
    asmCommands.push_back("    LOAD 9");//Y ZAPISUJEMY NUM2 DO C
    asmCommands.push_back("    STORE 2");
    asmCommands.push_back("    LOAD 11"); 
    asmCommands.push_back("    JNEG 6");//JUMP Z
    asmCommands.push_back("    STORE 8");
    asmCommands.push_back("    STORE 3");
    asmCommands.push_back("    LOAD 21");
    asmCommands.push_back("    JUMP 9");//JUMP b
    asmCommands.push_back("    LOAD 11"); 
    asmCommands.push_back("    SUB 11"); //Z 
    asmCommands.push_back("    SUB 11"); 
    asmCommands.push_back("    STORE 8"); 
    asmCommands.push_back("    STORE 3"); // ZAPISUJE NUM1 DO R
    asmCommands.push_back("    LOAD 21");
    asmCommands.push_back("    SUB 21");
    asmCommands.push_back("    SUB 21");
    asmCommands.push_back("    STORE 6"); //B
    asmCommands.push_back("    SET 0");
    asmCommands.push_back("    STORE 1"); //ZAPISUJE 0 DO L I D
    asmCommands.push_back("    STORE 4");
    asmCommands.push_back("    LOAD 2"); // A WHILE
    asmCommands.push_back("    SUB 8");
    asmCommands.push_back("    JPOS 9");// JUMP FOR
    asmCommands.push_back("    JUMP 1"); 
    asmCommands.push_back("    LOAD 1");
    asmCommands.push_back("    ADD 21");
    asmCommands.push_back("    STORE 1");
    asmCommands.push_back("    LOAD 2");
    asmCommands.push_back("    ADD 0");
    asmCommands.push_back("    STORE 2");
    asmCommands.push_back("    JUMP -9"); // JUMP A+1
    asmCommands.push_back("    LOAD 1"); //FOR
    asmCommands.push_back("    JZERO 21"); //JUMP AFTERFOR
    asmCommands.push_back("    LOAD 2");
    asmCommands.push_back("    HALF");
    asmCommands.push_back("    STORE 2");
    asmCommands.push_back("    SUB 3"); //IF
    asmCommands.push_back("    JPOS 9"); //JUMP ELSE
    asmCommands.push_back("    LOAD 4");
    asmCommands.push_back("    ADD 0");
    asmCommands.push_back("    ADD 21");
    asmCommands.push_back("    STORE 4");
    asmCommands.push_back("    LOAD 3");
    asmCommands.push_back("    SUB 2");
    asmCommands.push_back("    STORE 3");
    asmCommands.push_back("    JUMP 4"); //JUMP DECRESE L
    asmCommands.push_back("    LOAD 4"); // ELSE
    asmCommands.push_back("    ADD 0");
    asmCommands.push_back("    STORE 4");
    asmCommands.push_back("    LOAD 1"); //DECRESE L
    asmCommands.push_back("    SUB 21");
    asmCommands.push_back("    STORE 1");
    asmCommands.push_back("    JUMP -20"); //JUMP FOR + 1
    asmCommands.push_back("    LOAD 3"); // AFTERFOR, RESZTA W 3, WYNIK W 4
    asmCommands.push_back("    JZERO 35"); //JUMP END
    asmCommands.push_back("    LOAD 6"); 
    asmCommands.push_back("    JNEG 13"); //JUMP dZIELNAUJEMNA
    asmCommands.push_back("    LOAD 7");
    asmCommands.push_back("    JPOS 31"); //DODATNIA TO SKOK NA KONIEC BO WYNIK POPRAWNY
    asmCommands.push_back("    LOAD 4");
    asmCommands.push_back("    ADD 21");
    asmCommands.push_back("    STORE 4");
    asmCommands.push_back("    SUB 4");
    asmCommands.push_back("    SUB 4");
    asmCommands.push_back("    STORE 4");
    asmCommands.push_back("    LOAD 3");
    asmCommands.push_back("    SUB 9");
    asmCommands.push_back("    STORE 3");
    asmCommands.push_back("    JUMP 21"); //jump end
    asmCommands.push_back("    LOAD 7"); //DZIELNA UJEMNA
    asmCommands.push_back("    JNEG 11"); //JUMP DZIELNIKUJEMNY
    asmCommands.push_back("    LOAD 4");
    asmCommands.push_back("    ADD 21");
    asmCommands.push_back("    STORE 4");
    asmCommands.push_back("    SUB 4");
    asmCommands.push_back("    SUB 4");
    asmCommands.push_back("    STORE 4");
    asmCommands.push_back("    LOAD 9");
    asmCommands.push_back("    SUB 3");
    asmCommands.push_back("    STORE 3");
    asmCommands.push_back("    JUMP 9");
    asmCommands.push_back("    LOAD 3"); //DZIELNIK UJEMNY
    asmCommands.push_back("    SUB 3");
    asmCommands.push_back("    SUB 3");
    asmCommands.push_back("    STORE 3");
    asmCommands.push_back("    JUMP 4");
    asmCommands.push_back("    SET 0");
    asmCommands.push_back("    STORE 4");
    asmCommands.push_back("    STORE 3"); // END -1
    asmCommands.push_back("    RTRN " + std::to_string(rtntAddressDivide));

    return asmCommands;
}