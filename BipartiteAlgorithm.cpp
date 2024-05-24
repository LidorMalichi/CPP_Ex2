/*
 * Name: Lidor Malichi
 * ID: 318515947
 * Email: lidor673@gmail.com
 */
#include "BipartiteAlgorithm.hpp"

// Implementation of the Bipartite method to check if the graph is bipartite
std::string BipartiteAlgorithm::Bipartite(const ariel::Graph &g) {
    
    size_t numVertice = g.getNumVertices();  
    
    // Create a vector to store colors for each vertex
    std::vector<int> color(numVertice, -1);  

    // Iterate through each vertex
    for (size_t i = 0; i < numVertice; i++) {
        // Check if the vertex already has a color assigned
        if (color[i] != -1) {
            continue;  
        }
    
        // Create a queue for BFS traversal
        std::queue<size_t> q;  
        q.push(i);  
        color[i] = RED;  

        // Perform BFS traversal
        while (!q.empty()) {
            size_t u = q.front();  
            q.pop();  

            // Traverse adjacent vertices of vertex u
            for (size_t v = 0; v < numVertice; v++) {
            
                if (g[u][v] != 0) {
                    // Check if vertex v has no color assigned
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];  
                        q.push(v);  
                    } 
                    else {
                        // Check if v has the same color as u (indicating an odd cycle)
                        if (color[v] == color[u]) {
                            return "0";  
                        }
                    }
                }
            }
        }
    }

    // Prepare strings to represent bipartite sets
    std::string setA = "A={}";
    std::string setB = "B={}";

    // Iterate through vertices to populate sets A and B based on colors
    for (size_t v = 0; v < numVertice; v++) {
        if (color[v] == RED) {
            setA.insert(setA.size() - 1, std::to_string(v) + ", "); 
        }
        if (color[v] == BLUE) {
            setB.insert(setB.size() - 1, std::to_string(v) + ", ");  
        }
    }

    // Remove trailing commas from sets A and B
    if (setA.size() > 4) {
        setA.erase(setA.size() - 3, 2);
    }
    if (setB.size() > 4) {
        setB.erase(setB.size() - 3, 2);
    }

    // Return the result indicating bipartite sets
    return "The graph is bipartite: " + setA + ", " + setB;
}
