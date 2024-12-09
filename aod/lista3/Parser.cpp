#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <vector>

#include "Parser.hpp"

Parser::Parser(int argc, char* argv[]) : argc(argc), argv(argv){}


std::pair<std::pair<int,int>, std::vector<std::tuple<int,int,int>>> Parser::readEdgesFromFile(){
    std::vector<std::tuple<int, int, int>> edges;
    int vertexSize = 0;
    int edgesSize = 0;
    std::fstream graphData;

    if(!checkArgs(argc, argv)){
        std::cerr << "Invalid arguments provided. Program will terminate." << std::endl;
        exit(1); // Zakończenie programu z kodem błędu 
    }

    if(argc == 8){
        std::string file(argv[3]);
        path = path + file;

        graphData.open(path);


        if (!graphData.is_open()){
            std::cout<<"File was't open"<<std::endl;
            return std::make_pair(std::make_pair(vertexSize, edgesSize), edges);
        }
    }
    else{
        graphData.open(path);
        if (!graphData.is_open()){
            std::cout<<"File was't open"<<std::endl;
            return std::make_pair(std::make_pair(vertexSize, edgesSize), edges);
        }
    }
    

    if(!checkFileExtension())
    {
        std::cerr << "Invalid arguments provided. Program will terminate." << std::endl;
        exit(1);
    }

    std::string line;
    std::string lineType, problem;
    int from, to, vs, es;
    int cost;
    while(std::getline(graphData, line)){
        std::istringstream iss(line);

        iss >> lineType >> problem >> vs >> es;

        if(lineType == "p"){
            vertexSize = vs;
            edgesSize = es;
            
            break;
        }
    }

    while(std::getline(graphData, line)){
        std::istringstream iss(line);

        iss >> lineType >> from >> to >> cost;

        if(lineType == "a"){

            edges.emplace_back(from, to, cost);
        }

    }

    graphData.close();
    return std::make_pair(std::make_pair(vertexSize, edgesSize), edges);;
}

std::vector<int> Parser::readStartPoint(){
    std::string startPointFile( argv[5]);
    std::string holePath = path + startPointFile;

    std::fstream startPoint(holePath);
    std::vector<int> startPoints;

    if(!startPoint.is_open()) {
        std::cout<<"Source file is't open"<<std::endl;
        return startPoints;
    }


    std::string line, lineType;
    int sp;

    while(std::getline(startPoint, line)){
        std::istringstream iss(line);

        iss >> lineType >> sp;

        if(lineType == "s"){
            startPoints.emplace_back(sp);
        }
    }
    return startPoints;
}

std::vector<std::pair<int, int>> Parser::readP2P(){
    std::string startPointFile( argv[5]);
    std::string holePath = path + startPointFile;

    std::fstream startPoint(holePath);
    std::vector<std::pair<int,int>> points;

    if(!startPoint.is_open()) return points;


    std::string line, lineType;
    int sp, endp;

    while(std::getline(startPoint, line)){
        std::istringstream iss(line);

        iss >> lineType >> sp >>endp;

        if(lineType == "q"){
            points.emplace_back(sp, endp);
        }
    }
    return points;
}

bool Parser::checkArgs(size_t argc, char *argv[])
{
    if(argc == 2) {
        path = argv[1];
        return true;
    }

    if(argc != 8 && argc != 2) {
        std::cout << "Incorrect number of arguments!" << std::endl;
        return false;
    }
    if(strcmp(argv[1],"dijkstra") != 0 && strcmp(argv[1], "dial") != 0 && strcmp(argv[1],"radixheap") != 0)
    {
        std::cout << R"(Use "dijkstra" or "dial" or "radixheap" as first argument!)" << std::endl;
        return false;
    }
    if(strcmp(argv[2] ,"-d") != 0)
    {
        std::cout << "You forgot -d!" << std::endl;
        return false;
    }
    if(strcmp(argv[4], "-ss")  != 0 && strcmp(argv[4], "-p2p") != 0)
    {
        std::cout << "Use -ss or -p2p option!" << std::endl;
        return false;
    }
    else if((strcmp(argv[4], "-ss") == 0 && strcmp(argv[6],"-oss") != 0)
            || (strcmp(argv[4], "-p2p") == 0 && strcmp(argv[6], "-op2p") != 0))
    {
        std::cout << "Follow -ss with -oss or -p2p with -op2p option!" << std::endl;
        return false;
    }
    // TODO - check file type, aka .*
    return true;
}

bool Parser::checkFileExtension()
{
    if(argc == 2){
        return true;
    }

    std::string def = argv[3];
    std::string sour = argv[5];
    std::string res = argv[7];
    if(def.substr(def.find_last_of('.') + 1) != "gr")
    {
        std::cout << "Invalid graph extension!" << std::endl;
        return false;
    }
    if(sour.substr(sour.find_last_of('.') + 1) != "ss"
    && sour.substr(sour.find_last_of('.') + 1) != "p2p")
    {
        std::cout << "Invalid source extension!" << std::endl;
        return false;
    }
    if(res.substr(res.find_last_of('.') + 1) != "res")
    {
        std::cout << "Invalid result extension!" << std::endl;
        return false;
    }
    return true;
}