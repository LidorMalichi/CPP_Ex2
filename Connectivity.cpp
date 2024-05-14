/*
 * Name: Lidor Malichi
 * ID: 318515947
 * Email: lidor673@gmail.com
 */
#include "Connectivity.hpp"

bool Connectivity::connected(ariel::Graph &g)
{
    // Check if the graph is undirected
    if(g.isUnDirected())
    {
        return undirected_connectivity(g);
    }

    // Check if the graph is directed
    return directed_connectivity(g);
}

bool Connectivity::undirected_connectivity(ariel::Graph &g)
{
    size_t numVertice = static_cast<size_t>(g.getNumVertices());

    // Initialize predecessor vector and get the adjacency matrix of the graph
    vector<int> predecessor(numVertice, -1);
    vector<vector<int>> matrix = g.getMatrix();

    // Perform Depth-First Search (DFS) on the graph to find connected components
    SearchAlgorithms::dfs(matrix, predecessor);

    int count = 0;

    // Count the number of disconnected components found during DFS
    for(size_t i = 0; i < numVertice; i++)
    {
        if(predecessor[i] == -1)
        {
            count++;
        }
    }

    // If there are more than 1 disconnected component, the graph is not connected
    if(count > 1)
    {
        return false;
    }
    
    // The graph is connected
    return true;
}

bool Connectivity::directed_connectivity(ariel::Graph &g)
{
    size_t numVertice = static_cast<size_t>(g.getNumVertices());

    // Initialize predecessor vector and get the adjacency matrix of the graph
    vector<int> predecessor(numVertice, -1);
    vector<vector<int>> matrix = g.getMatrix();

    // Perform DFS on the graph to find connected components
    SearchAlgorithms::dfs(matrix, predecessor);

    int count1 = 0;

    // Count the number of disconnected components found during the first DFS
    for(size_t i = 0; i < numVertice; i++)
    {
        if(predecessor[i] == -1)
        {
            count1++;
        }
    }

    // Get the transpose of the adjacency matrix for directed graphs
    vector<vector<int>> transpose = g.getTranspose();

    // Perform DFS on the transpose graph to find connected components
    SearchAlgorithms::dfs(transpose, predecessor);

    int count2 = 0;

    // Count the number of disconnected components found during DFS on the transpose graph
    for(size_t i = 0; i < numVertice; i++)
    {
        if(predecessor[i] == -1)
        {
            count2++;
        }
    }
    
    // If the sum of disconnected components from both DFS is less than or equal to 2, the graph is connected
    return count1 + count2 <= 2;
}
