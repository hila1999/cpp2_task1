#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <cstddef>


namespace ariel {
    // class Algorithms; // Forward declaration of Algorithms class

    class Graph {
    private:
        std::vector<std::vector<int>> adjacencyMatrix;


    public:
        Graph() {}
        Graph(const std::vector<std::vector<int>>& graph_data) : adjacencyMatrix(graph_data) {}
        std::vector<size_t> getNeighbors(size_t node) const;
        size_t size() const;
        void loadGraph(const std::vector<std::vector<int>>& matrix);
        void printGraph() const;
        bool isDirected() const;
        const std::vector<std::vector<int>>& getAdjacencyMatrix() const {
            return adjacencyMatrix;
        }
        bool haveEdge(size_t from, size_t to) const {
            return adjacencyMatrix[from][to] != 0;
        }
        
        std::vector<std::vector<int>> getAdjMatrix();
    };
} // namespace ariel

#endif /* GRAPH_HPP */
