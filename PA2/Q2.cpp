#include <iostream>
#include "FileFunctions.h"
#include "Statistics.h"
#include <stdlib.h>     // srand, rand
#include <time.h>	

using namespace std;

int main(){
	int M, N;					// Declare our M, N
	int size = 1000;
	srand(time(NULL));				// Seed with time for rand()
	int* myArray = new int[size];			// Allocate memory in heap for max size
	float mean, stdDev;				// Outputs from our functions
	const char * fileName = "numbers.txt";		// Name of our file
	M = rand() % 1001;				// M and N are values between 0 and 1000
	N = rand() % 1000 + 1;
	WriteRandomDataToFile(fileName, N, M);		// Call WriteRandomDataToFile to generate a new numbers.txt file
	ReadDataFromFile(fileName, myArray, size);	// Call ReadDataFromFile to analyze the numbers and put it into our array and get the real size

	mean = getMean(myArray, size);			// Call getMean to calculate mean value
	stdDev = getStDev(myArray, size, mean);		// Call getStDev to calculate standard Dev

	cout << "Array size is: " << size << endl;	// Print our values
	cout << "Mean is: " << mean << endl;
	cout << "Standard Deviation is: " << stdDev << endl;

	return 0;	
}
