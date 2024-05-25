
# CPP_Ex2

# Graph Algorithms and Operators Library

## Overview

This repository contains a C++ library for graph algorithms and operators, designed to provide a comprehensive set of functionalities for graph analysis and manipulation.

 ## Algorithm Features

  * **Connectivity Check**: Determine if a graph is connected using the Connectivity class.
  * **Shortest Path Finding**: Find the shortest path between two vertices using the ShortestPath class.
  * **Cycle Detection**: Check if a graph contains a cycle using the CycleAlgorithms class.
  * **Bipartite Graph Identification**: Identify if a graph is bipartite using the BipartiteAlgorithm class.
  * **Negative Cycle Detection**: Detect negative cycles in a graph using the CycleAlgorithms class with a flag for negative cycle detection.
## Operators Features
### Common operators
  * **g1** `+` **g2**: Addition of two graphs creating a new graph
  * **g1** `+=` **g2**: Adding the second graph to the first one
  * **g1** `-` **g2**: Subtraction of two graphs creating a new graph
  * **g1** `-=` **g2**: Subtracting the second graph from the first one
  * **g1** `*` **g2**: Multiply the two graphs creating a new graph
  * **g1** `*=` **g2**: Multiply the first graph with the second graph
  * **g** `*` **a**: Multiply the graph edges with a scalar creating a new graph, a is an integer
  * **g** `*=` **a**: Multiply the graph edges with a scalar, a is an integer
### Prefix operators
* `++` **g**: Incrementing all existing edges by 1 than returning a copy of g
* `--` **g**: Decrementing all existing edges by 1 than returning a copy of g
* **g** `++`: Returning a copy of g than incrementing all existing edges by 1
* **g** `--`: Returning a copy of g than decrementing all existing edges by 1  
### Unary operators
  * `+` **g**: Unary plus doesn't change the graph
  * `-` **g**: Unary minus negating the graph edges, edges which are negative will become positive and vice versa
### Comparison operators
* **g1** `>` **g2**: return true if g1 is bigger than g2
* **g1** `>=` **g2**: return true if g1 is bigger or equal to g2
* **g1** `<` **g2**: return true if g2 is bigger than g1
* **g1** `<=` **g2**: return true if g2 is bigger or equal to g1
* **g1** `==` **g2**: return true if g1 is equal to g2
* **g1** `!=` **g2**: return true if g1 is **NOT** equal to g2
### Matrix operator
* **g** `[index]`: returns the row vector of the adjacency matrix in the specifeid index 
## Object-Oriented Programming Principles

The library implements several object-oriented programming (OOP) principles:

  * **Encapsulation**: The algorithms are encapsulated within classes, providing a clear interface for users to interact with.
    
  * **Abstraction**: The library abstracts away low-level details, providing high-level functions for common graph operations.

  * **Modularity**: Algorithms are modularly designed, promoting code reusability and maintainability.

  * **Separation of Concerns**: Different classes handle specific concerns like connectivity, shortest paths, cycles, and bipartiteness, adhering to the principle of separation of concerns.

## Graph Structure Overview

### Implementation Details

In this project, the graph structure is implemented using the following components:

- **Adjacency Matrix:** The connections between nodes in the graph are represented using an adjacency matrix. This matrix is a two-dimensional array where each element indicates whether there is an edge between two nodes.

- **Directed and Undirected Graphs:** The graph can be either directed or undirected, determined by a boolean value. A symmetric adjacency matrix indicates an undirected graph, while a non-symmetric matrix indicates a directed graph.

- **Weighted Type:** The graph can also have different weight types:
  - **Unweighted:** All edges are considered to have equal importance.
  - **Weighted:** Edges are associated with numerical weights, representing factors such as cost, distance, or capacity.
  - **Negative Weighted:** Some edges may have negative weights, influencing algorithms like shortest path algorithms.


## Usage

### Running the Demo

To run the demo showcasing the library's capabilities, use the following command:

```bash
make run
```

### Running Tests

To run tests and ensure the correctness of the algorithms, use the following command:

```bash
make runtests
```
### Cleaning Up Files

To delete files created during compilation and execution, use the following command:

```bash
make clean
```


