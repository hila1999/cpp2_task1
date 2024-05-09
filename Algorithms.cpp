#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include "Graph.hpp"
#include "Algorithms.hpp"
#include <climits> // for INT_MAX
#include <cstddef> // for SIZE_MAX
using namespace std;
using namespace ariel;
    void Algorithms::dfs(const std::vector<std::vector<int>>& adjacencyMatrix, std::vector<bool>& visited, int vertex) {
        visited[static_cast<std::vector<bool>::size_type>(vertex)] = true; // Mark the current vertex as visited
        for (std::size_t i = 0; i < adjacencyMatrix[static_cast<std::vector<std::vector<int>>::size_type>(vertex)].size(); ++i) {
            if (adjacencyMatrix[static_cast<std::vector<std::vector<int>>::size_type>(vertex)][i] && !visited[i]) {
                dfs(adjacencyMatrix, visited, static_cast<int>(i)); // Recursively visit adjacent vertices
            }
        }
    }
    bool Algorithms::isConnected(const Graph& g) {
        const std::vector<std::vector<int>>& adjacencyMatrix = g.getAdjacencyMatrix();
        if (adjacencyMatrix.empty()) {
            return false; // An empty graph is not connected
        }
        std::vector<bool> visited(adjacencyMatrix.size(), false);
        dfs(adjacencyMatrix, visited, 0);
        for (bool isVisited : visited) {
            if (!isVisited) {
                return false; // If any vertex is not visited, the graph is not connected
            }
        }
        return true; // If all vertices are visited, the graph is connected
    }
//    bool Algorithms::dfss(Graph& g, int u, std::vector<int>& parent, std::unordered_set<int>& visited, std::vector<int>& cycle) {
//     visited.insert(u);
//     const std::vector<int>& neighbors = g.neighbors(u);
//     for (int v : neighbors) {
//         if (visited.find(v) == visited.end()) {
//            parent[static_cast<size_t>(v)] = u; // Convert v to size_type
//             if (dfss(g, v, parent, visited, cycle)) {
//                 return true;
//             }
//         } else if (parent[static_cast<std::size_t>(u)] != v && v != u) { // Convert u to size_type
//             // Found a back edge
//             int cur = u;
//             while (cur != parent[static_cast<std::size_t>(v)]) { // Convert v to size_type
//                 cycle.push_back(cur);
//                 cur = parent[static_cast<std::size_t>(cur)];

//             }
//             cycle.push_back(parent[static_cast<std::size_t>(v)]);
//             cycle.push_back(u);
//             std::reverse(cycle.begin(), cycle.end());
//             return true;
//        } else if (parent[static_cast<std::size_t>(u)] == v) { // Handle self-loop
//             // Skip self-loop and continue
//             continue;
//         }
//     }
//     return false;
// }

// std::pair<bool, std::vector<int>> Algorithms::isContainsCycle(Graph& g) {
//     size_t n = static_cast<size_t>(g.size());// Use size_t for n
//     std::vector<int> parent(n, -1);
//     std::unordered_set<int> visited;
//     std::vector<int> cycle;

//     for (std::size_t i = 0; i < n; ++i) { // Use size_t for loop index
//         if (visited.find(static_cast<int>(i)) == visited.end()) {
//             if (dfss(g, static_cast<int>(i), parent, visited, cycle)) {
//                 return std::make_pair(true, cycle); // Return early if cycle found
//             }
//         }
//     }
//     cycle.clear();
//     return std::make_pair(false, cycle);
// }
// void Algorithms::printisContainsCycle(Graph& g) {
//         auto result = isContainsCycle(g);
//         bool hasCycle = result.first;
//         std::vector<int> cycle = result.second;

//         if (hasCycle) {
//             std::cout << "The cycle is: ";
//             for (std::size_t i = 0; i < cycle.size(); ++i) {
//                 // Adjust the index value and skip negative indices
//                 if (cycle[i] >= 0) {
//                     std::cout << cycle[i];
//                     if (i != cycle.size() - 1 && cycle[i] >= 0) {
//                         std::cout << "->";
//                     }
//                 }
//             }
//             std::cout << std::endl;
//         } else {
//             std::cout << hasCycle << std::endl;
//         }
//     }
// } // namespace


