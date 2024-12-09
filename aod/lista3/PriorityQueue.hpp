#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>

class PriorityQueue {
public:
    using Vertex = int;
    using Cost = long long int;
    using Pair = std::pair<Vertex, Cost>;

private:
    std::vector<Pair> heap;
    std::unordered_map<Vertex, size_t> vertexPosition;

    void heapifyUp(size_t idx) {
        while (idx > 0) {
            size_t parent = (idx - 1) / 2;
            if (heap[idx].second < heap[parent].second) {
                swap(idx, parent);
                idx = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(size_t idx) {
        size_t smallest = idx;
        size_t left = 2 * idx + 1;
        size_t right = 2 * idx + 2;

        if (left < heap.size() && heap[left].second < heap[smallest].second)
            smallest = left;

        if (right < heap.size() && heap[right].second < heap[smallest].second)
            smallest = right;

        if (smallest != idx) {
            swap(idx, smallest);
            heapifyDown(smallest);
        }
    }

    void swap(size_t i, size_t j) {
        std::swap(heap[i], heap[j]);
        vertexPosition[heap[i].first] = i;
        vertexPosition[heap[j].first] = j;
    }

public:
    void insert(Vertex v, Cost cost) {
        if (vertexPosition.count(v)) {
            throw std::runtime_error("Vertex already exists in the priority queue");
        }
        heap.emplace_back(v, cost);
        size_t idx = heap.size() - 1;
        vertexPosition[v] = idx;
        heapifyUp(idx);
    }

    Pair extractMin() {
        if (heap.empty()) {
            throw std::runtime_error("Priority queue is empty");
        }
        Pair minElement = heap.front();
        swap(0, heap.size() - 1);
        heap.pop_back();
        vertexPosition.erase(minElement.first);
        if (!heap.empty()) {
            heapifyDown(0);
        }
        return minElement;
    }

    void decreaseKey(Vertex v, Cost newCost) {
        if (!vertexPosition.count(v)) {
            throw std::runtime_error("Vertex not found in the priority queue");
        }
        size_t idx = vertexPosition[v];
        if (newCost > heap[idx].second) {
            throw std::runtime_error("New cost is greater than current cost");
        }
        heap[idx].second = newCost;
        heapifyUp(idx);
    }

    bool empty() const {
        return heap.empty();
    }
};