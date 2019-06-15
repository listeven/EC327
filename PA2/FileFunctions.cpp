#include <iostream>
#include <fstream> 
#include <stdlib.h>     // srand, rand
#include <time.h>
#include <stdio.h>
#include "FileFunctions.h"

using namespace std;

void WriteRandomDataToFile(const char* fileName, int N, int M){
	int rnd = 0;
	srand (time(NULL));			// Seed with time for rand()
	ofstream myFile;
	myFile.open(fileName);			// myFile is our opened input fileName
	if(!(N < 0 || M < 0)){			// Check if both are positive
		for(int i = 0; i < N; i++){	// Get a new random number from 0 - M and enter it into our file
			rnd = rand() % (M+1);
			myFile << rnd << endl;
		}
	}

}

void ReadDataFromFile(const char* fileName, int* &myArray, int &size){
	ifstream input(fileName);		// Open file as our input stream
	int temp;
	int i = 0;
	while(!input.eof()){			// While not at end of function, we will take the input and put it into our array
		input >> temp;
		if(input.eof())
			break;
		myArray[i] = temp;
		i++;
	}	
	size = i;
}
