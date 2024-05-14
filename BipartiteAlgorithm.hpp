/*
 * Name: Lidor Malichi
 * ID: 318515947
 * Email: lidor673@gmail.com
 */
#ifndef BIPARTITEALGORITHM_H
#define BIPARTITEALGORITHM_H

#include "Graph.hpp"  // Include the header file for Graph class
#include <vector>     // Include the vector library for using vectors
#include <string>     // Include the string library for using strings
#include <queue>      // Include the queue library for using queues

// Enum to represent colors for the Bipartite algorithm
enum colorBi {
    RED,   
    BLUE   
};

class BipartiteAlgorithm {
public:
    // Function to check if the graph is bipartite and return a string indicating the result
    static std::string Bipartite(ariel::Graph &g);
};

#endif
