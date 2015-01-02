/*
 * Author: Dustin Wilson, 06325157
 * File: disjointSet.cpp
 * --------------------------------------------------------
 * This file is reponsible for implementing the functionality for a data structure
 * with very efficient look-up in addition to a very efficient means of joining two
 * sets together.
 */

#include "disjointset.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/*
 * Constructor
 * Funtion: DisjointSet
 * Param: integer for size of the DisjointSet
 * Usage: set = DisjointSet(5);
 * ------------------------------------------------
 * Constuctor which sets the size of this DisjointSet.
 */
DisjointSet::DisjointSet(int N) {

    setSize = N;

    // intitialise id array
    id = new int[setSize];
    for (int i = 0; i < setSize; i++){

        id[i] = i;

    }// end for

    // intialise sizeArray
    sizeArray = new int[setSize];
    for(int j = 0; j < setSize; j++) {

        sizeArray[j] = 1;

    }// end for

}// end DisjointSet(int)

/*
 * Destructor
 * Function: ~DisjointSet
 * Usage: implicit
 */
DisjointSet::~DisjointSet() {

    delete[] id;
    delete[] sizeArray;

}// ~DisjointSet()

/*
 * Function: Find
 * Param: integer; element in the parent set
 * Usage: i = Find(indexOne);
 * ------------------------------------------------
 * Returns to the index of the parent set of the element in the parameter.
 */
int DisjointSet::Find(int index) {

    while(index != id[index]) {

        id[index] = id[id[index]];

        index = id[index];

    }// end while

    return index;

}// end Find(int)

/*
 * Function: Union
 * Param 1: integer for index 1
 * Param 2: integer for index 2
 * Usage: set.Union(1,0);
 * ------------------------------------------------
 * Creates the union of two disjoint sets whose indexes are passsed as parameters
 */
void DisjointSet::Union(int indexOne, int indexTwo) {

    // indexes for the elements parent set
    int i = Find(indexOne);
    int j = Find(indexTwo);

    if(sizeArray[i] < sizeArray[j]){

        id[i] = j;
        sizeArray[j] += sizeArray[i];

    } else {

        id[j] = i;
        sizeArray[i] += sizeArray[j];

    }// end else if

}// end Union(int, int)

/*
 * Function: SameComponent
 * Param 1: integer for index 1
 * Param 2: integer for index 2
 * Usage: isSame = set.SameComponent(1, 0);
 * ------------------------------------------------
 * Returns true if the two indexes passed as parameters are in the same set.
 */
bool DisjointSet::SameComponent(int indexOne, int indexTwo) {

    return Find(indexOne) == Find(indexTwo);

}//end SameComponent(int, int)
