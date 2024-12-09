#include <algorithm>

#include "RadixHeapAlgorithm.hpp"
#include "RadixHeap.hpp"

std::vector<long long int> RadixHeapAlgorithm::findPath(Graph &graph, int start, int destination) {
    auto adjacency = graph.getNeighborhood();
    auto INF = std::numeric_limits<long long int>::max();
    auto size = adjacency.size();
    std::vector<long long int> dist(size, INF);
    std::vector<long long int> prev(size, -1);
    RadixHeap heap;

    dist[start] = 0;
    heap.push(0, start);

    while (!heap.empty()) {
        long long int current_cost = heap.top_key();
        int current_vertex = heap.top_value();
        heap.pop();

        if (current_cost > dist[current_vertex]) continue;

        for (const auto &[neighbor, weight] : adjacency[current_vertex]) {
            long long int new_cost = current_cost + weight;                

            if (new_cost < dist[neighbor]) {

                dist[neighbor] = new_cost;
                prev[neighbor] = current_vertex;
                heap.push(new_cost, neighbor);
            }
        }
    }

    if (destination != -1 && dist[destination] == INF) {
        return {};
    }

    // if (destination != -1) {
    //     std::vector<long long int> path;
    //     for (int v = destination; v != -1; v = prev[v]) {
    //         path.push_back(v);
    //     }
    //     std::reverse(path.begin(), path.end());
    //     return path;
    // }

    if(destination != -1){
        std::vector<long long int> distances(1, 0);
        distances[0] = dist[destination];
        return distances;
    }

    return dist;
}