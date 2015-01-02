/*
 * Author: Dustin Wilson, 06325157
 * File: edgecomparer.h
 * --------------------------------------------------------
 * This file implements an function for ordering, by determining if
 * one edge is greater than another.
 */

#include "edgecomparer.h"

/*
 * Function: operator()
 * Param 1: Pointer to the first Edge
 * Param 2: Pointer to the second Edge
 * Usage: priority_queue<Edge*, vector<Edge*>, EdgeComparer> edgeList
 * ------------------------------------------------
 * This function returns true if and only if the weight of the first Edge
 * is greater than the weight of the second Edge.
 */
bool EdgeComparer::operator()(Edge* one, Edge* two) {

    return (one->GetWeight() > two->GetWeight());

}// end operator()(Edge*, Edge*)
