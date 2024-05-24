/*
 * Name: Lidor Malichi
 * ID: 318515947
 * Email: lidor673@gmail.com
 */
#include "Algorithms.hpp"

// Check if the graph is connected using the Connectivity class.
bool ariel::Algorithms::isConnected(const Graph &g)
{
    return Connectivity::connected(g);
}

// Find the shortest path between two vertices using the ShortestPath class.
string ariel::Algorithms::shortestPath(const Graph &g, int source, int destination)
{
    return ShortestPath::findShortestPath(g, source, destination);   
}

// Check if the graph contains a cycle using the CycleAlgorithms class.
string ariel::Algorithms::isContainsCycle(const Graph &g)
{
    return CycleAlgorithms::findCycle(g);
}

// Check if the graph is bipartite using the BipartiteAlgorithm class.
string ariel::Algorithms::isBipartite(const Graph &g)
{
    return BipartiteAlgorithm::Bipartite(g);
}

// Check if the graph contains a negative cycle using the CycleAlgorithms class.
string ariel::Algorithms::negativeCycle(const Graph &g)
{
    return CycleAlgorithms::findCycle(g, true);
}
