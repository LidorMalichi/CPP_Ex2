/*
 * Name: Lidor Malichi
 * ID: 318515947
 * Email: lidor673@gmail.com
 */
#include "ShortestPath.hpp"

string ShortestPath::findShortestPath(const ariel::Graph &g, int source, int destination)
{
    // Validate input vertices to ensure they are within the valid range
    if (source < 0 || destination < 0 || source >= g.getNumVertices() || destination >= g.getNumVertices())
    {
        throw std::invalid_argument("Vertices not valid!");
    }

    // Convert vertices to size_t for array indexing
    size_t numVertices = g.getNumVertices();
    size_t s = static_cast<size_t>(source);
    size_t v = static_cast<size_t>(destination);

    // Initialize distance array and predecessor array for shortest path computation
    vector<int> d(numVertices, __INT_MAX__); 
    vector<int> predecessor(numVertices, -1); 
    

    // Choose the shortest path algorithm based on the weight type of the graph
    switch (g.getWeightType())
    {
        // Unweighted graph
        case 0: 
            SearchAlgorithms::bfs(g, s, d, predecessor);
            break;
        // Weighted graph
        case 1: 
            ShortestPathAlgorithms::dijkstra(g, s, d, predecessor);
            break;
        // Negative weighted graph
        case 2: 
            if (g.isUnDirected())
            {
                throw std::invalid_argument("No meaning for shortest path in Undirected graph with negative weights!");
            }

            // Apply Bellman-Ford algorithm for negative weighted directed graphs
            string valid = ShortestPathAlgorithms::bellmanFord(g, s, d, predecessor);
            if (valid != "ok")
            {
                return "-1"; 
            }
            break;
    }

    // Check if a path exists from source to destination
    if (predecessor[v] == -1)
    {
        return "-1"; 
    }

    // Reconstruct the shortest path from destination to source
    string shortestPath = "";
    
    while (predecessor[v] != -1)
    {
        shortestPath.insert(0, "->" + to_string(v)); 
        v = static_cast<size_t>(predecessor[v]); 
    }
    shortestPath.insert(0, to_string(v)); 
    
    return shortestPath; 
}
