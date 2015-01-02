/*
 * Author: Dustin Wilson, 06325157
 * File: graph.cpp
 * --------------------------------------------------------
 * This file is responsible for providing the implementation for functionality of a Graph.
 * Providing functions that calculate the minimum distance travelled between
 * the vertices in several ways; Optimally: dynamically and by brute force.
 * Approxiamately: using Kruskal's minimum spanning tree.
 */

#include "graph.h"
#include <algorithm>
#include "disjointset.h"
#include <stack>

/*
 * Constructor
 * Function: Graph
 * Param: integer, number of vertices in the graph
 * Usage: Graph graph = Graph(10);
 * ------------------------------------------------
 * Constructor which sets the number of vertices in this Graph, in addition
 * to intialising collections of this Graph.
 */
Graph::Graph(int vertices) {

    numCities = vertices;

    // Set the number of vertices in this graph - Adj Matrix
    graph = new double*[numCities];
    for(int i = 0; i < numCities; i++) {

        graph[i] = new double[numCities];

    }// end for

    // Intialise the Adjacency Matrix
    for(int i = 0; i < numCities; i++) {

        for(int j = 0; j < numCities; j++){

            graph[i][j] = 0;

        }// end for

    }// end for

    // initialise Adjacency List as an empty vector
    adjList.resize(0);

    // Sets up the memorisation table [N][(1 << N)]
    mTable = new double*[numCities];
    for(int i = 0; i < numCities; i++) {

        mTable[i] = new double[BIT << numCities];

    }// end for

    // initialise the visited array
    visited = new bool[numCities];

}// end Graph(int)

/*
 * Destructor
 * Function: ~Graph
 * Usage: implicit
 * ------------------------------------------------
 * Destructor deletes the contents of the dynamically created collections
 * of this Graph
 */
Graph::~Graph() {

    for(int i = 0; i < numCities; i++){

        delete[] graph[i];
        delete[] mTable[i];

    }// end for

    delete[] graph;
    delete[] mTable;
    delete[] visited;

    adjList.clear();

}// end ~Graph()

/*
 * Function: AddVertex
 * Param: Pointer to Vertex to be added to the adjacent list
 * Usage: graph.AddVertex(vertex);
 * ------------------------------------------------
 * Adds pointer to Vertex to the adjacency list for this Graph.
 */
void Graph::AddVertex(Vertex* newVertex) {

    adjList.push_back(newVertex);

}// end AddVertex(Vertex*)

/*
 * Accessor
 * Function: GetVertex
 * Param: integer, index for the Vertex in the adjacency list
 * Usage: vertex = graph.GetVertex(1);
 * ------------------------------------------------
 * Returns a pointer to Vertex with the identifier/index in the parameter.
 */
Vertex* Graph::GetVertex(int id) {

    return adjList[id];

}// end GetVertex(int)

/*
 * Function: AddEdge
 * Param: Pointer to Edge to be added.
 * Usage: graph.AddEdge(edge);
 * ------------------------------------------------
 * Adds pointer to Edge to the edge list for this Graph. Also stores the
 * information (weight) for the edge in the underlying adjancency matrix.
 */
void Graph::AddEdge(Edge* newEdge) {

    edgeList.push(newEdge);

    int src = newEdge->GetSource()->GetId();
    int dest = newEdge->GetDestination()->GetId();

    // add to adjacency matrix
    graph[src][dest] = newEdge->GetWeight();
    graph[dest][src] = newEdge->GetWeight();

}// end AddEdge(Edge*)

/*
 * Function: OptimalTSP
 * Usage: optimalDistance = graph.OptimalTSP();
 * ------------------------------------------------
 * Returns the length of the optimal TSP tour. Only to be called if NUM_CITIES is
 * less than or equal to 22. This is done using the dynamic programming approach.
 */
double Graph::OptimalTSP() {

    double result = 0;

    /* Brute Force Set up

    // pre- condidition will have to be changed to if (numCities <= 11){

    // initialise visited to false
    for (int i = 0; i < numCities; i++) {

        visited[i] = false;

    }// end for

    // set first element of visited to true
    visited[0] = true;

    result <- TSPBruteForce(0, visited)
    result = TSPBruteForce(ZERO, visited);

    */

    /* Dynamic Programming Approach */

    // Set all values in table to UNSET
    for(int i = 0; i < numCities; i++) {

        for(int j = 0; j < (BIT << numCities); j++){

            mTable[i][j] = UNSET;

        }// end for

    }// end for

    // result <- TSPDP(0, 1)
    result = TSPDP(START, BIT);

    return result;

}// end OptimalTSP()

/*
 * Function: ApproximateTSP
 * Usage: approximateDistance = graph.ApproximateTSP();
 * ------------------------------------------------
 * Returns the length of the approximate TSP tour using Kruskal
 * Minimum Spanning Tree algorithm and then calculating using a Depth
 * First Search function.
 */
double Graph::ApproximateTSP() {

    MinimumSpanningTree();

    return DepthFirstSearch();

}// end ApproximateTSP()

