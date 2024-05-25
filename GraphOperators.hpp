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
    
    // + operator
    Graph operator+(const Graph& g1, const Graph& g2); 

    // += operator
    Graph operator-(const Graph& g1, const Graph& g2);

    // > operator
    bool operator>(const Graph& g1, const Graph& g2);

    // == operator
    bool operator==(const Graph& g1, const Graph& g2);

    // >= operator
    bool operator>=(const Graph& g1, const Graph& g2);

    // < operator
    bool operator<(const Graph& g1, const Graph& g2);

    // <= operator
    bool operator<=(const Graph& g1, const Graph& g2);

    // != operator
    bool operator!=(const Graph& g1, const Graph& g2);

    // * scalar operator
    Graph operator*(const Graph& g1, int scalar);

    // * operator
    Graph operator*(const Graph& g1, const Graph& g2);

    // << operator
    std::ostream& operator<<(std::ostream& os, const Graph& g);

    
}


#endif