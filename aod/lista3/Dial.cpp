
#include <list>
#include <limits>
#include <deque>
#include <algorithm>
#include <map>

#include "Dial.hpp"

// std::vector<long long int> Dial::findPath(Graph& graph, int start, int destination) {
//     auto adjacency = graph.getNeighborhood();
//     long long int inf = std::numeric_limits<long long int>::max();

//     int numVertices = adjacency.size();
//     std::vector<long long int> distances(numVertices, inf);
//     distances[start] = 0;
//     std::vector<bool> visited(numVertices, false);

//     // Dynamiczne kubełki - klucz to indeks kubełka, wartość to deka wierzchołków
//     std::map<long long int, std::deque<int>> buckets;
//     buckets[0].push_back(start);

//     int nodesToFind = numVertices;

//     while (!buckets.empty() && nodesToFind > 0) {
//         // Pobierz najniższy kubełek
//         auto it = buckets.begin();
//         long long int currentBucketId = it->first;
//         auto& currentBucket = it->second;

//         while (!currentBucket.empty()) {
//             int node = currentBucket.back();
//             currentBucket.pop_back();

//             if (visited[node]) continue;

//             visited[node] = true;
//             nodesToFind--;

//             // Przejdź po sąsiadach
//             for (const auto& edge : adjacency[node]) {
//                 int neighbor = edge.first;
//                 long long int weight = edge.second;
//                 long long int newDistance = distances[node] + weight;

//                 if (distances[neighbor] > newDistance) {
//                     distances[neighbor] = newDistance;

//                     // Przenieś do odpowiedniego kubełka
//                     long long int newBucketId = newDistance;
//                     buckets[newBucketId].push_back(neighbor);
//                 }
//             }
//         }

//         // Usuń kubełek, jeśli jest pusty
//         // if (currentBucket.empty()) {
//         //     buckets.erase(it);
//         // }
//     }

//     if(destination != -1){
//         std::vector<long long int> dist(1, 0);
//         dist[0] = distances[destination];
//         return dist;
//     }

//     return distances;
// }

std::vector<long long int> Dial::findPath(Graph& graph, int start, int destination) {
    auto adjacency = graph.getNeighborhood();
    // long long int inf = std::numeric_limits<long long int>::max();

    int numVertices = adjacency.size();
    // int numVertices = graph.getNumVertices();
    int numBuckets = graph.getMaxCost() + 1; 
    std::vector<std::list<int>> buckets(numBuckets);
    std::vector<long long int> distance(numVertices + 1, std::numeric_limits<long long int>::max());
    std::vector<std::list<int>::iterator> positionMap(numVertices + 1);

    distance[start] = 0;
    buckets[0].push_back(start);
    positionMap[start] = buckets[0].begin();

    int currentBucket = 0;
    int processedVertices = 0;

    while (processedVertices < numVertices) {

        int i = currentBucket;

        while (buckets[currentBucket].empty()) {
            currentBucket = (currentBucket + 1) % numBuckets;

            if(i == currentBucket){
                return distance;
            }
        }

        while (!buckets[currentBucket].empty()) {

            int u = buckets[currentBucket].front();
            buckets[currentBucket].pop_front();
            positionMap[u] = std::list<int>::iterator();
            processedVertices++;

            for (auto [v, weight] : adjacency[u]) {
                long long int newDistance = distance[u] + weight;

                if (distance[v] > newDistance) {

                    if (distance[v] != std::numeric_limits<long long int>::max()) {
                        int oldBucket = distance[v] % numBuckets;
                        buckets[oldBucket].erase(positionMap[v]);
                    }

                    distance[v] = newDistance;
                    int newBucket = newDistance % numBuckets;
                    buckets[newBucket].push_back(v);
                    positionMap[v] = std::prev(buckets[newBucket].end());

                }
            }
        }
    }
    if(destination != -1){
        std::vector<long long int> dist(1, 0);
        dist[0] = distance[destination];
        return dist;
    }

    return distance;
}

