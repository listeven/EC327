#include <iostream>

using namespace std;

int gcd(int m, int n){				// Followed description in assignment
	if((m%n) == 0)				// Base case 
		return n;
	else
		return gcd(n,m%n);		// Recursively call with different parameters
}

int main(){
	int m, n;
	cout << "Enter m: ";
	cin >> m;
	cout << "Enter n: ";
	cin >> n;
	if(m <= 0 || n <= 0){			// Check that both inputs are positive numbers
		cout << "Error. Can't use negative numbers." << endl;
		return 0;
	}
	else
		cout << "GCD is: " << gcd(m,n) << endl;
	return 0;
}
