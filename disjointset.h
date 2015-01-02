/*
 * Author: Dustin Wilson, 06325157
 * File: disjointSet.h
 * --------------------------------------------------------
 * This interface is reponsible for providing functionality for a data structure
 * with very efficient look-up in addition to a very efficient means of joining two
 * sets together.
 */

#ifndef _disjointset_h
#define _disjointset_h

/* Disjoint Set type definition, consisint of a size and two collections id and sizeArray */
class DisjointSet
{
    public:

        /*
         * Constructor
         * Funtion: DisjointSet
         * Param: integer for size of the DisjointSet
         * Usage: set = DisjointSet(5);
         * ------------------------------------------------
         * Constuctor which sets the size of this DisjointSet.
         */
        DisjointSet(int);

        /*
         * Destructor
         * Function: ~DisjointSet
         * Usage: implicit
         */
        ~DisjointSet();

        /*
         * Function: Find
         * Param: integer; element in the parent set
         * Usage: i = Find(indexOne);
         * ------------------------------------------------
         * Returns to the index of the parent set of the element in the parameter.
         */
        int Find(int);

        /*
         * Function: Union
         * Param 1: integer for index 1
         * Param 2: integer for index 2
         * Usage: set.Union(1,0);
         * ------------------------------------------------
         * Creates the union of two disjoint sets whose indexes are passsed as parameters
         */
        void Union(int, int);

        /*
         * Function: SameComponent
         * Param 1: integer for index 1
         * Param 2: integer for index 2
         * Usage: isSame = set.SameComponent(1, 0);
         * ------------------------------------------------
         * Returns true if the two indexes passed as parameters are in the same set.
         */
        bool SameComponent(int, int);

    private:

        // Collections for this DisjointSet
        int* id;
        int* sizeArray;

        // Size of set
        int setSize;

};

#endif // _disjointset_h
