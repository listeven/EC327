#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;
							// Overloaded function to be used in main
int blackjack(int x, int y){				// int, int
	int total = x + y;
	return total;
}

int blackjack(char x, char y){				// char, char
	int xVal, yVal;	
	if((x == 'J') || (x == 'Q') || (x = 'K')){	// J, Q, K are equal to 10
		xVal = 10;
	}
	else if(x == 'A'){				// A is equal to 11
		xVal = 11;
	}
	if((y == 'J') || (y == 'Q') || (y = 'K')){
		yVal = 10;
	}
	else if(y == 'A'){
		yVal = 11;
	}
	int total = xVal + yVal;
	return total;
}

int blackjack(char x, int y){				// char, int
	int xVal;	
	if((x == 'J') || (x == 'Q') || (x = 'K')){
		xVal = 10;
	}
	else if(x == 'A'){
		xVal = 11;
	}
	int total = xVal + y;
	return total;
}

int blackjack(int x, char y){				// int, char
	int yVal;	
	if((y == 'J') || (y == 'Q') || (y = 'K')){
		yVal = 10;
	}
	else if(x == 'A'){
		yVal = 11;
	}
	int total = x + yVal;
	return total;
}

int blackjack(int x){					// Just int. Not used
	return x;
}

int blackjack(char x){					// Just char.
	int xVal;	
	if((x == 'J') || (x == 'Q') || (x = 'K')){
		xVal = 10;
	}
	else if(x == 'A'){
		xVal = 11;
	}
	return xVal;
}

int main(){
	int total;					// Running total
	char draw = 'y';				// Do we draw again or not
	char a,b;					// Cards if J, Q, K, A
	srand (time(NULL));				// Seed for rand func
	int x = rand() % 13 + 2;			// Random number between 2 and 14
	int y = rand() % 13 + 2;			// Random number between 2 and 14

	if(x > 10){					// If x>10 then we have a J,Q,K, or A
		if(x == 11){
			a = 'J';
		}
		else if(x == 12){
			a = 'Q';
		}
		else if(x == 13){
			a = 'K';
		}
		else if(x == 14){
			a = 'A';
		}
	}
	if(y > 10){					// If y>10 then we have a J,Q,K, or A
		if(y == 11){
			b = 'J';
		}
		else if(y == 12){
			b = 'Q';
		}
		else if(y == 13){
			b = 'K';
		}
		else if(y == 14){
			b = 'A';
		}		
	}						// Choose which function to use based on what cards we chose
	if((x > 10) && (y > 10)){			// char, char
		total = blackjack(a,b);
	}
	else if((x > 10) && (y <= 10)){			// char, int
		total = blackjack(a,y);	
	}	
	else if((x <= 10) && (y > 10)){			// int, char
		total = blackjack(x,b);
	}
	else if((x <= 10) && (y <= 10)){		// int, int
		total = blackjack(x,y);
	}
	
	cout << "Welcome to EC327 Black Jack" << endl << "Total: " << total << endl;
	
	while((draw == 'y') && (total < 21)){		// While loop for determining how the game continues
		cout << "Draw Again (y/n): ";		// Prompts for draw again
		cin >> draw;
		if(draw == 'n'){
			cout << "Total: " << total << endl << "YOU QUIT WITH " << total << endl;
		}
		else if(draw == 'y'){
			int z = rand() % 13 + 2;	// Next card
			int newC;			// For value to be added
			char c;
			if(z > 10){
				if(z == 11){
					c = 'J';
				}
				else if(z == 12){
					c = 'Q';
				}
				else if(z == 13){
					c = 'K';
				}
				else if(z == 14){
					c = 'A';
				}
				newC = blackjack(c);
				total += newC;
			}
			else{
				total += z;		// Didn't call function because it just returns the input
			}
			cout << "Total: " << total << endl;
		}
		else{
			cout << "Total: " << total << endl << "ERROR OCCURED" << endl;
			break;
		}
	}
	
	if(total == 21){				// If running total is 21, you win
		cout << "WON BLACKJACK" << endl;
	}
	if(total > 21){
		cout << "FAILED BLACKJACK" << endl;	// If running total exceeds 21, you lose
	}
	
	return 0;
	
}
