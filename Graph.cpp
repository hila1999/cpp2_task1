#include <iostream>
#include "Graph.hpp"
using namespace ariel;
    // void Graph::loadGraph(const std::vector<std::vector<int>>& graph) {
    //     this->adjacencyMatrix = graph;
    // }
    void Graph::loadGraph(const std::vector<std::vector<int>>& graph) {
    // Check if the graph is square
    if (graph.size() != graph[0].size()&&graph.size()==0) {
        throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
    }
    this->adjacencyMatrix = graph;
    }

    void Graph::printGraph() const {
        int numVertices = adjacencyMatrix.size();
        int numEdges = 0;
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
            for (size_t j = 0; j < adjacencyMatrix.size(); ++j) {
                if(adjacencyMatrix[i][j]!=0){
                    numEdges += 1;
                }
            }
        }
        
         if (!isDirected()) {
        numEdges /= 2;
    }
        std::cout << "Graph with " << numVertices << " vertices and " << numEdges << " edges." << std::endl;
    }
    bool Graph::isDirected() const {
    for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
            if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i]) {
                return true;
            }
        }
    }
    return false;
}
std::vector<size_t> Graph::getNeighbors(size_t node) const {
    std::vector<size_t> neighbors;
    if (node >= adjacencyMatrix.size()) {
        throw std::out_of_range("Node index out of range");
    }
    for (size_t i = 0; i < adjacencyMatrix[node].size(); ++i) {
        if (adjacencyMatrix[node][i] != 0) {
            neighbors.push_back(i);
        }
    }
    return neighbors;
}
    const std::vector<int> Graph::neighbors(int vertex) {
    static const std::vector<int> empty;
    if (vertex < 0 || vertex >= static_cast<int>(adjacencyMatrix.size())) {
        // Return an empty vector if the vertex index is out of bounds
        return empty;
    }
    return adjacencyMatrix[static_cast<size_t>(vertex)];
}

    size_t Graph::size() const {
        return adjacencyMatrix.size();
    }