bool Algorithms::dfss(Graph& graph, int u, std::vector<int>& parent,std::unordered_set<int>& visited, std::vector<int>& cycle) {
        visited.insert(u);
        std::vector<int> neighbors = graph.neighbors(u);
        for (std::size_t v = 0; v < neighbors.size(); ++v) {
                if (visited.find(static_cast<int>(v)) == visited.end()) {
                    parent[static_cast<std::size_t>(v)] = u;
                    if (dfss(graph, static_cast<int>(v), parent, visited, cycle)) {
                        return true;
                    }
                } 
                    else if (static_cast<std::size_t>(parent[static_cast<std::size_t>(u)]) != v &&  v != u){
                    // Found a back edge
                    int cur = u;
                    while (cur != parent[static_cast<std::size_t>(v)]) {
                        cycle.push_back(cur);
                        cur = parent[static_cast<std::size_t>(cur)];

                    }
                    cycle.push_back(parent[static_cast<std::size_t>(v)]);
                    cycle.push_back(u);
                    std::reverse(cycle.begin(), cycle.end());
                    return true;
                }
        }
        return false;
    }
std::string Algorithms::shortestPath(Graph& graph, int start, int end) {

        int n = graph.size();
        std::vector<int> parent(static_cast<std::vector<int>::size_type>(n), -1);
        std::vector<bool> visited(static_cast<std::vector<bool>::size_type>(n), false);

        std::queue<int> q; // Queue for BFS

        q.push(start);
        visited[static_cast<std::vector<bool>::size_type>(start)] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            if (current == end) {
                std::vector<int> path;
                while (current != -1) {
                    path.push_back(current);
                current = static_cast<int>(parent[static_cast<std::vector<int>::size_type>(current)]);
                }
                 std::reverse(path.begin(), path.end()); 
                std::string result;
                
                for (const int& node : path) {
                    result += std::to_string(node);
                   if (&node != &path.back()) {
                   result += "->";
                       }
                           }

                return result;
            }
              for (int neighbor = 0; neighbor < n; ++neighbor) {
                if (graph.neighbors(current)[static_cast<std::vector<int>::size_type>(neighbor)] != 0 && !visited[static_cast<std::vector<bool>::size_type>(neighbor)]) {
                q.push(neighbor);
                visited[static_cast<std::vector<bool>::size_type>(neighbor)] = true;
                parent[static_cast<std::vector<int>::size_type>(neighbor)] = current;
            }
        }
    }

        // If no path found
        return "-1";
    }
std::string Algorithms::isBipartite(const Graph &g) {
    size_t numNodes = g.size();
    vector<int> colorArr(numNodes, -1);
    std::vector<size_t> setA, setB;

    for (size_t i = 0; i < numNodes; i++) {
        if (colorArr[i] == -1) {
            std::queue<size_t> q;
            q.push(i);
            colorArr[i] = 1;
            while (!q.empty()) {
                size_t u = q.front();
                q.pop();
                std::vector<size_t> neighbors = g.getNeighbors(u);
                for (size_t v : neighbors) {
                    if (colorArr[v] == -1) {
                        colorArr[v] = 1 - colorArr[u];
                        q.push(v);
                    } else if (colorArr[v] == colorArr[u]) {
                        return "0";
                    }
                }
            }
        }
    }

    for (size_t i = 0; i < numNodes; i++) {
        if (colorArr[i] == 1) {
            setA.push_back(i);
        } else {
            setB.push_back(i);
        }
    }

    std::string result = "The graph is bipartite: A={";
    for (size_t i = 0; i < setA.size(); i++) {
        result += std::to_string(setA[i]);
        if (i != setA.size() - 1) {
            result += ", ";
        }
    }
    result += "}, B={";
    for (size_t i = 0; i < setB.size(); i++) {
        result += std::to_string(setB[i]);
        if (i != setB.size() - 1) {
            result += ", ";
        }
    }
    result += "}";
    return result;
}

