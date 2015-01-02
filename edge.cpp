/*
 * Author: Dustin Wilson, 06325157
 * File: edge.cpp
 * --------------------------------------------------------
 * This file is responsible for providing the implementation of functions for a
 * Edge, such as storing its weight, source and destination, in addtion to
 * providing functions in which to access such information.
 */

#include "edge.h"
#include <sstream>

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
Edge::Edge(Vertex* src, Vertex* dest, double weight) {

    source = src;
    destination = dest;
    edgeWeight = weight;

}// end Edge(Vertex*, Vertex*, double)

/*
 * Destructor
 * Function: ~Edge
 * Usage: implicit
 */
Edge::~Edge() {

    // do nothing

}// end ~Edge()

/*
 * Accessor
 * Function: GetSource
 * Usage: source = edge.GetSource();
 * ------------------------------------------------
 * Returns a Pointer to the source Vertex
 */
Vertex* Edge::GetSource() {

    return source;

}// end GetSource()

/*
 * Accessor
 * Function: GetDestination
 * Usage: destination = edge.GetDestination();
 * ------------------------------------------------
 * Returns a Pointer to the destination Vertex
 */
Vertex* Edge::GetDestination() {

    return destination;

}// end GetDestination()

/*
 * Accessor
 * Function: GetWeight
 * Usage: weight = edge.GetWeight();
 * ------------------------------------------------
 * Returns the weight of this Edge
 */
double Edge::GetWeight() {

    return edgeWeight;

}// end GetWeight()

/*
 * Function: ToString
 * Usage: edgeDetais = edge.ToString();
 * ------------------------------------------------
 * Returns a string representation of this Edge. For testing purposes.
 */
string Edge::ToString() {

    string edge = "Edge: ";
    int src = source->GetId();
    int dst = destination->GetId();

    // Converts information into a string
    stringstream convertSource;
    stringstream convertDestination;
    stringstream convertWeight;
    convertSource >> src;
    convertDestination >> dst;
    convertWeight >> edgeWeight;

    edge += convertSource.str() + "- " + convertDestination.str() + ": Weight: "
            + convertWeight.str();

    return edge;

}// end ToString()
