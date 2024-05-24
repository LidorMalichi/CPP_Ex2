/*
 * Name: Lidor Malichi
 * ID: 318515947
 * Email: lidor673@gmail.com
 */
#include "CycleAlgorithms.hpp"

// Implementation of the findCycle function from CycleAlgorithms class

// Function to find a cycle in the given graph
string CycleAlgorithms::findCycle(const ariel::Graph &g, bool negative)
{
    // Get the number of vertices in the graph
    size_t numVertice = g.getNumVertices();

    // Initialize edge classification matrix
    vector<vector<char>> edgeClass(numVertice, vector<char>(numVertice, NOT_CLASS));

    // Initialize predecessor array for DFS traversal
    vector<int> predecessor(numVertice, -1);

    // Perform Depth-First Search (DFS) traversal on the graph
    SearchAlgorithms::dfs(g, predecessor, edgeClass, g.isUnDirected());

    // Iterate through each edge in the graph
    for(size_t u = 0; u < numVertice; u++)
    {
        for (size_t v = 0; v < numVertice; v++)
        {
            // Check if the edge is a back edge (indicating a cycle)
            if(edgeClass[u][v] == BACK_EDGE)
            {
                string cycle = ""; 
                int cycleWeight = 0; 

                size_t curr_vertice = u; 

                cycleWeight += g[curr_vertice][v]; 
                cycle.insert(0, to_string(curr_vertice) + "->" + to_string(v)); 

                // Traverse the cycle until reaching the cycle's starting vertex or reaching a dead end
                while(predecessor[curr_vertice] != v && predecessor[curr_vertice] != -1)
                {
                    cycleWeight += g[static_cast<size_t>(predecessor[curr_vertice])][curr_vertice]; 
                    cycle.insert(0, to_string(predecessor[curr_vertice]) + "->"); 
                    curr_vertice = static_cast<size_t>(predecessor[curr_vertice]); 
                }

                // If a cycle was found and negative flag is set, check for negative cycle
                if(predecessor[curr_vertice] != -1 && negative)
                {
                    cycleWeight += g[static_cast<size_t>(predecessor[curr_vertice])][curr_vertice];
                    if(cycleWeight < 0) 
                    {
                        cycle.insert(0, to_string(predecessor[curr_vertice]) + "->");
                        return cycle;
                    }
                }

                // If a non-negative cycle is found, return the cycle
                if(predecessor[curr_vertice] != -1 && !negative)
                {
                    cycle.insert(0, to_string(predecessor[curr_vertice]) + "->");
                    return cycle;
                }
            }
        }
    }

    // If no cycle is found, return "0"
    return "0";
}
