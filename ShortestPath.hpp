/*
 * Name: Lidor Malichi
 * ID: 318515947
 * Email: lidor673@gmail.com
 */

#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include "Graph.hpp"
#include <vector>
#include <string>
#include "SearchAlgorithms.hpp"
#include "ShortestPathAlgorithms.hpp"

class ShortestPath {
public:
    /**
     * Find the shortest path between two vertices in a graph.
     * 
     * @param g The graph.
     * @param source The source vertex.
     * @param destination The destination vertex.
     * @return A string representing the shortest path between source and destination vertices.
     */
    static std::string findShortestPath(const ariel::Graph &g, int source, int destination);

};

#endif
