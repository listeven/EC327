#include <iostream>
#include <iomanip>	// precision
#include <cmath>
#include "funcLib.h"
#include <stdio.h>
#include <stdlib.h>     // srand, rand
#include <fstream> 	// file io
#include <string>
#include <sstream>	// stringstream


extern const int ENTRIES;

using namespace std;

void initialize(){
	cout << "327: Introduction to Software Engineering" << endl;			
	cout << "Fall 2016" << endl;
	cout << "Programming Assignment 2" << endl;
	cout << "Maximum computation is: " << ENTRIES << endl;
}

bool checkCode(char cmd){	// Returns true if the command code is one of our valid ones
	if(cmd == 'U' || cmd == 'C' || cmd == 'R' || cmd == 'D' || cmd == 'L' || cmd == 'S' || cmd == 'N' || cmd == 'E' || cmd == 'A' || cmd == 'Y' || cmd == 'P' || cmd == 'O' || cmd == 'Q')
		return true;
	else
		return false;
}

void square(double first, double last, double delta){			// Calculates area of square by squaring the value
	double square = 0.0;
	int count = 0;
	while((first <= last) && (count < ENTRIES)){			// Loops while we are in our desired range and we have not exceeded our entries limit
		square = first*first;
		cout << "Area of square with side length " << fixed << setprecision(2) << first << " = " << fixed << setprecision(4) << square << endl;
		first += delta;
		count++;
	}
}

void circle(double first, double last, double delta){			// Calculate circumference using 2*3.14*r where first is our r
	double circum = 0.0;
	int count = 0;
	while((first <= last) && (count < ENTRIES)){			// Loops while we are in our desired range and we have not exceeded our entries limit
		circum = 6.28 * first;
		cout << "Circumference of circle with radius " << fixed << setprecision(2) << first << " = " << fixed << setprecision(4) << circum << endl;
		first += delta;
		count++;
	}
}

void root(double first, double last, double delta){			// Use sqrt function from cmath to calculate square root values
	int count = 0;
	double rt;
	while((first <= last) && (count < ENTRIES)){			// Loops while we are in our desired range and we have not exceeded our entries limit
		rt = sqrt(first);
		cout << "Square root of " << fixed << setprecision(2) << first << " = " << fixed << setprecision(4) << rt << endl;
		first += delta;
		count++;
	}
}

void odd(double first, double last){					// Prints odd numbers within our stated range
	int count = 0;
	int val;
	cout << "Odd numbers from " << fixed << setprecision(2) << first << " to " << fixed << setprecision(2) << last << " =";
	while((first <= last) && (count < ENTRIES)){			// Loops while we are in our desired range and we have not exceeded our entries limit
		if(first > ((int)first))				// Cast to int and rounds up to next int value if it has a decimal component
			val = (int)(first+1);
		else
			val = first;
		if((val % 2) == 1)
			cout << " " << fixed << setprecision(2) << val;
		first++;
		count++;
	}
	cout << endl;
}

void lucky(double first, double last, double delta){			// Generate lucky numbers using srand() and rand()
	double lNum;
	int count = 0;
	while((first <= last) && (count < ENTRIES)){			// Loops while we are in our desired range and we have not exceeded our entries limit
		srand(first);						// Seed with the input value (first)
		lNum = rand();
		cout << "Lucky number of " << fixed << setprecision(2) << first << " = " << fixed << setprecision(4) << lNum << endl;
		first += delta;
		count++;
	}
}

void sine(double first, double last, double delta){			// Calculate sin values with sin() from cmath
	double sinVal;
	int count = 0;
	while((first <= last) && (count < ENTRIES)){			// Loops while we are in our desired range and we have not exceeded our entries limit
		sinVal = sin(first);
		cout << "Sine of " << fixed << setprecision(2) << first << " = " << fixed << setprecision(4) << sinVal << endl;
		first += delta;
		count++;
	}	
}

void cosine(double first, double last, double delta){			// Calculate cos values with cos() from cmath
	double cosVal;
	int count = 0;
	while((first <= last) && (count < ENTRIES)){			// Loops while we are in our desired range and we have not exceeded our entries limit
		cosVal = cos(first);
		cout << "Cosine of " << fixed << setprecision(2) << first << " = " << fixed << setprecision(4) << cosVal << endl;
		first += delta;
		count++;
	}	
}

