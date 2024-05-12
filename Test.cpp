//ID -324246651
//GMAIL- sapirblumshtein@gmail.com



#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <climits>

const int MY_INT_MAX = 1000000000; // Global definition


using namespace std;
using namespace ariel;

TEST_CASE("Test isConnected")
{
    Graph g;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g.loadGraph(graph1);
    CHECK(Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 0},
        {0, 0}
    };
    g.loadGraph(graph2);
    CHECK(Algorithms::isConnected(g) == false);

    // Graph with multiple components
    vector<vector<int>> graph3 = {
        {0, 2, 0},
        {2, 0, 0},
        {0, 0, 0}
    };
    g.loadGraph(graph3);
    CHECK(Algorithms::isConnected(g) == false);

    // Fully connected graph
    vector<vector<int>> graph4 = {
        {0, 1},
        {1, 0}
    };
    g.loadGraph(graph4);
    CHECK(Algorithms::isConnected(g) == true);

    // Line Style Graph
    vector<vector<int>> graph5 = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0}
    };
    g.loadGraph(graph5);
    CHECK(Algorithms::isConnected(g) == true);
}

TEST_CASE("Test shortestPath")
{
    Graph g;

    vector<vector<int>> graph1 = {
        {0, 1, 0, 4},
        {1, 0, 2, 0},
        {0, 2, 0, 1},
        {4, 0, 1, 0}
    };
    g.loadGraph(graph1);
    CHECK(Algorithms::shortestPath(g, 0, 3) == "0->3");

    vector<vector<int>> graph2 = {
        {0, 3, MY_INT_MAX, 7},
        {3, 0, 1, 5},
        {MY_INT_MAX, 1, 0, 2},
        {7, 5, 2, 0}
    };
    g.loadGraph(graph2);
    CHECK(Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    // Test for no path available
    vector<vector<int>> graph3 = {
        {0, MY_INT_MAX, MY_INT_MAX},
        {MY_INT_MAX, 0, MY_INT_MAX},
        {MY_INT_MAX, MY_INT_MAX, 0}
    };
    g.loadGraph(graph3);
    CHECK(Algorithms::shortestPath(g, 0, 2) == "-1");

    // Test single node graph
    vector<vector<int>> graph4 = {
        {0}
    };
    g.loadGraph(graph4);
    CHECK(Algorithms::shortestPath(g, 0, 0) == "0");

    // Test larger looped graph
    vector<vector<int>> graph5 = {
        {0, 1, MY_INT_MAX, MY_INT_MAX, 6},
        {1, 0, 2, MY_INT_MAX, MY_INT_MAX},
        {MY_INT_MAX, 2, 0, 3, MY_INT_MAX},
        {MY_INT_MAX, MY_INT_MAX, 3, 0, 4},
        {6, MY_INT_MAX, MY_INT_MAX, 4, 0}
    };
    g.loadGraph(graph5);
    CHECK(Algorithms::shortestPath(g, 0, 3) == "0->1->2->3");
}

TEST_CASE("Test isContainsCycle")
{
    Graph g;
    // Simple triangle
    vector<vector<int>> graph1 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };
    g.loadGraph(graph1);
    CHECK(Algorithms::isContainsCycle(g) != "0");

    // No cycle
    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g.loadGraph(graph2);
    CHECK(Algorithms::isContainsCycle(g) == "0");

    // Complex Cycle
    vector<vector<int>> graph3 = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
    g.loadGraph(graph3);
    CHECK(Algorithms::isContainsCycle(g) != "0");

    // Star topology, no cycle
    vector<vector<int>> graph4 = {
        {0, 1, 1, 1},
        {1, 0, 0, 0},
        {1, 0, 0, 0},
        {1, 0, 0, 0}
    };
    g.loadGraph(graph4);
    CHECK(Algorithms::isContainsCycle(g) == "0");

    // Single node graph
    vector<vector<int>> graph5 = {
        {0}
    };
    g.loadGraph(graph5);
    CHECK(Algorithms::isContainsCycle(g) == "0");
}

TEST_CASE("Test isBipartite")
{
    Graph g;
    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}
    };
    g.loadGraph(graph1);
    CHECK(Algorithms::isBipartite(g) != "0");

    vector<vector<int>> graph2 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g.loadGraph(graph2);
    CHECK(Algorithms::isBipartite(g) != "0");

    // Graph with all edges
    vector<vector<int>> graph3 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };
    g.loadGraph(graph3);
    CHECK(Algorithms::isBipartite(g) == "0");

    // Graph with different structure
    vector<vector<int>> graph4 = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
    g.loadGraph(graph4);
    CHECK(Algorithms::isBipartite(g) != "0");

    // Fully connected graph
    vector<vector<int>> graph5 = {
        {0, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 0}
    };
    g.loadGraph(graph5);
    CHECK(Algorithms::isBipartite(g) == "0");
}


TEST_CASE("Test invalid graph")
{
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0}
    };
    CHECK_THROWS(g.loadGraph(graph)); 
}
