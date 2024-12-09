#pragma once

#include <vector>
#include <memory>

class Parser{
public: 
    Parser(int argc, char* argv[]);
    std::pair<std::pair<int,int>, std::vector<std::tuple<int,int,int>>> readEdgesFromFile();
    std::vector<int> readStartPoint();
    std::vector<std::pair<int, int>> readP2P();
    bool checkFileExtension();
    bool checkArgs(size_t argc, char *argv[]);

private:
    int argc;
    char** argv;
    char* graphFile;
    char* sourceFile;
    char* outputFile;
    std::string path = "/home/piter/ch9-1.1/inputs/Long-C/";
    int nodes;
};