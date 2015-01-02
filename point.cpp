/*
 * Author: Dustin Wilson, 06325157
 * File: point.cpp
 * ------------------------------------
 * This is the implementation file for the Point class which provides the
 * functionality for calculating the distance between two instances of Point
 * objects
 */

#include "point.h"

#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

/*
 * Constructor
 * Param 1: integer for x coordinate
 * Param 2: integer for y coordinate
 * Usage: Point point = Point(0,0);
 * ------------------------------------------------
 * Constructs a new point and sets its x and y coordinates.
 */
Point::Point(int x, int y) {
    coordX = x;
    coordY = y;

}// end Point(int, int)

/*
 * Destructor
 * Usage: implicit
 */
Point::~Point() {

    // Does nothing

}// end ~Point()

/*
 * Function: DistanceTo
 * Param: Pointer to point, the other point used to determine distance
 * Usage: distance = point.DistanceTo(pointTwo);
 * ------------------------------------------------
 * Calculates and returns the Euclidean distance between this Point and
 * the Point* given in the parameter of this function.
 */
double Point::DistanceTo(Point* point) {

    // Calculates the difference between each point respectively
    int x = this->coordX - point->coordX;
    int y = this->coordY - point->coordY;

    // square x and y
    x = x * x;
    y = y * y;

    // square-roots the value
    double d = sqrt(x + y);

    return d;

}// end DistanceTo(Point*)

/*
 * Function: ToString
 * Usage: coords = point.ToString();
 * ------------------------------------------------
 * Returns a string representation of this Point, x and y coordinations.
 */
string Point::ToString() {

    // Converts the interger values into a string representation
    stringstream convert;

    convert << setw(3) << coordX << " " << setw(3) << coordY;

    return convert.str();

}// end ToString()

//#endif
