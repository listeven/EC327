#include <iostream>
#include <math.h>       /* pow */

using namespace std;

int main(){

	int hamming = 0;								// Counter
	int x, y, Rx, Ry;			
	cout << "Enter two numbers between 0-100: ";					// Prompt for 2 inputs
	cin >> x >> y;
	while((x>100) || (y > 100) || (x < 0) || (y < 0)){				// Check if inputs are within range
		cout << "Invalid numbers. Enter two numbers between 0-100: ";
		cin >> x >> y;
	}
	Rx = x;
	Ry = y;
	for(int i = 4; i >= 0; i--){							// For loop where i is the power of 3
		int pwr = pow(3, i);							
		if( (Rx/(pwr)) != (Ry/(pwr)) ){						// Check if the value in each place is the same or not
			hamming++;							// If not same, increment counter
		}
		Rx = Rx % (pwr);							// Set Rx and Ry to the remainder after division
		Ry = Ry % (pwr);
	}
	cout << "Hamming distance between " << x << " and " << y << " when numbers are in ternary format is " << hamming << "." << endl;
	return 0;
}
