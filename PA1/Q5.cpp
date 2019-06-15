#include <iostream>

using namespace std;

int main(){
	char ltr;	
	cout << "Enter a letter: ";
	cin >> ltr;
	int ascii = (int)ltr;					// Gets the ascii value of our char
	int valid;						// Determine if we should print the crypto message
	if((65 <= ascii) && (ascii <= 89)){			// Uppercase
		ascii++;
		valid = 1;
	}
	else if((97 <= ascii) && (ascii <= 121)){		// Lowercase
		ascii -= 31;					// Offset is 32 to get uppercase so use 31 to get next letter
		valid = 1;	
	}
	else if(ascii == 90 || ascii == 122){			// For letter z, both lowercase and uppercase will go to A
		ascii = 65;
		valid = 1;
	}
	else{							// Error message when you don't input a letter
		cout << "YOU DID NOT ENTER A LETTER" << endl;
		valid = 0;
	}
	if(valid == 1){						// If valid input, print result
		char out = ascii;				// Convert from ascii to char
		cout << "CRYPTO: " << out << endl;
	}
	return 0;
}
