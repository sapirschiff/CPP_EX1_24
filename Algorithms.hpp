#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include "Graph.hpp"
#include <string>
#include <stack>

using namespace std;

namespace ariel {


    class Algorithms { // because 
    public:
        // Return if the graph is conncted
    static bool isConnected(const Graph& graph);

    static string shortestPath(const Graph& graph, int start, int end);

    static bool  isBipartiteHelper(const vector<vector<int>>& graph, int current, vector<int>& visited, vector<int>& side1, vector<int>& side2, int group_num) ;

    static string isBipartite(const Graph& g) ;
 
    static string isContainsCycle(const Graph& graph) ;

    static bool negativeCycle(const Graph& graph);

    static string isContainsHelper(const Graph& g, int source, vector<int>& visited, vector<int>& stack_of_cycle,int parent) ;

    static vector<int> bellmanFord(const Graph& graph, size_t source, vector<int>& dist, vector<int>& prev) ;

    static void dfsSecond(const vector<vector<int>>& transpose, size_t v, vector<bool>& visited) ;

    static void dfsFirst(const vector<vector<int>>& matrix, size_t v, vector<bool>& visited, stack<int>& finishOrder) ;

    };

}

#endif // ALGORITHMS_HPP