bool Algorithms::isCyclicUtil(size_t v, std::vector<bool>& visited, std::vector<bool>& recStack, std::vector<size_t >& parent, const Graph& g, std::vector<size_t >& cycle) {
    visited[v] = true;
    recStack[v] = true;
    bool isDirected = g.isDirected();

    size_t numNodes = g.size();
    for (size_t i = 0; i < numNodes; i++) {
        if (g.isEdge(v, i)) {  // Check if there is an edge from v to i
            if (!visited[i]) {
                parent[i] = v;
                if (isCyclicUtil(i, visited, recStack, parent, g, cycle)) {
                    return true;
                }
            } else if ((isDirected && recStack[i]) || (!isDirected && recStack[i] && parent[v] != i)) {
                // If a cycle is detected, trace back to print the cycle
                cycle.push_back(i);
                for (size_t p = v; p != i; p = parent[p]) {
                    cycle.push_back(p);
                }
                cycle.push_back(i);  // Complete the cycle by adding the start node again
                std::reverse(cycle.begin(), cycle.end());

                // Print the cycle path
                std::cout << "Cycle detected: ";
                for (size_t j = 0; j < cycle.size(); j++) {
                    std::cout << cycle[j];
                    if (j < cycle.size() - 1) std::cout << " -> ";
                }
                std::cout << std::endl;

                return true;
            }
        }
    }

    recStack[v] = false;
    return false;
}
bool Algorithms::isContainsCycle(const Graph& g) {
    size_t numNodes = g.size();
    std::vector<bool> visited(numNodes, false);
    std::vector<bool> recStack(numNodes, false);
    std::vector<size_t > parent(numNodes, SIZE_MAX);
    std::vector<size_t> cycle;  // To store the path of the cycle

    for (size_t i = 0; i < numNodes; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, visited, recStack, parent, g, cycle)) {
                return true;
            }
        }
    }
    return false;
}

bool Algorithms::bellmanFord(const Graph& g, std::vector<size_t>& dist) {
    const auto& graph = g.getAdjacencyMatrix();
    size_t V = graph.size();
    std::vector<size_t> parent(V, SIZE_MAX); // Change to SIZE_MAX
    for (size_t u = 0; u < V-1; ++u) {
         vector<size_t> neighbors=g.getNeighbors(u);
         for(size_t vertex:neighbors){
            if (graph[u][vertex] != 0 && static_cast<long long>(dist[u]) + graph[u][vertex] < dist[vertex]) {
                dist[vertex] = static_cast<size_t>(static_cast<long long>(dist[u]) + graph[u][vertex]);
                parent[vertex] = u;
            }
        }
    }
      for (size_t u = 0; u < V; ++u) {
        std::vector<size_t> neighbors = g.getNeighbors(u);
        for (size_t vertex : neighbors) {
             if (graph[u][vertex] != 0 && static_cast<long long>(dist[u]) + graph[u][vertex] < dist[vertex]) {
                   return true;
                }
            }
        }
    
    return false;
}
//  size_t cycleStart = SIZE_MAX;
//  for (size_t u = 0; u < V; ++u) {
//         std::vector<size_t> neighbors = g.getNeighbors(u);
//         for (size_t vertex : neighbors) {
//             if (graph[u][vertex] != 0 && static_cast<long long>(dist[u]) + graph[u][vertex] < dist[vertex]) {
//                 cycleStart = vertex;
//                 break; // Exit the loop once a negative cycle is found
//             }
//         }
//         if (cycleStart != SIZE_MAX)
//             break; // Exit the outer loop once a negative cycle is found
//     }

//     if (cycleStart != SIZE_MAX) {
//         // Trace back through the parent pointers to print the cycle vertices
//         std::vector<int> cycle;
//         size_t current = cycleStart;
//         cycle.push_back(current); // Insert the current vertex into the set
//         do {
//             current = parent[current];
//             // Add the current vertex to a temporary vector (optional)
//             cycle.push_back(current);
//           } while (current != SIZE_MAX && current != cycleStart);
//         // Add the starting vertex only once at the end
//         if (current != SIZE_MAX) {
//         cycle.push_back(current);
//         }
//         // Print the vertices of the cycle
//         std::cout << "Negative cycle vertices: ";
//         for (auto vertex : cycle) {
//             std::cout << vertex << " ";
//         }
//         std::cout << std::endl;

//         return true; // Negative cycle found
//     }

//     // If no negative cycle found
//     return false;
// }


void Algorithms::negativeCycle(const Graph& g) {
    const auto& graph = g.getAdjacencyMatrix();
    size_t V = graph.size();
    std::vector<size_t> dist(V, INT_MAX);

    // Start with vertex 0
    dist[0] = 0;

    if (!bellmanFord(g, dist)) {
        std::cout << "No negative cycle found." << std::endl;
    }
  else  std::cout << "Yes negative cycle found." << std::endl;
}






