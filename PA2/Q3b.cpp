#include <iostream>

using namespace std;

double series(int n){					// Followed description in assignment to create equation
	if(n==0)					// Base case
		return 0;
	else{
		double val = n;				// Add new term to previous values from recursion
		return (((2*val)/((3*val)+2)) + series(n-1));
	}
}

int main(){
	int n;
	cout << "Enter n: ";
	cin >> n;
	if(n < 0){					// Check if the number inputted it positive or negative. Only run if positive or 0.
		cout << "Error. No negative numbers please." << endl;
		return 0;
	}
	else
		cout << "Series(" << n << ") is: " << series(n) << endl;
	return 0;
}
