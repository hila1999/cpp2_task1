#include <iostream>
#include "Graph.hpp"
using namespace ariel;

// Loads an adjacency matrix into the graph
void Graph::loadGraph(const std::vector<std::vector<int>>& matrix) {
    if (matrix.empty()) {
        throw std::invalid_argument("The graph cannot be empty");
    }
    // Check if the matrix is square
    size_t size = matrix.size();
    for (const auto& row : matrix) {
        if (row.size() != size) {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
    }
    
    // If the matrix is square, load it into the adjacencyMatrix
    this->adjacencyMatrix = matrix;
}

// Prints the graph's adjacency matrix and basic information
void Graph::printGraph() const {
    unsigned int numVertices = static_cast<unsigned int>(adjacencyMatrix.size());
    int numEdges = 0;

    // Count the number of edges in the graph
    for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < adjacencyMatrix.size(); ++j) {
            if(adjacencyMatrix[i][j] != 0){
                numEdges += 1;
            }
        }
    }
    
    // If the graph is undirected, each edge is counted twice
    if (!isDirected()) {
        numEdges /= 2;
    }
    
    std::cout << "Graph with " << numVertices << " vertices and " << numEdges << " edges." << std::endl;
}

// Checks if the graph is directed
bool Graph::isDirected() const {
    for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
        for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
            if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i]) {
                return true; // If the adjacency matrix is not symmetric, the graph is directed
            }
        }
    }
    return false; // If the adjacency matrix is symmetric, the graph is undirected
}

// Returns the neighbors of a given node
std::vector<size_t> Graph::getNeighbors(size_t node) const {
    std::vector<size_t> neighbors;
    if (node >= adjacencyMatrix.size()) {
        throw std::out_of_range("Node index out of range");
    }
    for (size_t i = 0; i < adjacencyMatrix[node].size(); ++i) {
        if (adjacencyMatrix[node][i] != 0) {
            neighbors.push_back(i); // Add all nodes that have an edge from the given node
        }
    }
    return neighbors;
}

// Returns the number of vertices in the graph
size_t Graph::size() const {
    return adjacencyMatrix.size();
}

// Returns the adjacency matrix of the graph
std::vector<std::vector<int>> Graph::getAdjMatrix() {
    return this->adjacencyMatrix;
}
