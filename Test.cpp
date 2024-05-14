#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test isConnected")
{
    // Undirected connected graph
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    
    // Undirected not connected graph
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);

    // Directed strongly connected graph
    vector<vector<int>> graph3 = {
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    // Directed  not Strongly connected graph
    vector<vector<int>> graph4 = {
        {0, 1, 1, 0, 0},
        {5, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 7, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isConnected(g) == false);




}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;

    // Undirected graph with valid path
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    // Undirected graph with no path
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");


    // Undirected graph with negative edges
    vector<vector<int>> graph3 = {
        {0, -1, 1, 0, 0},
        {-1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK_THROWS(ariel::Algorithms::shortestPath(g, 0, 4));

    // Directed graph without cycles with negative edges and no valid path
    vector<vector<int>> graph4 = {
    {0, 3, 0, 0, 0},
    {0, 0, 2, 0, 0},
    {0, 0, 0, -1, 0},
    {0, 0, 0, 0, 2},
    {0, 0, 0, 0, 0}};

    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 0)== "-1");

    // Directed graph with positive cycle and negative edges
    vector<vector<int>> graph5 = {
    {0, 3, 0, 0, 0},
    {0, 0, 2, 0, 0},
    {10, 0, 0, -1, 0},
    {0, 0, 0, 0, 2},
    {0, 0, 0, 0, 0}};

    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 0)== "1->2->0");

    vector<vector<int>> graph6 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};

     g.loadGraph(graph6);
     CHECK(ariel::Algorithms::shortestPath(g, 0, 4)== "0->2->3->4");

    // Directed graph with negative cycle
    vector<vector<int>> graph7 = {
    {0, 3, 0, 0, 0},
    {0, 0, 2, 0, 0},
    {-10, 0, 0, -1, 0},
    {0, 0, 0, 0, 2},
    {0, 0, 0, 0, 0}};

    g.loadGraph(graph7);
    CHECK(ariel::Algorithms::shortestPath(g, 1, 0)== "-1");
    
    // Source too big

    CHECK_THROWS(ariel::Algorithms::shortestPath(g, 10, 0));

}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;

    // Undirected graph no cycle
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");

    // Undirected graph with a positive cycle
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->2->0");

    // Undirected graph with negative cycle
    vector<vector<int>> graph3 = {
    {0,-5, 1, 0, 0},
    {-5, 0, 1, 0, 0},
    {1, 1, 0, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}};


    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isContainsCycle(g)== "0->1->2->0");

    // Directed graph without cycles with negative edges
    vector<vector<int>> graph4 = {
    {0, 3, 0, 0, 0},
    {0, 0, 2, 0, 0},
    {0, 0, 0, -1, 0},
    {0, 0, 0, 0, 2},
    {0, 0, 0, 0, 0}};

    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isContainsCycle(g)== "0");

    // Directed graph positive cycle and negative edges
    vector<vector<int>> graph5 = {
    {0, 3, 0, 0, 0},
    {0, 0, 2, 0, 0},
    {0, 0, 0, -1, 0},
    {2, 0, 0, 0, 2},
    {0, 0, 0, 0, 0}};

    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isContainsCycle(g)== "0->1->2->3->0");



}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph4 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 4}, B={1, 3}");

    // Undirected graph with negative odd cycle
    vector<vector<int>> graph5 = {
    {0,-5, 1, 0, 0},
    {-5, 0, 1, 0, 0},
    {1, 1, 0, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}};


    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isBipartite(g)== "0");
    

    // Undirected graph with negative even cycle
    vector<vector<int>> graph6 = {
    {0,-5, 0, 1, 0},
    {-5, 0, 1, 0, 0},
    {0, 1, 0, 1, 0},
    {1, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}};


    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::isBipartite(g)== "The graph is bipartite: A={0, 2, 4}, B={1, 3}");

}

TEST_CASE("Test negativeCycle")
{
    ariel::Graph g;

    // Undirected graph no cycle
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");


    // Undirected graph with positive cycle
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::negativeCycle(g) == "0");

    // Undirected graph with negative cycle
    vector<vector<int>> graph3 = {
    {0,-5, 1, 0, 0},
    {-5, 0, 1, 0, 0},
    {1, 1, 0, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}};


    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::negativeCycle(g)== "0->1->2->0");

    // Directed graph with negative edges without cycles 
    vector<vector<int>> graph4 = {
    {0, 3, 0, 0, 0},
    {0, 0, 2, 0, 0},
    {0, 0, 0, -1, 0},
    {0, 0, 0, 0, 2},
    {0, 0, 0, 0, 0}};

    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::negativeCycle(g)== "0");

    // Directed graph positive cycle with negative edges
    vector<vector<int>> graph5 = {
    {0, 3, 0, 0, 0},
    {0, 0, 2, 0, 0},
    {0, 0, 0, -1, 0},
    {2, 0, 0, 0, 2},
    {0, 0, 0, 0, 0}};

    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::negativeCycle(g)== "0");

    // Directed graph with negative cycle
    vector<vector<int>> graph6 = {
    {0,-5, 1, 0, 0},
    {2, 0, 1, 0, 0},
    {1, 1, 0, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}};


    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::negativeCycle(g)== "0->1->0");





}

TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}