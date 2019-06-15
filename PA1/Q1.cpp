#include <cmath>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

int main(){
	double x1, x2, x3;						// Coordinates
	double y1, y2, y3;
	cout << "Enter three x,y coordinates:" << endl;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	double slope = (y2-y1)/(x2-x1);					// Slope equation
	double a = -1*slope;						// Find values of a,b,c
	double b = 1;							
	double c = -1*y1 + (slope*x1);
	double num = abs((a*x3)+(b*y3)+c);				// Numerator of distance equation
	double den = sqrt((a*a)+(b*b));					// Denominator of distance equation
	double d = num/den;						// Distance
	cout << "The shortest distance for (" << x3 << "," << y3 << ") to the line composed of (" << x1 << "," << y1 << ") and (" << x2 << "," << y2 << ") is " << d << "." << endl;
	return 0;
}

