#pragma once

#include <vector>
#include "Graph.hpp"
#include "DFS.hpp"


class StrongComponent
{
    public:
        StrongComponent(Graph* graph);
        ~StrongComponent();
        void findStrongComponents();
        void printStrongComponents();
    private:
        void makeTranspose();
        Graph* graph;
        Graph* transposedGraph;
        std::vector<std::vector<int>> strongComponents;
};