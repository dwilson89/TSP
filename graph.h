/*
 * Author: Dustin Wilson, 06325157
 * File: graph.h
 * --------------------------------------------------------
 * This interface is responsible for providing the functionality for a Graph.
 * Providing functions that calculate the minimum distance travelled between
 * the vertices in several ways; Optimally: dynamically and by brute force.
 * Approxiamately: using Kruskal's minimum spanning tree.
 */

#ifndef _graph_h
#define _graph_h

#include "edgecomparer.h"
#include "vertex.h"
#include "edge.h"
#include <Vector>
#include <queue>

using namespace std;

const int INFINITY  = 9999999;
const int UNSET = -1;

// starting point
const int START = 0;

// bitmask operations
const int BIT = 1;

/* Graph type definition consisting of a adjacency matrix, adjacent list, edge list */
/* and a memoisation table                                                          */
class Graph {

    public:

        /*
         * Constructor
         * Function: Graph
         * Param: integer, number of vertices in the graph
         * Usage: Graph graph = Graph(10);
         * ------------------------------------------------
         * Constructor which sets the number of vertices in this Graph, in addition
         * to intialising collections of this Graph.
         */
        Graph(int);

        /*
         * Destructor
         * Function: ~Graph
         * Usage: implicit
         * ------------------------------------------------
         * Destructor deletes the contents of the dynamically created collections
         * of this Graph
         */
        ~Graph();

        /*
         * Function: AddVertex
         * Param: Pointer to Vertex to be added to the adjacent list
         * Usage: graph.AddVertex(vertex);
         * ------------------------------------------------
         * Adds pointer to Vertex to the adjacency list for this Graph.
         */
        void AddVertex(Vertex*);

        /*
         * Accessor
         * Function: GetVertex
         * Param: integer, index for the Vertex in the adjacency list
         * Usage: vertex = graph.GetVertex(1);
         * ------------------------------------------------
         * Returns a pointer to Vertex with the identifier/index in the parameter.
         */
        Vertex* GetVertex(int);

        /*
         * Function: AddEdge
         * Param: Pointer to Edge to be added.
         * Usage: graph.AddEdge(edge);
         * ------------------------------------------------
         * Adds pointer to Edge to the edge list for this Graph. Also stores the
         * information (weight) for the edge in the underlying adjancency matrix.
         */
        void AddEdge(Edge*);

        /*
         * Function: OptimalTSP
         * Usage: optimalDistance = graph.OptimalTSP();
         * ------------------------------------------------
         * Returns the length of the optimal TSP tour. Only to be called if NUM_CITIES is
         * less than or equal to 22. This is done using the dynamic programming approach.
         */
        double OptimalTSP();

        /*
         * Function: ApproximateTSP
         * Usage: approximateDistance = graph.ApproximateTSP();
         * ------------------------------------------------
         * Returns the length of the approximate TSP tour using Kruskal
         * Minimum Spanning Tree algorithm and then calculating using a Depth
         * First Search function.
         */
        double ApproximateTSP();

    private:

        /* Private Variables */

        // graph - adjacency matrix
        double** graph;

        // edge list
        priority_queue<Edge*, vector<Edge*>, EdgeComparer> edgeList;

        // adjacency list
        vector<Vertex*> adjList;

        // memoisation table
        double** mTable;

        // number of cities/vertices
        int numCities;

        // bool array of visited Vertices
        bool* visited;

        /* private functions */

        /*
         * Function: TSPBruteForce
         * Param 1: integer, index of vertex
         * Param 2: Pointer to a bool array of visited vertices
         * Usage: distance = TSPBruteForce(0, visited);
         * ------------------------------------------------
         * Recursive brute force solution. Maximum size it can handle ~ 11.
         * Goes though each possible solution in a brute force manner, recording
         * and comparing distances found in order to determine the minimum distance
         * that has to be travelled.
         */
        double TSPBruteForce(int, bool*);

        /*
         * Function: TSPDP
         * Param 1: integer index of current vertex
         * Param 2: integer bitmask of places visited. (111) = 7 all cities visited
         * Usage: distance = TSPDP(0, 1);
         * ------------------------------------------------
         * Top down Dynamic Programmin with memorisation solution. Maximum size
         * it can handle ~ 20. Recursive, goes through each possible solution,
         * recording and comparing values - using known calculated paths that have
         * been stored in the memoisation table by use of the current position and bitmask
         * to save on re-calculating already known distances - in order to calculate and
         * determine the minimum distance that has been travelled.
         */
        double TSPDP(int, int);

        /*
         * Function: MinimumSpanningTree
         * Usage: MinimumSpanningTree();
         * ------------------------------------------------
         * Uses Kruskal's Algorithm to find the Minimum Spanning Tree for this Graph.
         * Stores the edges(Vertex to Vertex) of the MST in the adjacency lists of each
         * Vertex.
         */
        void MinimumSpanningTree();

        /*
         * Function: DepthFirstSearch
         * Usage: distance = DepthFirstSeach();
         * ------------------------------------------------
         * Returns the approximation for the TSP tour taken by traversing the vertices
         * in depth first order of the sub graph formed from the MST.
         */
        double DepthFirstSearch();

};

#endif // _graph_h
