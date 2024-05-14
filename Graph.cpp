/*
 * Name: Lidor Malichi
 * ID: 318515947
 * Email: lidor673@gmail.com
 */

#include "Graph.hpp"

namespace ariel {

    void Graph::loadGraph(vector<vector<int>> matrix)
    {
        // Check if the input matrix is a valid adjacency matrix
        size_t rows = matrix.size();
        if (rows == 0) {
            throw std::invalid_argument("Invalid graph: Graph is not valid.");
        }

        size_t columns = matrix[0].size();
        if (rows != columns) {
            throw std::invalid_argument("Invalid graph: Graph is not valid.");
        }

        for (size_t i = 1; i < rows; i++) {
            if (matrix[i].size() != columns) {
                throw std::invalid_argument("Invalid graph: Graph is not valid.");
            }
        }

        // Load the graph from the input matrix
        this->graph = matrix;
        this->num_of_vertices = rows;
        this->undirected = true;
        this->weightType = Unweighted;

        int numEdges = 0;

        // Check properties of the matrix
        for (size_t i = 0; i < rows; i++) {
            for (size_t j = 0; j < columns; j++) {

                if (matrix[i][j] != 0) {
                    numEdges++;
                }

                if (matrix[i][j] != matrix[j][i]) {
                    this->undirected = false;
                }

                if (matrix[i][j] > 1 && this->weightType == Unweighted) {
                    this->weightType = Weighted;
                }

                if (matrix[i][j] < 0) {
                    this->weightType = NegativeWeighted;
                }
            }
        }

        if (this->undirected) {
            this->num_of_edges = numEdges / 2;
        }
    }

    void Graph::printGraph()
    {
        string s1, s2;

        s1 = "An Undirected ";
        if (!this->undirected) { s1 = "A Directed "; }

        s2 = "Unweighted Graph ";
        if (this->weightType == Weighted) { s2 = "Weighted Graph "; }
        if (this->weightType == NegativeWeighted) { s2 = "Negative Weighted Graph "; }

        cout << s1 << s2 << "with " << this->num_of_vertices << " vertices and " << this->num_of_edges << " edges." << endl;
    }

    int Graph::getNumVertices()
    {
        return this->num_of_vertices;
    }

    int Graph::getNumEdges()
    {
        return this->num_of_edges;
    }

    vector<vector<int>> Graph::getMatrix()
    {
        return this->graph;
    }

    vector<vector<int>> Graph::getTranspose()
    {
        size_t numVertices = static_cast<size_t>(this->num_of_vertices);
        vector<vector<int>> transpose(numVertices, vector<int>(numVertices));

        for (size_t i = 0; i < this->num_of_vertices; i++)
        {
            for (size_t j = 0; j < this->num_of_vertices; j++)
            {
                transpose[i][j] = this->graph[j][i];
            }
        }
        return transpose;
    }

    bool Graph::isUnDirected()
    {
        return this->undirected;
    }

    int Graph::getWeightType()
    {
        return this->weightType;
    }

} // namespace ariel
