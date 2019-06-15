#include "Cart_Point.h"
//#include "Cart_Vector.h"
//#include <iostream>
#include <math.h>

using namespace std;

Cart_Point::Cart_Point(){
	x = 0.0;
	y = 0.0;
}

Cart_Point::Cart_Point(double inputx, double inputy){
	x = inputx;
	y = inputy;
}

double cart_distance(Cart_Point p1, Cart_Point p2){
	return sqrt( (pow(p1.x - p2.x, 2)) + (pow(p1.y - p2.y, 2)) );
}

ostream& operator<<(ostream& outStream, Cart_Point p1){
	outStream << "(" << p1.x << ", " << p1.y << ")";
}


Cart_Point operator+(Cart_Point p1, Cart_Vector v1){
	Cart_Point pOut = Cart_Point(p1.x + v1.x, p1.y + v1.y);
	return pOut;
}

Cart_Vector operator-(Cart_Point p1, Cart_Point p2){
	Cart_Vector vOut = Cart_Vector(p1.x - p2.x, p1.y - p2.y);
	return vOut;
}

bool operator!=(Cart_Point p1, Cart_Point p2){
	if(p1.x != p2.x || p1.y != p2.y)
		return true;
	else
		return false;
}

bool operator==(Cart_Point p1, Cart_Point p2){
	if(p1.x == p2.x && p1.y == p2.y)
		return true;
	else
		return false;
}