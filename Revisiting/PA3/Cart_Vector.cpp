//#include "Cart_Vector.h"
#include "Cart_Point.h"
//#include <iostream>


using namespace std;

Cart_Vector::Cart_Vector(){
	x = 0.0;
	y = 0.0;
}

Cart_Vector::Cart_Vector(double inputx, double inputy){
	x = inputx;
	y = inputy;
}

Cart_Vector operator*(Cart_Vector v1, double d){
	Cart_Vector vOut = Cart_Vector(v1.x * d, v1.y * d);
	return vOut;
}

Cart_Vector operator/(Cart_Vector v1, double d){
	Cart_Vector vOut = Cart_Vector(v1.x/d, v1.y/d);
	return vOut;
}

ostream& operator<<(ostream& outStream, Cart_Vector v1){
	outStream << "<" << v1.x << ", " << v1.y << ">";
}