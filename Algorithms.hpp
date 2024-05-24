/*
 * Name: Lidor Malichi
 * ID: 318515947
 * Email: lidor673@gmail.com
 */
#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Graph.hpp"  // Include the Graph header file
#include "Connectivity.hpp"  // Include the Connectivity header file
#include "ShortestPath.hpp"  // Include the ShortestPath header file
#include "CycleAlgorithms.hpp"  // Include the CycleAlgorithms header file
#include "BipartiteAlgorithm.hpp"  // Include the BipartiteAlgorithm header file

namespace ariel {
    class Algorithms {
    public:
        // Check if the graph is connected
        static bool isConnected(const Graph &g);

        // Find the shortest path between two vertices
        static std::string shortestPath(const Graph &g, int source, int destination);

        // Check if the graph contains a cycle
        static std::string isContainsCycle(const Graph &g);

        // Check if the graph is bipartite
        static std::string isBipartite(const Graph &g);

        // Check if the graph has a negative cycle
        static std::string negativeCycle(const Graph &g);
    };
}

#endif
