//hila.shamir99@gmail.com  314906983
#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <ostream>
#include <vector>
#include <cstddef>


namespace ariel {
    // class Algorithms; // Forward declaration of Algorithms class

    class Graph {
    private:
        std::vector<std::vector<int>> adjacencyMatrix;
         size_t vertices;

    public:
        Graph() {}
        Graph(const std::vector<std::vector<int>>& graph_data) : adjacencyMatrix(graph_data) {}
        std::vector<size_t> getNeighbors(size_t node) const;
        size_t size() const;
        void loadGraph(const std::vector<std::vector<int>>& matrix);
        void printGraph() const;
        bool isDirected() const;
        std::vector<std::vector<int>> getAdjMatrix();
        const std::vector<std::vector<int>>& getAdjacencyMatrix() const {
            if(adjacencyMatrix.empty())
            {
                throw std::invalid_argument("The graph is empty");
            }
            return adjacencyMatrix;
        }
        bool haveEdge(size_t from, size_t to) const {
            return adjacencyMatrix[from][to] != 0;
        }
        int getA(size_t from, size_t to) const {
            return adjacencyMatrix[from][to] ;
        }
        
       
    };
} // namespace ariel

#endif /* GRAPH_HPP */
