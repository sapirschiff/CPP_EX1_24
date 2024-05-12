//ID -324246651
//GMAIL- sapirblumshtein@gmail.com



#include "Graph.hpp"
#include <vector>
#include <iostream>
#include <stdexcept>


namespace ariel {

Graph::Graph() : nVertices(0), edges(0) ,weighted(false){}



void Graph::loadGraph(const std::vector<std::vector<int>>& matrix) {
        // Check if the input matrix is square
    size_t n = matrix.size();
    for(size_t i =0; i<n; i++){  //check all the option that the matrix can be
        if (matrix[i].size() != n) {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
    }

    this->adjMatrix = matrix;
    this->nVertices = n;
   
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