void expon(double first, double last, double delta){			// Calculate exp values with exp() from cmath
	double val;
	int count = 0;
	while((first <= last) && (count < ENTRIES)){			// Loops while we are in our desired range and we have not exceeded our entries limit
		val = exp(first);
		cout << "Exponential of " << fixed << setprecision(2) << first << " = " << fixed << setprecision(4) << val << endl;
		first += delta;
		count++;
	}	
}

void ln(double first, double last, double delta){			// Calculate natural log values with log() from cmath
	double val;
	int count = 0;
	while((first <= last) && (count < ENTRIES)){			// Loops while we are in our desired range and we have not exceeded our entries limit
		val = log(first);
		cout << "Natural Log of " << fixed << setprecision(2) << first << " = " << fixed << setprecision(4) << val << endl;
		first += delta;
		count++;
	}	
}

double findNyanCatValue(double first){					// Calculates NyanCatValue using given equation and the pow function
	double val = pow((3*first), first) + first;			
	return val;
}

void writeDataToFile(const char* fileName){				// Creates new output file that we write results to
	srand (time(NULL));						// Seed with time
	double val;
	int count = 0;
	int first = rand() % 21;					// Rand with range 0 - 20
	int last = (rand() % 32) + 45;					// Rand with range 45 - 76
	int delta = (rand() % 6) + 5;					// Rand with range 5 - 10
	ofstream myFile;
	myFile.open(fileName);
	while((first <= last) && (count < ENTRIES)){			// Loops while we are in our desired range and we have not exceeded our entries limit
		myFile << "Nyan Cat Value of " << fixed << setprecision(2) << first << " = " << fixed << setprecision(4) << findNyanCatValue(first) << endl;
		first += delta;
		count++;
	}	
}

void readDataFromFile(const char* fileName){				// Read from input file stated
	ifstream input(fileName);
	char cmd;
	double first, last, delta;
	string sfirst, slast, sdelta;
	while(!input.eof()){						// While we're not at the end of our file
		first = 0;						// Reset values
		last = 0;
		delta = 0;
		string s;
		getline(input, s);					// Take line of input and put in string s
		istringstream ss(s);					// Create input stringstream from our string s
		ss >> cmd >> sfirst >> slast >> sdelta;			// Input values from our stringstream
		cout << "Successfully read data from file: Code " << cmd << " First " << sfirst << " Last " << slast << " Delta " << sdelta << endl;
		first = atof(sfirst.c_str());
		last = atof(slast.c_str());
		delta = atof(sdelta.c_str());
		int ascii = (int)cmd;					// If lowercase letter, make it uppercase
		if(ascii >= 97 && ascii <= 122)
			ascii -= 32;
		cmd = ascii;

		if(!checkCode(cmd))					// Same functionality as our main, check for errors then call appropriate functions when no errors occur
			cout << "Not a valid command..." << endl;
		else if(cmd == 'Q'){
			cout << "quitting...." << endl;
			break;
		}
		else if(cmd == 'P'){
			const char * fileName = "q1Input.txt";
			readDataFromFile(fileName);
		}
		else if(cmd == 'O'){
         		const char * fileName = "q1Output.txt";
			writeDataToFile(fileName);
			cout << "file has been written..." << endl;
		}
		else{
			if(first > last || delta <= 0){
				cout << "No Computation needed" << endl;
			}
			else{
				if(cmd == 'U'){
					square(first, last, delta);
				}
				else if(cmd == 'C'){
					circle(first, last, delta);
				}
				else if(cmd == 'R'){
					root(first, last, delta);
				}
				else if(cmd == 'D'){
					odd(first, last);
				}
				else if(cmd == 'L'){
					lucky(first, last, delta);
				}
				else if(cmd == 'S'){
					sine(first, last, delta);
				}
				else if(cmd == 'N'){
					cosine(first, last, delta);
				}
				else if(cmd == 'E'){
					expon(first, last, delta);
				}
				else if(cmd == 'A'){
					ln(first, last, delta);
				}
				else if(cmd == 'Y'){					// If command code is Y, call findNyanCatValue function to print Nyan Cat values
					int count = 0;
					while((first <= last) && (count < ENTRIES)){	// Loops while we are in our desired range and we have not exceeded our entries limit
						cout << "Nyan Cat Value of " << fixed << setprecision(2) << first << " = " << fixed << setprecision(4) << findNyanCatValue(first) << endl;
						first += delta;
						count++;
					}
				}
			}
		}
		cout << endl;

	}
}







































