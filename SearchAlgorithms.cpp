/*
 * Name: Lidor Malichi
 * ID: 318515947
 * Email: lidor673@gmail.com
 */

#include "SearchAlgorithms.hpp"

void SearchAlgorithms::dfs_visit(size_t vertice, vector<vector<int>> &matrix, vector<int> &predecessor, vector<int> &color)
{
    color[vertice] = GRAY; // Mark current vertex as visited

    for(size_t v = 0; v < color.size(); v++)
    {
        if(matrix[vertice][v] != 0 && color[v] == WHITE)
        {
            predecessor[v] = vertice; // Set predecessor for the next vertex in the DFS traversal
            dfs_visit(v, matrix, predecessor, color); // Recursive call for the next vertex
        }
    }
}

void SearchAlgorithms::dfs(vector<vector<int>> &matrix, vector<int> &predecessor)
{
    vector<int> color(matrix[0].size(), WHITE); // Initialize color vector for DFS

    for(size_t v = 0; v < color.size(); v++)
    {
        if(color[v] == WHITE){
            dfs_visit(v, matrix, predecessor, color); // Start DFS traversal from each unvisited vertex
        }
    }
}

void SearchAlgorithms::dfs_visit(size_t vertice, vector<vector<int>> &matrix, int &cur_time, vector<int> &d_time, vector<int> &f_time, vector<int> &predecessor, vector<int> &color, vector<vector<char>> &edgeClass, bool isUndirected)
{
    color[vertice] = GRAY; // Mark current vertex as visited
    cur_time++;
    d_time[vertice] = cur_time; // Set discovery time for the current vertex

    for(size_t v = 0; v < color.size(); v++)
    {
        if(matrix[vertice][v] != 0)
        {
            if(isUndirected && edgeClass[vertice][v] == NOT_CLASS) // Check for undirected graph and unclassified edge
            {
                if(color[v] == GRAY)
                {
                    edgeClass[vertice][v] = BACK_EDGE; // Mark edge as back edge
                    edgeClass[v][vertice] = VISITED_EDGE;
                }
                if(color[v] == WHITE)
                {
                    edgeClass[vertice][v] = TREE_EDGE; // Mark edge as tree edge
                    edgeClass[v][vertice] = VISITED_EDGE;
                    predecessor[v] = vertice; // Set predecessor for the next vertex in the DFS traversal
                    dfs_visit(v, matrix, cur_time, d_time, f_time, predecessor, color, edgeClass, isUndirected); // Recursive call for the next vertex
                }
            }
            if(!isUndirected && edgeClass[vertice][v] == NOT_CLASS) // Check for directed graph and unclassified edge
            {
                if(color[v] == BLACK)
                {
                    if(d_time[vertice] < d_time[v])
                    {
                        edgeClass[vertice][v] = FORWARD_EDGE; // Mark edge as forward edge
                    }
                    else
                    {
                        edgeClass[vertice][v] = CROSS_EDGE; // Mark edge as cross edge
                    }
                }
                if(color[v] == GRAY)
                {
                    edgeClass[vertice][v] = BACK_EDGE; // Mark edge as back edge
                }
                if (color[v] == WHITE)
                {
                    edgeClass[vertice][v] = TREE_EDGE; // Mark edge as tree edge
                    predecessor[v] = vertice; // Set predecessor for the next vertex in the DFS traversal
                    dfs_visit(v, matrix, cur_time, d_time, f_time, predecessor, color, edgeClass, isUndirected); // Recursive call for the next vertex
                }
            }
        }
    }

    color[vertice] = BLACK; // Mark current vertex as finished
    cur_time++;
    f_time[vertice] = cur_time; // Set finish time for the current vertex
}

void SearchAlgorithms::dfs(vector<vector<int>> &matrix, vector<int> &predecessor, vector<vector<char>> &edgeClass, bool isUndirected)
{
    size_t numVertice = matrix[0].size();

    vector<int> d_time(numVertice, 0); // Initialize discovery time vector
    vector<int> f_time(numVertice, 0); // Initialize finish time vector
    vector<int> color(numVertice, WHITE); // Initialize color vector for DFS

    int cur_time = 0;

    for(size_t v = 0; v < color.size(); v++)
    {
        if(color[v] == WHITE){
            dfs_visit(v, matrix, cur_time, d_time, f_time, predecessor, color, edgeClass, isUndirected); // Start DFS traversal from each unvisited vertex
        }
    }
}

void SearchAlgorithms::bfs(vector<vector<int>> &matrix, size_t source, vector<int> &d, vector<int> &predecessor)
{
    vector<int> color(matrix.size(), WHITE); // Initialize color vector for BFS

    color[source] = GRAY; // Mark source vertex as visited
    d[source] = 0; // Set distance from source to itself as 0

    queue<size_t> q;
    q.push(source);

    while(!q.empty())
    {
        size_t u = q.front();
        q.pop();

        for(size_t v = 0; v < color.size(); v++)
        {
            if(matrix[u][v] != 0 && color[v] == WHITE)
            {
                color[v] = GRAY; // Mark adjacent vertex as visited
                d[v] = d[u] + 1; // Update distance from source to adjacent vertex
                predecessor[v] = u; // Set predecessor for the adjacent vertex
                q.push(v); // Add adjacent vertex to the queue for further traversal
            }
        }
        color[u] = BLACK; // Mark current vertex as finished
    }
}
