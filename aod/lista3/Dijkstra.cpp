#include <limits>
#include "PriorityQueue.hpp"

#include "Dijkstra.hpp"

std::vector<long long int> Dijkstra::findPath(Graph& graph, int start, int destination) {
    long long int inf = std::numeric_limits<long long int>::max();

    auto vertexSize = graph.getVertexSize();
    auto neighborhood = graph.getNeighborhood();
    std::vector<long long int> distances(vertexSize+1, inf); 
    distances[start] = 0;

    PriorityQueue queue;
    queue.insert(start, 0);

    while (!queue.empty()) {
        auto node = queue.extractMin();
        auto current_dist = node.second;
        auto current_vertex = node.first;

        if (current_dist > distances[current_vertex]) {
            continue;
        }

        for (const auto& [neighbor, weight] : neighborhood[current_vertex]) {

            long long int new_dist = current_dist + weight;

            if (new_dist < distances[neighbor]) {
                if (distances[neighbor] == inf)
                    queue.insert(neighbor, new_dist);
                else queue.decreaseKey(neighbor, new_dist);
                distances[neighbor] = new_dist;
            }
        }
    }
    if(destination != -1){
        std::vector<long long int> dist(1, 0);
        dist[0] = distances[destination];
        return dist;
    }
    return distances;
}