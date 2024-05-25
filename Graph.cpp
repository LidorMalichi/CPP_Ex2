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

        size_t numEdges = 0;

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

    void Graph::printGraph() const{
        string s1, s2;

        s1 = "An Undirected ";
        if (!this->undirected) { s1 = "A Directed "; }

        s2 = "Unweighted Graph ";
        if (this->weightType == Weighted) { s2 = "Weighted Graph "; }
        if (this->weightType == NegativeWeighted) { s2 = "Negative Weighted Graph "; }

        cout << s1 << s2 << "with " << this->num_of_vertices << " vertices and " << this->num_of_edges << " edges." << endl;
    }

    bool Graph::isEmpty() const{
        return this->graph.empty();
    }

    size_t Graph::getNumVertices() const{
        return this->num_of_vertices;
    }

    size_t Graph::getNumEdges() const{
        return this->num_of_edges;
    }

    vector<vector<int>> Graph::getMatrix() const{
        return this->graph;
    }

    vector<vector<int>> Graph::getTranspose() const{
        
        vector<vector<int>> transpose(this->num_of_vertices, vector<int>(this->num_of_vertices));

        for (size_t i = 0; i < this->num_of_vertices; i++)
        {
            for (size_t j = 0; j < this->num_of_vertices; j++)
            {
                transpose[i][j] = this->graph[j][i];
            }
        }
        return transpose;
    }

    bool Graph::isUnDirected() const{
        return this->undirected;
    }

    int Graph::getWeightType() const{
        return this->weightType;
    }

    // return g[index] : private function!
    vector<int> &Graph::operator[](size_t index)
    {
        if(isEmpty())
        {
            throw std::invalid_argument("Graph is empty");
        }
        return this->graph[index];
    }

    const vector<int> &Graph::operator[](size_t index) const
    {
        if(isEmpty())
        {
            throw std::invalid_argument("Graph is empty");
        }
        return this->graph[index];
    }

    // return const g[index]
    Graph &Graph::operator+=(const Graph &g2)
    {
        if(isEmpty() || g2.isEmpty())
        {
            throw std::invalid_argument("Graphs are empty");
        }
        else if(this->num_of_vertices!= g2.getNumVertices())
        {
            throw std::invalid_argument("Graphs aren't the same size");
        }

        for (size_t i = 0; i < this->num_of_vertices; i++)
        {
            for (size_t j = 0; j < this->num_of_vertices; j++)
            {
                (*this)[i][j] += g2[i][j];
            }
            
        }
        this->loadGraph(this->getMatrix());
        return *this;
    }

    // this -= g2
    Graph &Graph::operator-=(const Graph &g2)
    {
        if(isEmpty() || g2.isEmpty())
        {
            throw std::invalid_argument("Graphs are empty");
        }
        else if(this->num_of_vertices!= g2.getNumVertices())
        {
            throw std::invalid_argument("Graphs aren't the same size");
        }

        for (size_t i = 0; i < this->num_of_vertices; i++)
        {
            for (size_t j = 0; j < this->num_of_vertices; j++)
            {
                (*this)[i][j] -= g2[i][j];
            }
            
        }
        this->loadGraph(this->getMatrix());
        return *this;
    }

    // +this
    Graph& Graph::operator+()
    {
        if(isEmpty())
        {
            throw std::invalid_argument("Graph is empty");
        }
        return *this;
    }

    // -this
    Graph& Graph::operator-()
    {
        if(isEmpty())
        {
            throw std::invalid_argument("Graph is empty");
        }

        this->weightType = Unweighted;

        for (size_t i = 0; i < this->num_of_vertices; i++)
        {
            for (size_t j = 0; j < this->num_of_vertices; j++)
            {
                (*this)[i][j] = -(*this)[i][j];

                if ((*this)[i][j] > 1 && this->weightType == Unweighted) {
                    this->weightType = Weighted;
                }

                if ((*this)[i][j] < 0) {
                    this->weightType = NegativeWeighted;
                }

            }
            
        }
        
       return *this; 
    }

    // ++this
    Graph &Graph::operator++()
    {
        if(isEmpty())
        {
            throw std::invalid_argument("Graph is empty");
        }
        for (size_t i = 0; i < this->num_of_vertices; i++)
        {
            for (size_t j = 0; j < num_of_vertices; j++)
            {
                if(i != j && (*this)[i][j] != 0)
                {
                    (*this)[i][j]++;
                }
                 
            }
            
        }
        this->loadGraph(this->getMatrix());
        return *this;
        
    }

    // this++
    Graph Graph::operator++(int)
    {
        if(isEmpty())
        {
            throw std::invalid_argument("Graph is empty");
        }

        Graph temp = *this;
        for (size_t i = 0; i < this->num_of_vertices; i++)
        {
            for (size_t j = 0; j < num_of_vertices; j++)
            {
                if(i != j && (*this)[i][j] != 0)
                {
                    (*this)[i][j]++;
                }
                 
            }
            
        }
        this->loadGraph(this->getMatrix());
        return temp;

    }

    // --this
    Graph &Graph::operator--()
    {
        if(isEmpty())
        {
            throw std::invalid_argument("Graph is empty");
        }
        for (size_t i = 0; i < this->num_of_vertices; i++)
        {
            for (size_t j = 0; j < num_of_vertices; j++)
            {
                if(i != j && (*this)[i][j] != 0)
                {
                    (*this)[i][j]--;
                }
                 
            }
            
        }

        this->loadGraph(this->getMatrix());
        return *this;
    }

    // this--
    Graph Graph::operator--(int)
    {
        if(isEmpty())
        {
            throw std::invalid_argument("Graph is empty");
        }

        Graph temp = *this;
        for (size_t i = 0; i < this->num_of_vertices; i++)
        {
            for (size_t j = 0; j < num_of_vertices; j++)
            {
                if(i != j && (*this)[i][j] != 0)
                {
                    (*this)[i][j]--;
                }
                 
            }
            
        }
        this->loadGraph(this->getMatrix());
        return temp;
    }

    // this*=scalar
    Graph &Graph::operator*=(int scalar)
    {
        if(this->graph.empty())
        {
            throw std::invalid_argument("Graph is empty");
        }

        for (size_t i = 0; i < this->num_of_vertices; i++)
        {
            for (size_t j = 0; j < this->num_of_vertices; j++)
            {
                (*this)[i][j] *= scalar;
            }
            
        }
        this->loadGraph(this->graph);
        return *this;
        
    }

    // this*=g2
    Graph &Graph::operator*=(const Graph &g2)
    {
        if(isEmpty() || g2.isEmpty())
        {
            throw std::invalid_argument("Graphs are empty");
        }
        else if(this->num_of_vertices != g2.getNumVertices())
        {
            throw std::invalid_argument("Graphs aren't the same size");
        }

        vector<vector<int>> matrix(this->num_of_vertices, vector<int>(this->num_of_vertices, 0));

        for(size_t i = 0; i < this->num_of_vertices; i++)
        {
            for (size_t j = 0; j < this->num_of_vertices; j++)
            {
                for (size_t k = 0; k < this->num_of_vertices; k++)
                {
                    if(i != j)
                    {
                        matrix[i][j] += (*this)[i][k] * g2[k][j];
                    }
                }
                
            }
            
        }

        this->loadGraph(matrix);

        return *this;
    }

} // namespace ariel
