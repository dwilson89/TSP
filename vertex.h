/*
 * Author: Dustin Wilson, 06325157
 * File: vertex.h
 * --------------------------------------------------------
 * This interface is responsible for providing functions in which to use to
 * access this Vertex's information, in addition to storing the adjacent vertices
 * of this Vertex for use in Minimum Spanning Tree of the Graph
 */

#ifndef _vertex_h
#define _vertex_h

#include <iostream>
#include <vector>

using namespace std;

/* Vertex type definition, consisting of an id and a collection of adjacent vertices*/
class Vertex
{
    public:

        /*
         * Constructor
         * Param: integer for identifier for this Vertex
         * Usage: Vertex vertex = Vertex(0);
         * ------------------------------------------------
         * Constructs a new Vertex ad sets its identifier.
         */
        Vertex(int id);

        /*
         * Destructor
         * Usage: implicit
         * ------------------------------------------------
         * Destructor deletes each Vertex* in the adjacent collection.
         */
        ~Vertex();

        /*
         * Accessor
         * Function: GetId
         * Usage: id = vertex.GetId();
         * ------------------------------------------------
         * Returns the Vertex' identifier.
         */
        int GetId();

        /*
         * Function: AddAdjacency
         * Param: Pointer to adjacent Vertex
         * Usage: vertex.AddAdjacency(adjVertex)
         * ------------------------------------------------
         * Adds a pointer to a Vertex to this Vertex' adjacency list.
         */
        void AddAdjacency(Vertex* adjVertex);

        /*
         * Accessor
         * Function: GetAdjacencies
         * Usage: adjList = vertex.GetAdjacencies();
         * ------------------------------------------------
         * Returns this Vertex' adjacency list.
         */
        vector<Vertex*> GetAdjacencies();

        /*
         * Function: ToString
         * Usage: vertexInfo = vertex.ToString();
         * ------------------------------------------------
         * Returns a string reresentation of this vertex; it's identifier and
         * it adjacency list. For testing purposes.
         */
        string ToString();

    private:

        int identifier;
        vector<Vertex*> adjVertexes;

};

#endif // _vertex_h