/* Private Functions */

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
double Graph::TSPBruteForce(int current, bool* visited) {

    double minDistance;
    bool* visitedCopy;
    double dist;

    bool allTrue = true;

    // checks if visited is all True - if not ends
    for(int i = 0; i < numCities; i++) {

        if(visited[i] != true) {

            allTrue = false;
            break;

        }// end if

    }// end for

    // if all elements in visited are true
    if(allTrue) {

        // return distance from current to 0
        return graph[current][START];

    }// end if

    // make a copy of visited
    visitedCopy = visited;

    // set minDistance to INFINITY
    minDistance = INFINITY;

    // for adjacent from 0 to numVerties-1
    for(int i = 0; i < numCities; i++) {

        // if current != adjacent AND adjacent not visited
        if((current != i) && (visited[i] == false)) {

            // set adjacent in copy of vistited to true
            visitedCopy[i] = true;

            // dist <- distance from current to adjacent +
            //           TSPBruteForce(adjacent, copy of visited)
            dist = graph[current][i] + TSPBruteForce(i, visitedCopy);

            // minDistance <- minimum(minDistance, dist)
            minDistance = min(minDistance, dist);

            // set adjacent in copy of visited to false
            visitedCopy[i] = false;

        }// end if

    }// end for

    // return minDistance
    return minDistance;

}// end TSPBruteForce(int, bool*)

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
double Graph::TSPDP(int current, int bitmask) {

    double dist;
    double minDistance;

    // if table[current][bitmask] is not UNSET - value already exists to add on.
    if(mTable[current][bitmask] != UNSET){

        // return table[current][bitmask]
        return mTable[current][bitmask];

    }// end if

    // if bitmask ==((1 << N) - 1) - all places visited
    if(bitmask == ((BIT << numCities) - 1)) {

        // return distance from current to 0
        dist = graph[current][START];

        // return distance from current to 0
        return dist;

    }// end if

    // minDistance <- INFINITY
    minDistance = INFINITY;

    // for adjacent from 0 to N-1 - go though each possible solution
    for(int adjacent = 0; adjacent < numCities; adjacent++) {

        // if current != adjacent AND ((bitmask & (1 << ajacent)) == 0)
        if((current != adjacent) &&((bitmask & (BIT << adjacent)) == START)) {

            //dist <- distance from current to adjacent + TSPDP(adjacent, (bitmask |(1 << adacent)))
            dist = graph[current][adjacent] + TSPDP(adjacent, (bitmask | (BIT << adjacent)));

            // minDistance <- min(minDistance, dist) - keeps track of which one is minimum
            minDistance = min(minDistance, dist);

        }// endif

    }// endfor

    // table[current][bitmask] = minDistance
    mTable[current][bitmask] = minDistance;

    //return minDistance
    return minDistance;

}// end TSPDP(int, int)

/* The approximation Algorithm use both of these functions */

/*
 * Function: MinimumSpanningTree
 * Usage: MinimumSpanningTree();
 * ------------------------------------------------
 * Uses Kruskal's Algorithm to find the Minimum Spanning Tree for this Graph.
 * Stores the edges(Vertex to Vertex) of the MST in the adjacency lists of each
 * Vertex.
 */
void Graph::MinimumSpanningTree() {

    //initialise DisjointSet of size N
    DisjointSet* newSet = new DisjointSet(numCities);

    //edgeCount <- 0
    int edgeCount = 0;

    Edge* edge;
    Vertex* source;
    Vertex* destination;

    //while edges not empty AND edgeCount < N - 1
    while((!edgeList.empty()) && (edgeCount < (numCities - 1))){

        //edge <- pq.pop()
        edge = edgeList.top();
        edgeList.pop();

        source = edge->GetSource();
        destination = edge->GetDestination();

        //If NOT SameComponent(edge.source, edge.destination)
        if(!newSet->SameComponent(source->GetId(),destination->GetId())) {

            //increment edgeCount
            edgeCount++;

            //Union(edge.source, edge.destination)
            newSet->Union(source->GetId(),destination->GetId());

            //add source to adjacency list to destination
            destination->AddAdjacency(source);

            //add destination to adjacecy list of current
            source->AddAdjacency(destination);

        }//end if

    }//end while

}// end MinimumSpanningTree()

/*
 * Function: DepthFirstSearch
 * Usage: distance = DepthFirstSeach();
 * ------------------------------------------------
 * Returns the approximation for the TSP tour taken by traversing the vertices
 * in depth first order of the sub graph formed from the MST.
 */
double Graph::DepthFirstSearch() {

    // dist <- 0
    double dist = 0;

    // initialise visited array to false
    for (int i = 0; i < numCities; i++) {

        visited[i] = false;

    }// end for

    // create empty stack
    stack< Vertex* > vertexStack;

    // push vertex 0 onto stack
    vertexStack.push(GetVertex(START));

    // mark vertex 0 visited
    visited[0] = true;

    // let current vertex <- NULL
    Vertex* current = NULL;

    // let previous vertex <- NULL
    Vertex* previous = NULL;

    // while stack not empty
    while(!vertexStack.empty()) {

        // current <- pop from stack
        current = vertexStack.top();

        vertexStack.pop();

        // if previous not NULL
        if(previous != NULL){

            // dist <- dist + distance from previous to current
            dist += graph[previous->GetId()][current->GetId()];

        }// end if

        // for vertices adjacent to current
        for(unsigned adjacent = 0; adjacent < current->GetAdjacencies().size(); adjacent++){

            // if adjacent vertex not visited
            if(visited[current->GetAdjacencies()[adjacent]->GetId()] == false){

                // push adjacent vertex onto stack
                vertexStack.push(current->GetAdjacencies()[adjacent]);

                // mark adjacent vertex visited
                visited[current->GetAdjacencies()[adjacent]->GetId()] = true;

            }// end if

        }// end for

        // previous <- current
        previous = current;

    }// end while

    // dist <- distance from current to vertex 0
    dist += graph[current->GetId()][GetVertex(START)->GetId()] ;

    // return dist
    return dist;

}// end DepthFirstSearch
