/*
 * Author: Dustin Wilson, 06325157
 * File: edge.h
 * --------------------------------------------------------
 * This interface is responsible for providing the functionality of a Edge, such
 * as storing its weight, source and destination, in addtion to providing functions
 * in which to access such information.
 */

#ifndef _edge_h
#define _edge_h
#include <iostream>
#include "vertex.h"

using namespace std;

/* Edge type definition consisting of a source, detination and weight */
class Edge {
    public:

        /*
         * Constructor
         * Function: Edge
         * Param 1: Pointer to Vertex, source Vertex
         * param 2: Pointer to Vertex, destination Vertex
         * param 3: double, the weight of the edge
         * Usage: newEdge = Edge(source, destination, 10.0);
         * ------------------------------------------------
         * Constructor which sets the source Vertex, the destination Vertex and the
         * weight for this Edge.
         */
        Edge(Vertex*, Vertex*, double);

        /*
         * Destructor
         * Function: ~Edge
         * Usage: implicit
         */
        ~Edge();

        /*
         * Accessor
         * Function: GetSource
         * Usage: source = edge.GetSource();
         * ------------------------------------------------
         * Returns a Pointer to the source Vertex
         */
        Vertex* GetSource();

        /*
         * Accessor
         * Function: GetDestination
         * Usage: destination = edge.GetDestination();
         * ------------------------------------------------
         * Returns a Pointer to the destination Vertex
         */
        Vertex* GetDestination();

        /*
         * Accessor
         * Function: GetWeight
         * Usage: weight = edge.GetWeight();
         * ------------------------------------------------
         * Returns the weight of this Edge
         */
        double GetWeight();

        /*
         * Function: ToString
         * Usage: edgeDetais = edge.ToString();
         * ------------------------------------------------
         * Returns a string representation of this Edge. For testing purposes.
         */
        string ToString();

    private:

        // Private variables to store source, destination and weight of this Edge
        Vertex* source;
        Vertex* destination;
        double edgeWeight;

};

#endif // _edge_h
