#include <iostream>
#include <iomanip>
#include <math.h>  

using namespace std;

int main(){
	double origBill, taxRate, billPretip, totalTip, totalBill;
	int tipLevel, postTax;
	cout << "Enter the original bill amount: ";							// Prompt for original bill amount
	cin >> origBill;
	while(origBill < 0){										// No negatives
		cout << "Invalid bill amount. Enter the original bill amount: ";
		cin >> origBill;
	}
	cout << "Enter the tax rate %: ";								// Prompt for tax rate
	cin >> taxRate;
	while(taxRate < 0){										// No negatives
		cout << "Invalid tax rate. Enter the tax rate %: ";
		cin >> taxRate;
	}	
	cout << "Enter tip level (1=15%, 2=20%, 3=25%): ";						// Prompt for tip level
	cin >> tipLevel;
	bool validTipLev = (tipLevel == 1 || tipLevel == 2 || tipLevel == 3);
	while(validTipLev == false){									// Check for invalid tip levels
		cout << "Invalid tip level. Enter tip level (1=15%, 2=20%, 3=25%): ";
		cin >> tipLevel;
		validTipLev = (tipLevel == 1 || tipLevel == 2 || tipLevel == 3);
	}
	cout << "Tip on post-tax amount? (1=yes, 2=no): ";						// Prompt for tax option
	cin >> postTax;
	bool validPostTax = (postTax == 1 || postTax == 2);
	while(validPostTax == false){									// Check for invalid tax options
		cout << "Invalid tax option. Tip on post-tax amount? (1=yes, 2=no): ";
		cin >> postTax;
		validPostTax = (postTax == 1 || postTax == 2);
	}

	billPretip = origBill + (origBill*taxRate/100);							// Add original bill amount with tax amount
	if (tipLevel == 1){										// Find tip values based on options
		if (postTax == 1){
			totalTip = 0.15*billPretip;
		}
		else if (postTax == 2){
			totalTip = 0.15*origBill;
		}
	}
	else if (tipLevel == 2){
		if (postTax == 1){
			totalTip = 0.2*billPretip;
		}
		else if (postTax == 2){
			totalTip = 0.2*origBill;
		}	
	}
	else if (tipLevel == 3){
		if (postTax == 1){
			totalTip = 0.25*billPretip;
		}
		else if (postTax == 2){
			totalTip = 0.25*origBill;
		}
	}
	totalBill = totalTip + billPretip;								// Add tip and the bill pre tip
	cout << "The total bill pre-tip is: $" << fixed << setprecision(2) << ceil(100*billPretip)/100 << endl;		// Used << fixed << setprecision(2) to get only 2 decimal places
	cout << "The total tip is: $" << fixed << setprecision(2) << ceil(100*totalTip)/100 << endl;			// Ceil to round up 
	cout << "The total bill post-tip is: $" << fixed << setprecision(2) << ceil(100*totalBill)/100 << endl;
	return 0;
}
