/*
 * Name: Lidor Malichi
 * ID: 318515947
 * Email: lidor673@gmail.com
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
using namespace std;

namespace ariel{

    enum WeightType{Unweighted, Weighted, NegativeWeighted};

    class Graph{

        vector<vector<int>> graph;
        int num_of_vertices;
        int num_of_edges;
        bool undirected;
        WeightType weightType;
        
        public:

            /**
             * Loads a graph from a given adjacency matrix.
             * @param matrix The adjacency matrix representing the graph.
             */
            void loadGraph(vector<vector<int>> matrix);

            /**
             * Prints the graph.
             */
            void printGraph();

            /**
             * Gets the number of vertices in the graph.
             * @return The number of vertices.
             */
            int getNumVertices();
            
            /**
             * Gets the number of edges in the graph.
             * @return The number of edges.
             */
            int getNumEdges();

            /**
             * Gets the adjacency matrix of the graph.
             * @return The adjacency matrix.
             */
            vector<vector<int>> getMatrix();

            /**
             * Gets the transpose of the adjacency matrix.
             * @return The transpose of the adjacency matrix.
             */
            vector<vector<int>> getTranspose();

            /**
             * Checks if the graph is undirected.
             * @return True if the graph is undirected, false otherwise.
             */
            bool isUnDirected();
            
            /**
             * Gets the weight type of the graph.
             * @return The weight type (Unweighted, Weighted, NegativeWeighted).
             */
            int getWeightType();

    };
}

#endif
