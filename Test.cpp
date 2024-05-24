#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include "GraphOperators.hpp"
#include <sstream>

using namespace std;

// EX1 TESTS

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


// EX2 TESTS

TEST_CASE("Test graph addition")
{
    stringstream ss;

    //Check addition and creating a new garph
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);

    ariel::Graph g3 = g1 + g2;
    
    ss << g3;    
    CHECK(ss.str() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]\n");
    CHECK(ariel::Algorithms::isContainsCycle(g3) == "0->1->2->0");

    ss.str("");

    //Check addition to an already existing graph
    g1 += g2;
    ss << g1;
    CHECK(ss.str() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]\n");
    CHECK(ariel::Algorithms::shortestPath(g1, 0, 2) == "0->2");
    
}

TEST_CASE("Test graph subtraction")
{
    stringstream ss;

    //Check subtraction and creating a new garph
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);
    CHECK(ariel::Algorithms::shortestPath(g1, 0, 2) == "0->1->2");

    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, -1, 0},
        {-1, 0, 1},
        {0, 1, 0}};
    g2.loadGraph(graph2);

    ariel::Graph g3 = g1 - g2;
    ss << g3;    
    CHECK(ss.str() == "[0, 2, 0]\n[2, 0, 0]\n[0, 0, 0]\n");
    CHECK(ariel::Algorithms::shortestPath(g3, 0, 2) == "-1");

    ss.str("");

    //Check subtraction to an already existing graph
    g1 -= g2;
    ss << g1;
    CHECK(ss.str() == "[0, 2, 0]\n[2, 0, 0]\n[0, 0, 0]\n");
    CHECK(ariel::Algorithms::isConnected(g1) == false);

}

TEST_CASE("Test graph multiplication")
{
    stringstream ss;

    //Check multiplication and creating a new garph
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);

    ariel::Graph g3 = g1 * g2;
    
    ss << g3;
    CHECK(ss.str() == "[0, 0, 2]\n[1, 0, 1]\n[1, 0, 0]\n");

    ss.str("");

    ariel::Graph g4;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0}};
    g4.loadGraph(graph2);
    
    ariel::Graph g5;
    vector<vector<int>> graph3 = {
        {0, 1, 1, 0, 1},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph3);

    ariel::Graph g6 = g4 * g5;

    ss << g6;
    CHECK(ss.str() == "[0, 1, 1, 1, 1]\n[2, 0, 1, 2, 1]\n[1, 1, 0, 1, 1]\n[2, 1, 1, 0, 1]\n[1, 1, 1, 1, 0]\n");

    ss.str("");

    //Check multiplication with a scalar and creating a new garph
    ariel::Graph g7 = g1*4;
    ss << g7;
    CHECK(ss.str() == "[0, 4, 0]\n[4, 0, 4]\n[0, 4, 0]\n");

    ss.str("");

    //Check multiplication with a scalar to an already existing graph
    g1 *= 4;
    ss << g1;
    CHECK(ss.str() == "[0, 4, 0]\n[4, 0, 4]\n[0, 4, 0]\n");
}

TEST_CASE("Test graph comparison operators")
{
    // Same size Different number of edges - g2 is bigger
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);

    CHECK(g1 < g2);
    CHECK(g1 <= g2);
    CHECK_FALSE(g1 > g2);
    CHECK_FALSE(g1 == g2);
    CHECK_FALSE(g1 >= g2);

    //g2 has more vertices, he is bigger, g1 is contained in g2
    vector<vector<int>> weightedGraph2 = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}};
    g2.loadGraph(weightedGraph2);

    CHECK(g1 < g2);
    CHECK(g1 <= g2);
    CHECK_FALSE(g1 > g2);
    CHECK_FALSE(g1 == g2);
    CHECK_FALSE(g1 >= g2);

    //g1 and g2 same size, same number of edges that connects the same vertices - g1 g2 are equal 
    vector<vector<int>> weightedGraph3 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    g2.loadGraph(weightedGraph3);

    CHECK_FALSE(g1 < g2);
    CHECK_FALSE(g1 > g2);
    CHECK(g1 <= g2);
    CHECK(g1 == g2);
    CHECK(g1 >= g2);

    //g1 and g2 same size, same number of edges but connects different vertices - g1 g2 are equal
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 0},
        {0, 0, 0}};
    g2.loadGraph(graph2);

    vector<vector<int>> graph3 = {
        {0, 0, 0},
        {0, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph3);

    CHECK_FALSE(g1 < g2);
    CHECK_FALSE(g1 > g2);
    CHECK(g1 <= g2);
    CHECK(g1 == g2);
    CHECK(g1 >= g2);

    //g1 has more edges but less vertices, g2 is bigger
    vector<vector<int>> graph4 = {
        {0, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}};
    g2.loadGraph(graph4);

    CHECK(g1 < g2);
    CHECK_FALSE(g1 > g2);
}

TEST_CASE("Unary operations")
{
    stringstream ss;

    //Check unary + 
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    +g1;
    ss << g1;
    CHECK(ss.str() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]\n");

    ss.str("");

    //Check unary - 
    -g1;
    ss << g1;
    CHECK(ss.str() == "[0, -1, 0]\n[-1, 0, -1]\n[0, -1, 0]\n");

    ss.str("");

    //Check unary + 
    +g1;
    ss << g1;
    CHECK(ss.str() == "[0, -1, 0]\n[-1, 0, -1]\n[0, -1, 0]\n");
}

TEST_CASE("Test ++ --")
{
    stringstream ss;

    //Check prefix ++
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);

    ariel::Graph g2 = ++g1;
    ss << g1;
    CHECK(ss.str() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]\n");

    ss.str("");

    ss << g2;
    CHECK(ss.str() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]\n");

    ss.str("");

    //Check postfix ++
    ariel::Graph g3 = g1++;
    ss << g1;
    CHECK(ss.str() == "[0, 3, 0]\n[3, 0, 3]\n[0, 3, 0]\n");

    ss.str("");

    ss << g3;
    CHECK(ss.str() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]\n");

    ss.str("");

    //Check prefix -- 
    ariel::Graph g4 = --g1;
    ss << g1; 
    CHECK(ss.str() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]\n");

    ss.str("");

    ss << g4;
    CHECK(ss.str() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]\n");

    ss.str("");

    //Check postfix --
    ariel::Graph g5 = g1--;
    ss << g1;
    CHECK(ss.str() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]\n");

    ss.str("");

    ss << g5;
    CHECK(ss.str() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]\n");

}

TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1},
        {1, 1, 1, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);

    ariel::Graph g7; 
    CHECK_THROWS(g7 + g5);
    CHECK_THROWS(g7 * g5);

    CHECK_THROWS(g5 += g2);
    CHECK_THROWS(g5 -= g2);

    
}