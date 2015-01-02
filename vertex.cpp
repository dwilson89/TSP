/*
 * Author: Dustin Wilson, 06325157
 * File: vertex.cpp
 * --------------------------------------------------------
 * This file is responsible for providing implementation for the functions in
 * which to use to access this Vertex's information, in addition to storing
 * the adjacent vertices of this Vertex for use in Minimum Spanning Tree of the
 * Graph
 */
#include "vertex.h"

#include <sstream>
#include <fstream>
#include <iomanip>

/*
 * Constructor
 * Param: integer for identifier for this Vertex
 * Usage: Vertex vertex = Vertex(0);
 * ------------------------------------------------
 * Constructs a new Vertex ad sets its identifier.
 */
Vertex::Vertex(int id) {

    identifier = id;
    adjVertexes.resize(0);//initialise as empty vector

}// end Vertex(int)

/*
 * Destructor
 * Usage: implicit
 * ------------------------------------------------
 * Destructor deletes each Vertex* in the adjacent collection.
 */
Vertex::~Vertex() {

    for (unsigned i = 0; i < adjVertexes.size(); i++)
        delete adjVertexes[i];

}// end ~Vertex()

/*
 * Accessor
 * Function: GetId
 * Usage: id = vertex.GetId();
 * ------------------------------------------------
 * Returns the Vertex' identifier.
 */
int Vertex::GetId() {

    return identifier;

}// end GetId()

/*
 * Function: AddAdjacency
 * Param: Pointer to adjacent Vertex
 * Usage: vertex.AddAdjacency(adjVertex)
 * ------------------------------------------------
 * Adds a pointer to a Vertex to this Vertex' adjacency list.
 */
void Vertex::AddAdjacency(Vertex* adjVertex) {

    adjVertexes.push_back(adjVertex);

}// end AddAdjacency(Vertex*)

/*
 * Accessor
 * Function: GetAdjacencies
 * Usage: adjList = vertex.GetAdjacencies();
 * ------------------------------------------------
 * Returns this Vertex' adjacency list.
 */
vector<Vertex*> Vertex::GetAdjacencies() {

    return adjVertexes;

}// end GetAdjacencies()

/*
 * Function: ToString
 * Usage: vertexInfo = vertex.ToString();
 * ------------------------------------------------
 * Returns a string reresentation of this vertex; it's identifier and
 * it adjacency list. For testing purposes.
 */
string Vertex::ToString() {

    string vertices = "Vertex ";

    // converts the identifier to a string
    stringstream convert;
    convert << identifier;
    vertices += convert.str();
    vertices += " has the following adjacent vertices: ";

    // for converting the id of adjacent vertices
    stringstream convertTwo;

    int adjId;
    int adjVerticesSize = adjVertexes.size();

    // Lists the adjacent vertices
    for (int i = 0; i < adjVerticesSize; i++) {

        adjId = adjVertexes[i]->identifier;

        convertTwo << adjId << setw(2);

    }// end for

    vertices += convertTwo.str() + "\n";

    return vertices;

}// end ToString()
