#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <chrono>
#include <fstream>
#include "args.hpp"

class Graph {
public:
    Graph(size_t k, size_t i) {
        V2.resize(std::pow(2, k) * 2 + 2);  // +2 for source and sink

        std::random_device rd;
        std::mt19937 gen(rd());
        std::pair<size_t, size_t> range = {V2.size() / 2, V2.size() - 2};

        for (size_t curr = 1; curr < V2.size() / 2; curr++) {
            while (V2[curr].size() < i) {
                std::uniform_int_distribution<size_t> dis(range.first, range.second);
                size_t candidate = dis(gen);

                if (std::find(V2[curr].begin(), V2[curr].end(), candidate) == V2[curr].end() &&
                    std::find(V2[candidate].begin(), V2[candidate].end(), curr) == V2[candidate].end()) {
                    V2[curr].push_back(candidate);
                    V2[candidate].push_back(curr);
                }
            }
            V2[0].push_back(curr);
            V2[curr].push_back(0);
        }

        for (size_t current = V2.size() / 2; current <= V2.size() - 2; current++) {
            V2[V2.size() - 1].push_back(current);
            V2[current].push_back(V2.size() - 1);
        }
    }

    int maxFlow() {
        int source = 0, sink = V2.size() - 1;
        std::vector<std::vector<int>> capacities(V2.size(), std::vector<int>(V2.size(), 0));
        std::vector<int> parent(V2.size());

        for (size_t i = 0; i < V2.size(); i++) {
            for (size_t j : V2[i]) {
                capacities[i][j] = 1;
            }
        }

        int new_flow;
        int flow = 0;
        while ((new_flow = bfs(source, sink, parent, capacities))) {
            flow += new_flow;
            int cur = sink;
            while (cur != source) {
                int prev = parent[cur];
                capacities[prev][cur] -= new_flow;
                capacities[cur][prev] += new_flow;
                cur = prev;
            }
        }

        return flow;
    }

private:
    std::vector<std::vector<size_t>> V2;

    int bfs(int source, int sink, std::vector<int>& parent, std::vector<std::vector<int>>& capacities) {
        std::fill(parent.begin(), parent.end(), -1);
        parent[source] = -2;
        std::queue<std::pair<int, int>> q;
        q.push({source, std::numeric_limits<int>::max()});

        while (!q.empty()) {
            int cur = q.front().first;
            int flow = q.front().second;
            q.pop();

            for (int next : V2[cur]) {
                if (parent[next] == -1 && capacities[cur][next] > 0) {
                    parent[next] = cur;
                    int new_flow = std::min(flow, capacities[cur][next]);
                    if (next == sink)
                        return new_flow;

                    q.push({next, new_flow});
                }
            }
        }

        return 0;
    }
};

int main(int argc, char* argv[]) {
    auto args = cmdline_args(argc, argv);

    // Plik zbiorczy na czas działania w zależności od k dla każdego i
    std::ofstream totalTimeFile("time_vs_k.csv");
    totalTimeFile << "i,k,AvgTime\n";

    int repetitions = 5;

    for (size_t i = 1; i <= args.degree; i++) {
        for (int k = i; k <= args.size; k++) {
            double totalTime = 0.0;

            for (int rep = 0; rep < repetitions; rep++) {
                Graph graph(k, i);

                auto start = std::chrono::high_resolution_clock::now();
                int maxFlow = graph.maxFlow();
                auto end = std::chrono::high_resolution_clock::now();

                std::chrono::duration<double> elapsed = end - start;
                totalTime += elapsed.count();
            }

            double avgTime = totalTime / repetitions;
            totalTimeFile << i << "," << k << "," << avgTime << "\n";
        }
    }

    totalTimeFile.close();
    return 0;
}
