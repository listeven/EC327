#ifndef CART_POINT_H
#define CART_POINT_H

#include "Cart_Vector.h"
//#include <iostream>

using namespace std;

class Cart_Point{
public:
	double x;
	double y;
	Cart_Point();		// Default Constructor
	Cart_Point(double, double);
};

double cart_distance(Cart_Point, Cart_Point);

ostream& operator<<(ostream&, Cart_Point);

Cart_Point operator+(Cart_Point, Cart_Vector);

Cart_Vector operator-(Cart_Point, Cart_Point);

bool operator!=(Cart_Point, Cart_Point);

bool operator==(Cart_Point, Cart_Point);

#endif