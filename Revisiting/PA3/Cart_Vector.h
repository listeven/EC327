#ifndef CART_VECTOR_H
#define CART_VECTOR_H
#include <iostream>

using namespace std;

class Cart_Vector{
public:
	double x;
	double y;
	Cart_Vector();
	Cart_Vector(double, double);
};

Cart_Vector operator*(Cart_Vector, double);

Cart_Vector operator/(Cart_Vector, double);

ostream& operator<<(ostream&, Cart_Vector);

#endif