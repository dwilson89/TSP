/*
 * Author: Dustin Wilson, 06325157
 * File: point.h
 * -------------------------------------------------------
 * This interface is responsible for providing a function for calculating the
 * distance between two instances of Point objects
 */

#ifndef _point_h
#define _point_h
#include <iostream>

using namespace std;

/* Point type definition, consisting on a x and y coordinate */
class Point {

    public:

        /*
         * Constructor
         * Param 1: integer for x coordinate
         * Param 2: integer for y coordinate
         * Usage: Point point = Point(0,0);
         * ------------------------------------------------
         * Constructs a new Point and sets its x and y coordinates.
         */
        Point(int x, int y);

        /*
         * Destructor
         * Usage: implicit
         */
        ~Point();

        /*
         * Function: DistanceTo
         * Param: Pointer to point, the other point used to determine distance
         * Usage: distance = point.DistanceTo(pointTwo);
         * ------------------------------------------------
         * Calculates and returns the Euclidean distance between this Point and
         * the Point* given in the parameter of this function.
         */
        double DistanceTo(Point* point);

        /*
         * Function: ToString
         * Usage: coords = point.ToString();
         * ------------------------------------------------
         * Returns a string representation of this Point, x and y coordinations.
         */
        string ToString();

    private:

        // Private coordinate values
        int coordX;
        int coordY;

};

#endif // _point_h
