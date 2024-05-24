/*
 * Name: Lidor Malichi
 * ID: 318515947
 * Email: lidor673@gmail.com
 */
#ifndef GRAPHOPERATORS_H
#define GRAPHOPERATORS_H
#include "Graph.hpp"
#include <vector>

namespace ariel{

    Graph operator+(const Graph& g1, const Graph& g2); 

    Graph operator-(const Graph& g1, const Graph& g2);

    bool operator>(const Graph& g1, const Graph& g2);

    bool operator==(const Graph& g1, const Graph& g2);

    bool operator>=(const Graph& g1, const Graph& g2);

    bool operator<(const Graph& g1, const Graph& g2);

    bool operator<=(const Graph& g1, const Graph& g2);

    bool operator!=(const Graph& g1, const Graph& g2);

    Graph operator*(const Graph& g1, int scalar);

    Graph operator*(const Graph& g1, const Graph& g2);

    std::ostream& operator<<(std::ostream& os, const Graph& g);

    
}


#endif