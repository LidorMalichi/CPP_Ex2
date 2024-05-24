/*
 * Name: Lidor Malichi
 * ID: 318515947
 * Email: lidor673@gmail.com
 */
#include "ShortestPathAlgorithms.hpp"

void ShortestPathAlgorithms::relax(size_t u, size_t v, int edgeWeight, vector<int> &d, vector<int> &predecessor)
{
    // Relaxation step: Update distance and predecessor if a shorter path is found
    if(d[v] > d[u] + edgeWeight)
    {
        d[v] = d[u] + edgeWeight;
        predecessor[v] = u;
    }
}

void ShortestPathAlgorithms::dijkstra(const ariel::Graph &g, size_t source, vector<int> &d, vector<int> &predecessor)
{
    priority_queue<pair<size_t, int>, vector<pair<size_t, int>>, Compare> q;

    size_t numVertices = g.getNumVertices();

    // Initialize priority queue with vertices and their corresponding distances
    for(size_t v = 0; v < numVertices; v++)
    {
        q.push({v, d[v]});
    }
    d[source] = 0; 
    
    while(!q.empty())
    {
        pair<size_t, int> u = q.top();
        q.pop();

        for(size_t v = 0; v < numVertices; v++)
        {
            // Perform relaxation for adjacent vertices with non-zero weight edges
            if(g[u.first][v] != 0 && d[u.first] != __INT_MAX__)
            {
                relax(u.first, v, g[u.first][v], d, predecessor);
            }
        }
    }
}

string ShortestPathAlgorithms::bellmanFord(const ariel::Graph &g, size_t source, vector<int> &d, vector<int> &predecessor)
{
    d[source] = 0;

    size_t numVertices = g.getNumVertices();

    // Relaxation process for |V| - 1 iterations
    for(int k = 0; k < numVertices - 1; k++)
    {
        for(size_t u = 0; u < numVertices; u++)
        {
            for(size_t v = 0; v < numVertices; v++)
            {
                // Perform relaxation for edges with non-zero weight and update distances
                if(g[u][v] != 0 && d[u] != __INT_MAX__)
                {
                    relax(u, v, g[u][v], d, predecessor);
                }
            }
        }
    }

    // Check for negative cycles
    for(size_t u = 0; u < numVertices; u++)
    {
        for(size_t v = 0; v < numVertices; v++)
        {
            // If a shorter path is found, return error message indicating a negative cycle
            if(g[u][v] != 0)
            {
                if(d[v] > d[u] + g[u][v]){
                    return "Error: Negative cycle";
                }
            }
        }
    }

    // If no negative cycles are found, return "ok"
    return "ok";
}
