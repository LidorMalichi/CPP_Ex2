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
        size_t num_of_vertices;
        size_t num_of_edges;
        bool undirected;
        WeightType weightType;

        vector<int>& operator[](size_t index);
        
        public:

            /**
             * Loads a graph from a given adjacency matrix.
             * @param matrix The adjacency matrix representing the graph.
             */
            void loadGraph(vector<vector<int>> matrix);

            /**
             * Prints the graph.
             */
            void printGraph() const;

            bool isEmpty() const;

            /**
             * Gets the number of vertices in the graph.
             * @return The number of vertices.
             */
            size_t getNumVertices() const;
            
            /**
             * Gets the number of edges in the graph.
             * @return The number of edges.
             */
            size_t getNumEdges() const;

            /**
             * Gets the adjacency matrix of the graph.
             * @return The adjacency matrix.
             */
            vector<vector<int>> getMatrix() const;

            /**
             * Gets the transpose of the adjacency matrix.
             * @return The transpose of the adjacency matrix.
             */
            vector<vector<int>> getTranspose() const;

            /**
             * Checks if the graph is undirected.
             * @return True if the graph is undirected, false otherwise.
             */
            bool isUnDirected() const;
            
            /**
             * Gets the weight type of the graph.
             * @return The weight type (Unweighted, Weighted, NegativeWeighted).
             */
            int getWeightType() const;

            // [] operator for matrix
            const vector<int>& operator[](size_t index) const;

            // += operator
            Graph& operator+=(const Graph& g2);

            // -= operator
            Graph& operator-=(const Graph& g2);

            // + unary operator
            Graph& operator+();

            // - unary operator
            Graph& operator-();

            // ++ prefix operator
            Graph& operator++();
            
            // ++ postfix operator
            Graph operator++(int);

            // -- prefix operator
            Graph& operator--();

            // -- postfix operator
            Graph operator--(int);

            // *= scalar operator
            Graph& operator*=(int scalar);

            // *= operator
            Graph& operator*=(const Graph& g2);


    };
}

#endif
