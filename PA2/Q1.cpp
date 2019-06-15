#include <iostream>
#include <string>
#include <iomanip>	// precision
#include <sstream>	// for stringstream
#include <stdlib.h>     // srand, rand
#include "funcLib.h"

using namespace std;

extern const int ENTRIES = 23;

int main(){
	initialize();									// Call initialize function
	bool valid = true;								// valid to determine if we are still looping
	while(valid){									// Keep looping while valid is true
		char cmd;
		cout << endl << "Please enter command code: ";
		cin >> cmd;								// Input command code
		int ascii = (int)cmd;
		if(ascii >= 97 && ascii <= 122)
			ascii -= 32;
		cmd = ascii;								// If lowercase, change to uppercase for convenience.
		double first, last, delta;
		if(!checkCode(cmd))							// Call checkCode function to determine if the command is valid
			cout << "Not a valid command..." << endl;
		else if(cmd == 'Q'){
			valid = false;							// If command code is Q, we want to stop looping so we set valid to false
			cout << "quitting...." << endl;
		}
		else if(cmd == 'P'){							// If command code is P, we want to read from an input file
			const char * fileName = "q1Input.txt";
			readDataFromFile(fileName);
		}
		else if(cmd == 'O'){							// If command code is O, generate the output file described 
         		const char * fileName = "q1Output.txt";
			writeDataToFile(fileName);
			cout << "file has been written..." << endl;
		}
		else{
			cout << "Please enter command parameters: ";
			cin.ignore();							// Reset cin
			first = 0;							// Reset first, last, delta
			last = 0;
			delta = 0;
			string s;
			getline(cin, s);						// Takes entire line from cin and puts it in string s
			istringstream ss(s);						// Makes stringstream out of our string
			ss >> first >> last >> delta;					// Use our input stringstream to input our values
			if(first > last || delta <= 0){					// Error check the values
				cout << "No Computation needed" << endl;
			}
			else{								// If no errors, check our command codes to determine which function
				if(cmd == 'U'){						// If command code is U, call our square function to print area of square
					square(first, last, delta);
				}
				else if(cmd == 'C'){					// If command code is C, call our circle function to print circumference
					circle(first, last, delta);
				}
				else if(cmd == 'R'){					// If command code is R, call root function to print square root values
					root(first, last, delta);
				}
				else if(cmd == 'D'){					// If command code is D, call odd function to print odd values
					odd(first, last);
				}
				else if(cmd == 'L'){					// If command code is L, call lucky function to print lucky numbers
					lucky(first, last, delta);
				}
				else if(cmd == 'S'){					// If command code is S, call sine function to print sin values
					sine(first, last, delta);
				}
				else if(cmd == 'N'){					// If command code is N, call cosine function to print cos values
					cosine(first, last, delta);
				}
				else if(cmd == 'E'){					// If command code is E, call expon function to print exp values
					expon(first, last, delta);
				}
				else if(cmd == 'A'){					// If command code is A, call ln function to print ln values
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
	}
	return 0;

}
