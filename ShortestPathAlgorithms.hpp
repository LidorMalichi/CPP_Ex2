/*
 * Name: Lidor Malichi
 * ID: 318515947
 * Email: lidor673@gmail.com
 */

#ifndef SHORTESTPATHALGORITHMS_H
#define SHORTESTPATHALGORITHMS_H

#include "Graph.hpp"
#include <vector>
#include <queue>
#include <string>

class ShortestPathAlgorithms {
private:
    struct Compare {
        bool operator()(const std::pair<unsigned long, int>& a, const std::pair<unsigned long, int>& b) const {
            return a.first > b.first; // Compare based on the first element of the pair (unsigned long)
        }
    };

    static void relax(size_t u, size_t v, int edgeWeight, vector<int> &d, vector<int> &predecessor);

public:
    /**
     * Perform Dijkstra's algorithm to find the shortest paths from a source vertex to all other vertices in a graph.
     * 
     * @param matrix The adjacency matrix of the graph.
     * @param source The index of the source vertex.
     * @param d Vector to store the shortest distances from the source vertex.
     * @param predecessor Vector to store the predecessors of vertices in the shortest paths.
     */
    static void dijkstra(const ariel::Graph &g, size_t source, vector<int> &d, vector<int> &predecessor);

    /**
     * Perform Bellman-Ford algorithm to find the shortest paths from a source vertex to all other vertices in a graph.
     * 
     * @param matrix The adjacency matrix of the graph.
     * @param source The index of the source vertex.
     * @param d Vector to store the shortest distances from the source vertex.
     * @param predecessor Vector to store the predecessors of vertices in the shortest paths.
     * @return A string indicating the presence of negative cycles in the graph.
     */
    static std::string bellmanFord(const ariel::Graph &g, size_t source, vector<int> &d, vector<int> &predecessor);
};

#endif
