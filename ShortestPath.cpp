/*
 * Name: Lidor Malichi
 * ID: 318515947
 * Email: lidor673@gmail.com
 */
#include "ShortestPath.hpp"

string ShortestPath::findShortestPath(ariel::Graph &g, int source, int destination)
{
    // Validate input vertices to ensure they are within the valid range
    if (source < 0 || destination < 0 || source >= g.getNumVertices() || destination >= g.getNumVertices())
    {
        throw std::invalid_argument("Vertices not valid!");
    }

    // Convert vertices to size_t for array indexing
    size_t numVertices = static_cast<size_t>(g.getNumVertices());
    size_t s = static_cast<size_t>(source);
    size_t v = static_cast<size_t>(destination);

    // Initialize distance array and predecessor array for shortest path computation
    vector<int> d(numVertices, __INT_MAX__); // Array to store shortest distances
    vector<int> predecessor(numVertices, -1); // Array to store predecessors in shortest path
    vector<vector<int>> matrix = g.getMatrix(); // Adjacency matrix representing the graph

    // Choose the shortest path algorithm based on the weight type of the graph
    switch (g.getWeightType())
    {
        case 0: // Unweighted graph
            SearchAlgorithms::bfs(matrix, s, d, predecessor);
            break;
    
        case 1: // Weighted graph
            ShortestPathAlgorithms::dijkstra(matrix, s, d, predecessor);
            break;

        case 2: // Negative weighted graph
            // Ensure meaningful interpretation for negative weighted graphs
            if (g.isUnDirected())
            {
                throw std::invalid_argument("No meaning for shortest path in Undirected graph with negative weights!");
            }

            // Apply Bellman-Ford algorithm for negative weighted directed graphs
            string valid = ShortestPathAlgorithms::bellmanFord(matrix, s, d, predecessor);
            if (valid != "ok")
            {
                return "-1"; // Error message for negative cycle in the graph
            }
            break;
    }

    // Check if a path exists from source to destination
    if (predecessor[v] == -1)
    {
        return "-1"; // Return -1 if no path exists
    }

    // Reconstruct the shortest path from destination to source
    string shortestPath = "";
    
    while (predecessor[v] != -1)
    {
        shortestPath.insert(0, "->" + to_string(v)); // Append vertex to the path string
        v = static_cast<size_t>(predecessor[v]); // Move to the predecessor
    }
    shortestPath.insert(0, to_string(v)); // Add the source vertex to the beginning of the path
    
    return shortestPath; // Return the shortest path as a string
}
