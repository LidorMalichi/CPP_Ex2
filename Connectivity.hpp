/*
 * Name: Lidor Malichi
 * ID: 318515947
 * Email: lidor673@gmail.com
 */

#ifndef CONNECTIVITY_H
#define CONNECTIVITY_H

#include "Graph.hpp"
#include "SearchAlgorithms.hpp"
#include <vector>

class Connectivity {
private:
    static bool undirected_connectivity(const ariel::Graph &g);
    static bool directed_connectivity(const ariel::Graph &g);

public:
    /**
     * Check if a graph is connected.
     * 
     * @param g The graph to check for connectivity.
     * @return true if the graph is connected, false otherwise.
     */
    static bool connected(const ariel::Graph &g);
};

#endif
