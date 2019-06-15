#include "Statistics.h"
#include <algorithm>    // min

using namespace std;

float getMean(int* myArray, int size)			// Takes in array and a size
{
	float total = 0; 
	float mean;   	
	for(int i = 0; i < size; i++){			// For each element in array, add it all up and then divide by size to get mean
		total += myArray[i];
	}
	mean = total / size;
	return mean;
}

float getStDev(int* myArray, int size, float mean){
	double sum = 0;	
	double tol = 1e-6; 				// Tolerance for square root convergence test
	double val;
	double guess;
	double N;
	double conVal;
	double num;

	for(int i = 0; i < size; i++)			// Sum the values of (x[i] - mean)^2
	{
		val = myArray[i] - mean;
		sum += val*val; 
	}
	sum = sum/size;					// Divide by N to get the value under square root in our equation
	guess = sum;					// Set up to find square root using convergence. From Lab4
	N = guess;
	do{
	    	guess = (guess + (N / guess)) / 2;
		num = (guess - N / guess);
		if(num < 0)
			num *= -1;
	    	conVal = num / min(guess, N / guess);
	}while (conVal > tol);

	return (float)guess; 
	
}
