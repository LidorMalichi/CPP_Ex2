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

void ShortestPathAlgorithms::dijkstra(vector<vector<int>> &matrix, size_t source, vector<int> &d, vector<int> &predecessor)
{
    priority_queue<pair<size_t, int>, vector<pair<size_t, int>>, Compare> q;

    // Initialize priority queue with vertices and their corresponding distances
    for(size_t v = 0; v < matrix[0].size(); v++)
    {
        q.push({v, d[v]});
    }
    d[source] = 0; // Set distance of source vertex to 0
    
    while(!q.empty())
    {
        pair<size_t, int> u = q.top();
        q.pop();

        for(size_t v = 0; v < matrix[0].size(); v++)
        {
            // Perform relaxation for adjacent vertices with non-zero weight edges
            if(matrix[u.first][v] != 0 && d[u.first] != __INT_MAX__)
            {
                relax(u.first, v, matrix[u.first][v], d, predecessor);
            }
        }
    }
}

string ShortestPathAlgorithms::bellmanFord(vector<vector<int>> &matrix, size_t source, vector<int> &d, vector<int> &predecessor)
{
    d[source] = 0; // Set distance of source vertex to 0

    // Relaxation process for |V| - 1 iterations
    for(int k = 0; k < matrix[0].size() - 1; k++)
    {
        for(size_t u = 0; u < matrix[0].size(); u++)
        {
            for(size_t v = 0; v < matrix[0].size(); v++)
            {
                // Perform relaxation for edges with non-zero weight and update distances
                if(matrix[u][v] != 0 && d[u] != __INT_MAX__)
                {
                    relax(u, v, matrix[u][v], d, predecessor);
                }
            }
        }
    }

    // Check for negative cycles
    for(size_t u = 0; u < matrix[0].size(); u++)
    {
        for(size_t v = 0; v < matrix[0].size(); v++)
        {
            // If a shorter path is found, return error message indicating a negative cycle
            if(matrix[u][v] != 0)
            {
                if(d[v] > d[u] + matrix[u][v]){
                    return "Error: Negative cycle";
                }
            }
        }
    }

    // If no negative cycles are found, return "ok"
    return "ok";
}
