//ID -324246651
//GMAIL- sapirblumshtein@gmail.com



#include "Graph.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>


namespace ariel {

Graph::Graph() : nVertices(0), edges(0) , directed(false) ,weighted(false){}



void Graph::loadGraph(const std::vector<std::vector<int>>& matrix) {
        // Check if the input matrix is square
    size_t n = matrix.size();
    for(size_t i =0; i<n; i++){  //check all the option that the matrix can be
        if (matrix[i].size() != n) {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
    }

   // bool symmetrical = true;
   // bool weight = false;
   // for (size_t i = 0; i < n; i++) {
    //   for (size_t j = i + 1; j < n; j++) {
    //        if (matrix[i][j] != matrix[j][i]) { // if isn't equal so is not symmetrical is directed
    //            symmetrical = false; 
    //        }
    //        if (matrix[i][j] != 1 && matrix[i][j] != 0 ) // if the number in the matrix is diffrent from 0/1
    //           weight = true;

    
   //     }
   // }

    // load the matrix
    this->adjMatrix = matrix;
    this->nVertices = n;
   // this->directed = !symmetrical; 
   // this->weighted = weight;

        // count the number of edges in the graph 
        this->edges=0;
        for (std::size_t i = 0; i < n; i++) {
           for (std::size_t j = 0; j < n; j++) {
               if (adjMatrix[i][j] != 0) {
                   this->edges++;
                }
            } 
        }
    }

    void Graph::printGraph() const {
    for (const auto& row : adjMatrix) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

    

    int Graph::getNVertices() const { 
        return this->nVertices;
    }

    int Graph::getEdges () const { 
        return this->edges; 
    }

    const std::vector<std::vector<int>>& ariel::Graph::getAdjMatrix() const {
        return this->adjMatrix ;
    }



} // namespace ariel