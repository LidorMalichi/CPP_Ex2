/*
 * Name: Lidor Malichi
 * ID: 318515947
 * Email: lidor673@gmail.com
 */

#include "SearchAlgorithms.hpp"

void SearchAlgorithms::dfs_visit(size_t vertice, const ariel::Graph &g, vector<int> &predecessor, vector<int> &color)
{
    color[vertice] = GRAY; 

    for(size_t v = 0; v < color.size(); v++)
    {
        if(g[vertice][v] != 0 && color[v] == WHITE)
        {
            predecessor[v] = vertice; 
            dfs_visit(v, g, predecessor, color); 
        }
    }
}

void SearchAlgorithms::dfs(const ariel::Graph &g, vector<int> &predecessor)
{
    // Initialize color vector for DFS
    vector<int> color(g.getNumVertices(), WHITE); 

    for(size_t v = 0; v < color.size(); v++)
    {
        if(color[v] == WHITE){
            dfs_visit(v, g, predecessor, color);
        }
    }
}

void SearchAlgorithms::dfs_visit(size_t vertice, const ariel::Graph &g, int &cur_time, vector<int> &d_time, vector<int> &f_time, vector<int> &predecessor, vector<int> &color, vector<vector<char>> &edgeClass, bool isUndirected)
{
    color[vertice] = GRAY; 
    cur_time++;
    d_time[vertice] = cur_time; 

    //Classify every edge on the graph while performing dfs traversal
    for(size_t v = 0; v < color.size(); v++)
    {
        if(g[vertice][v] != 0 && edgeClass[vertice][v] == NOT_CLASS)
        {
            if(isUndirected)
            {
                if(color[v] == GRAY)
                {
                    edgeClass[vertice][v] = BACK_EDGE; 
                    edgeClass[v][vertice] = VISITED_EDGE;
                }
                else if(color[v] == WHITE)
                {
                    edgeClass[vertice][v] = TREE_EDGE; 
                    edgeClass[v][vertice] = VISITED_EDGE;
                    predecessor[v] = vertice; 
                    dfs_visit(v, g, cur_time, d_time, f_time, predecessor, color, edgeClass, isUndirected); 
                }
            }
            else
            {
                switch(color[v])
                {
                    case BLACK:
                    {
                        edgeClass[vertice][v] = d_time[vertice] < d_time[v] ? FORWARD_EDGE : CROSS_EDGE;
                        break;
                    }
                    case GRAY:
                    {
                        edgeClass[vertice][v] = BACK_EDGE;
                        break; 
                    }
                    case WHITE:
                    { 
                        edgeClass[vertice][v] = TREE_EDGE; 
                        predecessor[v] = vertice; 
                        dfs_visit(v, g, cur_time, d_time, f_time, predecessor, color, edgeClass, isUndirected);
                        break; 
                    }
                }
                
            }
        }
    }

    color[vertice] = BLACK; 
    cur_time++;
    f_time[vertice] = cur_time; 
}

void SearchAlgorithms::dfs(const ariel::Graph &g, vector<int> &predecessor, vector<vector<char>> &edgeClass, bool isUndirected)
{
    // Initialize discovery time, finish time and color vector for DFS
    size_t numVertice = g.getNumVertices();

    vector<int> d_time(numVertice, 0); 
    vector<int> f_time(numVertice, 0); 
    vector<int> color(numVertice, WHITE); 

    int cur_time = 0;

    for(size_t v = 0; v < color.size(); v++)
    {
        if(color[v] == WHITE){
            dfs_visit(v, g, cur_time, d_time, f_time, predecessor, color, edgeClass, isUndirected); 
        }
    }
}

void SearchAlgorithms::bfs(const ariel::Graph &g, size_t source, vector<int> &d, vector<int> &predecessor)
{
    vector<int> color(g.getNumVertices(), WHITE); 

    color[source] = GRAY; 
    d[source] = 0; 

    queue<size_t> q;
    q.push(source);

    while(!q.empty())
    {
        size_t u = q.front();
        q.pop();

        for(size_t v = 0; v < color.size(); v++)
        {
            if(g[u][v] != 0 && color[v] == WHITE)
            {
                color[v] = GRAY; 
                d[v] = d[u] + 1; 
                predecessor[v] = u; 
                q.push(v); 
            }
        }
        color[u] = BLACK; 
    }
}
