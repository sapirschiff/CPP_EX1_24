//ID -324246651
//GMAIL- sapirblumshtein@gmail.com



#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

namespace ariel {

class Graph {

private:

    std::vector<std::vector<int>> adjMatrix;
       int nVertices; // Number of vertices 
       int edges; // Number of edges 
       bool weighted; // if there is a weight on the edges

public:

/**
 * @brief Defult constract of the class
 */
    Graph();

    /**
 * @brief Loads the adjacency matrix representation of the graph.
 * @param matrix The adjacency matrix representation of the graph.
 */
    void loadGraph(const std::vector<std::vector<int>>& matrix);

 /**
 * @brief Prints the adjacency matrix representation of the graph.
 */
    void printGraph() const;

    /**
  * @brief Gets the number of edges in the graph.
 * @return The number of edges in the graph.
 */

    int getEdges() const;

    /**
  * @brief Gets the number of vertices in the graph.
 * @return The number of vertices in the graph.
 */

    int getNVertices() const;

   /**
 * @brief Gets a const reference to the adjacency matrix of the graph.
 * @return A const reference to the adjacency matrix of the graph.
 */
   const std::vector<std::vector<int>>& getAdjMatrix() const;

};

} //finish of namespace ariel

#endif // GRAPH_H