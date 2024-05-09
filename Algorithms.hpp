#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include <string> 
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include "Graph.hpp"
namespace ariel {
    // Declare the Algorithms namespace or class
    class Algorithms {
    public:
    static bool isConnected(const Graph& g);
    static std::string shortestPath(Graph& graph, int start, int end) ;
    static std::string isBipartite(const Graph& g) ;
    // static std::pair<bool, std::vector<int>> isContainsCycle( Graph& g);
    static void printisContainsCycle(Graph& g);
    static bool isContainsCycle(const Graph& g);
    static void negativeCycle(const Graph& g) ;

    private:
    static void dfs(const std::vector<std::vector<int> >&, std::vector<bool>&, int);
    static bool dfss( Graph& g, int u, std::vector<int>& parent, std::unordered_set<int>& visited, std::vector<int>& cycle);
    static void DFS(const Graph& g, size_t node, std::vector<bool>& visited);
    static bool isCyclicUtil(size_t v, std::vector<bool>& visited, std::vector<bool>& recStack, std::vector<size_t >& parent, const Graph& g, std::vector<size_t>& cycle);  
    static bool bellmanFord(const Graph& g, std::vector<size_t>& dist);

    };
}

        // Declare functions or members here
 

#endif /* ALGORITHMS_HPP */
