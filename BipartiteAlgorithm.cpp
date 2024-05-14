/*
 * Name: Lidor Malichi
 * ID: 318515947
 * Email: lidor673@gmail.com
 */
#include "BipartiteAlgorithm.hpp"

// Implementation of the Bipartite method to check if the graph is bipartite
std::string BipartiteAlgorithm::Bipartite(ariel::Graph &g) {
    // Get the adjacency matrix of the graph
    std::vector<std::vector<int>> matrix = g.getMatrix();
    size_t numVertice = matrix.size();  // Get the number of vertices in the graph

    std::vector<int> color(numVertice, -1);  // Create a vector to store colors for each vertex

    // Iterate through each vertex
    for (size_t i = 0; i < numVertice; i++) {
        // Check if the vertex already has a color assigned
        if (color[i] != -1) {
            continue;  // Skip if the vertex already has a color
        }

        std::queue<size_t> q;  // Create a queue for BFS traversal
        q.push(i);  // Push the current vertex to the queue
        color[i] = RED;  // Assign red color to the current vertex

        // Perform BFS traversal
        while (!q.empty()) {
            size_t u = q.front();  // Get the front element of the queue
            q.pop();  // Remove the front element from the queue

            // Traverse adjacent vertices of vertex u
            for (size_t v = 0; v < numVertice; v++) {
                // Check if there is an edge between u and v
                if (matrix[u][v] != 0) {
                    // Check if vertex v has no color assigned
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];  // Assign opposite color to v
                        q.push(v);  // Push v to the queue for further traversal
                    } else {
                        // Check if v has the same color as u (indicating an odd cycle)
                        if (color[v] == color[u]) {
                            return "0";  // Return 0 if an odd cycle is found
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
            setA.insert(setA.size() - 1, std::to_string(v) + ", ");  // Add vertex v to set A
        }
        if (color[v] == BLUE) {
            setB.insert(setB.size() - 1, std::to_string(v) + ", ");  // Add vertex v to set B
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
