/*
 * Name: Lidor Malichi
 * ID: 318515947
 * Email: lidor673@gmail.com
 */

#ifndef CYCLEALGORITHMS_H
#define CYCLEALGORITHMS_H

#include "Graph.hpp" // Include the Graph header file for using the Graph class
#include <vector> // Include the vector library for using std::vector
#include <string> // Include the string library for using std::string
#include "SearchAlgorithms.hpp" // Include the SearchAlgorithms header file for using search algorithms

class CycleAlgorithms {
public:
    /**
     * @brief Finds a cycle in the given graph.
     * 
     * This function detects a cycle in the graph using depth-first search (DFS) algorithm.
     * If the graph contains a negative cycle and the `negative` parameter is set to true, it will also detect negative cycles.
     * 
     * @param g The graph to search for a cycle in.
     * @param negative Flag indicating whether to search for negative cycles.
     * @return A string indicating the cycle found, or an empty string if no cycle is found.
     */
    static std::string findCycle(ariel::Graph &g, bool negative = false);
};

#endif
