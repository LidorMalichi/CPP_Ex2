/*
 * Name: Lidor Malichi
 * ID: 318515947
 * Email: lidor673@gmail.com
 */

#ifndef SEARCHALGORITHMS_H
#define SEARCHALGORITHMS_H

#include "Graph.hpp"
#include <vector>
#include <queue>

#define TREE_EDGE 'T'
#define BACK_EDGE 'B'
#define FORWARD_EDGE 'F'
#define CROSS_EDGE 'C'
#define VISITED_EDGE 'V'
#define NOT_CLASS 'N'

enum color{
    WHITE, 
    GRAY, 
    BLACK
};

class SearchAlgorithms{

    /**
     * Helper function for depth-first search (DFS) visit.
     * @param vertice The current vertex being visited.
     * @param matrix The adjacency matrix representing the graph.
     * @param predeccesor The predecessor vector for DFS.
     * @param color The color vector for DFS.
     */
    static void dfs_visit(size_t vertice, vector<vector<int>> &matrix, vector<int> &predeccesor, vector<int> &color);

    /**
     * Helper function for depth-first search (DFS) visit with timestamps and edge classification.
     * @param vertice The current vertex being visited.
     * @param matrix The adjacency matrix representing the graph.
     * @param cur_time The current timestamp.
     * @param d The discovery time vector for DFS.
     * @param f The finish time vector for DFS.
     * @param predeccesor The predecessor vector for DFS.
     * @param color The color vector for DFS.
     * @param edgeClass The edge classification vector for DFS.
     * @param isUndirected Flag indicating if the graph is undirected (default: false).
     */
    static void dfs_visit(size_t vertice, vector<vector<int>> &matrix, int &cur_time, vector<int> &d, vector<int> &f, vector<int> &predeccesor, vector<int> &color, vector<vector<char>> &edgeClass, bool isUndirected = false);

public:

    /**
     * Breadth-first search (BFS) algorithm to compute shortest paths from a source vertex.
     * @param matrix The adjacency matrix representing the graph.
     * @param source The source vertex for BFS.
     * @param d The distance vector for BFS.
     * @param predeccesor The predecessor vector for BFS.
     */
    static void bfs(vector<vector<int>> &matrix, size_t source, vector<int> &d, vector<int> &predeccesor);

    /**
     * Depth-first search (DFS) algorithm without timestamps and edge classification.
     * @param matrix The adjacency matrix representing the graph.
     * @param predeccesor The predecessor vector for DFS.
     */
    static void dfs(vector<vector<int>> &matrix, vector<int> &predeccesor);

    /**
     * Depth-first search (DFS) algorithm with timestamps and edge classification.
     * @param matrix The adjacency matrix representing the graph.
     * @param predeccesor The predecessor vector for DFS.
     * @param edgeClass The edge classification vector for DFS.
     * @param isUndirected Flag indicating if the graph is undirected.
     */
    static void dfs(vector<vector<int>> &matrix, vector<int> &predeccesor, vector<vector<char>> &edgeClass, bool isUndirected);
};

#endif
