#include "Gold_Mine.h"
#include <iostream>

using namespace std;

Gold_Mine::Gold_Mine():Game_Object('G', 0){
	state = 'f';
	amount = 100.0;
	cout << "Gold_Mine default constructed" << endl;
}

Gold_Mine::Gold_Mine(int inputId, Cart_Point inputLoc):Game_Object('G', inputId, inputLoc){
	state = 'f';
	amount = 100.0;
	cout << "Gold_Mine constructed" << endl;
}

bool Gold_Mine::is_empty(){
	if(amount == 0.0)
		return true;
	else
		return false;
}

double Gold_Mine::dig_gold(double amount_to_dig){
	if(amount >= amount_to_dig){
		amount = amount - amount_to_dig;
		return amount_to_dig;
	}
	else{
		double tempAmt = amount;
		amount = 0.0;
		return tempAmt;
	}
}

bool Gold_Mine::update(){
	if(amount == 0.0 && state == 'f'){
		state = 'e';
		display_code = 'g';
		cout << "Gold_Mine " << get_id() << " has been depleted." << endl;
		return true;
	}
	else{
		return false;
	}
}

void Gold_Mine::show_status(){
		cout << "Gold Mine status: " << display_code << get_id() << " at location " << get_location() << " Contains " << amount << "." << endl;
}

Gold_Mine::~Gold_Mine(){
	cout << "Gold Mine " << get_id() << " destructed." << endl;
}