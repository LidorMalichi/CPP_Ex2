/*
 * Name: Lidor Malichi
 * ID: 318515947
 * Email: lidor673@gmail.com
 */
#include "GraphOperators.hpp"

namespace ariel{

    //g1+g2
    Graph operator+(const Graph &g1, const Graph &g2)
    {
        if(g1.isEmpty() || g2.isEmpty())
        {
            throw std::invalid_argument("Graphs are empty");
        }
        else if(g1.getNumVertices() != g2.getNumVertices())
        {
            throw std::invalid_argument("Graphs aren't the same size");
        }

        
        size_t numVertice = g1.getNumVertices();

        vector<vector<int>> matrix(numVertice, vector<int>(numVertice, 0));

        for (size_t i = 0; i < numVertice; i++)
        {
            for (size_t j = 0; j < numVertice; j++)
            {
                matrix[i][j] = g1[i][j] + g2[i][j];
            }
            
        }
        

        Graph g;
        g.loadGraph(matrix);
        return g;
    }

    
    //g1-g2
    Graph operator-(const Graph &g1, const Graph &g2)
    {
        if(g1.isEmpty() || g2.isEmpty())
        {
            throw std::invalid_argument("Graphs are empty");
        }
        else if(g1.getNumVertices() != g2.getNumVertices())
        {
            throw std::invalid_argument("Graphs aren't the same size");
        }

        size_t numVertice = g1.getNumVertices();

        vector<vector<int>> matrix(numVertice, vector<int>(numVertice, 0));

        for (size_t i = 0; i < numVertice; i++)
        {
            for (size_t j = 0; j < numVertice; j++)
            {
                matrix[i][j] = g1[i][j] - g2[i][j];
            }
            
        }
        

        Graph g;
        g.loadGraph(matrix);
        return g;
    }

    //g1 > g2
    bool operator>(const Graph &g1, const Graph &g2)
    {
        if(g1.isEmpty() || g2.isEmpty())
        {
            throw std::invalid_argument("Graphs are empty");
        }

        else if(g1.getNumVertices() < g2.getNumVertices())
        {
            return false;
        }

        bool contains = true;

        for (size_t i = 0; i < g2.getNumVertices(); i++)
        {
            for (size_t j = 0; j < g2.getNumVertices(); j++)
            {
                if(g2[i][j] != g1[i][j])
                {
                    contains = false;
                }
            }
            
        }

        if(contains)
        {
            return g1.getNumVertices() > g2.getNumVertices();
        }
        else
        {
            if(g1.getNumEdges() > g2.getNumEdges())
            {
                return true;
            }
            else
            {
                return g1.getNumVertices() > g2.getNumVertices();
            }
        }
        
    }

    //g1==g2
    bool operator==(const Graph &g1, const Graph &g2)
    {
        if(g1.isEmpty() || g2.isEmpty())
        {
            throw std::invalid_argument("Graphs are empty");
        }
        return !(g1 > g2) && !(g2 > g1);
    }

    //g1>=g2
    bool operator>=(const Graph &g1, const Graph &g2)
    {
        if(g1.isEmpty() || g2.isEmpty())
        {
            throw std::invalid_argument("Graphs are empty");
        }
        return (g1 > g2) || (g1 == g2);
    }

    //g1<g2
    bool operator<(const Graph &g1, const Graph &g2)
    {
        if(g1.isEmpty() || g2.isEmpty())
        {
            throw std::invalid_argument("Graphs are empty");
        }
        return g2 > g1;
    }

    //g1<=g2
    bool operator<=(const Graph &g1, const Graph &g2)
    {
        if(g1.isEmpty() || g2.isEmpty())
        {
            throw std::invalid_argument("Graphs are empty");
        }
        return g2 >= g1;
    }

    //g1!=g2
    bool operator!=(const Graph &g1, const Graph &g2)
    {
        if(g1.isEmpty() || g2.isEmpty())
        {
            throw std::invalid_argument("Graphs are empty");
        }
        return !(g1 == g2);
    }

    //g1*a
    Graph operator*(const Graph &g1, int scalar)
    {
        if(g1.isEmpty())
        {
            throw std::invalid_argument("The graph is empty");
        }
        size_t numVertice = g1.getNumVertices();

        vector<vector<int>> matrix(numVertice, vector<int>(numVertice, 0));

        for (size_t i = 0; i < numVertice; i++)
        {
            for (size_t j = 0; j < numVertice; j++)
            {
                matrix[i][j] = g1[i][j] * scalar;
            }
            
        }
        Graph g;
        g.loadGraph(matrix);
        
        return g;
    }

    //g1*g2
    Graph operator*(const Graph &g1, const Graph &g2)
    {
        if(g1.isEmpty() || g2.isEmpty())
        {
            throw std::invalid_argument("Graphs are empty");
        }
        else if(g1.getNumVertices() != g2.getNumVertices())
        {
            throw std::invalid_argument("Graphs aren't the same size");
        }
        size_t numVertice = g1.getNumVertices();

        vector<vector<int>> matrix(numVertice, vector<int>(numVertice, 0));

        for(size_t i = 0; i < numVertice; i++)
        {
            for (size_t j = 0; j < numVertice; j++)
            {
                for (size_t k = 0; k < numVertice; k++)
                {
                    if(i != j)
                    {
                        matrix[i][j] += g1[i][k] * g2[k][j];
                    }
                }
                
            }
            
        }

        Graph g;
        g.loadGraph(matrix);

        return g;
    }

    //<<g
    std::ostream &operator<<(std::ostream &os, const Graph &g)
    {
        if(g.isEmpty())
        {
            os << "The Graph is empty";
            return os;
        }
        else
        {
            for (size_t i = 0; i < g.getNumVertices(); i++)
            {
                os << "[";

                for (size_t j = 0; j < g.getNumVertices(); j++)
                {
                    os << g[i][j];
                    os << (j < g.getNumVertices()-1 ? ", " : "");
                }
                os << "]\n";
                
            }
            
        } 
        return os;      
    }
}
