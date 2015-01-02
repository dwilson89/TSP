/*
 * Author: Dustin Wilson, 06325157
 * File: edgecomparer.h
 * --------------------------------------------------------
 * This interface is responsible for providing an ordering for determining if
 * one edge is greater than another.
 */

#ifndef _edgecomparer_h
#define _edgecomparer_h

#include "edge.h"

class EdgeComparer
{
    public:

        /*
         * Function: operator()
         * Param 1: Pointer to the first Edge
         * Param 2: Pointer to the second Edge
         * Usage: priority_queue<Edge*, vector<Edge*>, EdgeComparer> edgeList
         * ------------------------------------------------
         * This function returns true if and only if the weight of the first Edge
         * is greater than the weight of the second Edge.
         */
        bool operator()(Edge*, Edge*);
};

#endif // _edgecomparer_h
