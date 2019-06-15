#include "Town_Hall.h"
#include <iostream>

using namespace std;

Town_Hall::Town_Hall():Game_Object('t', 1, Cart_Point()){
	state = 'o';
	amount = 0;
	cout << "Town_Hall default constructed" << endl;
}

Town_Hall::Town_Hall(int inputId, Cart_Point inputLoc):Game_Object('t', inputId, inputLoc){
	state = 'o';
	amount = 0;
	cout << "Town_Hall constructed" << endl;
}

Cart_Point Town_Hall::get_location(){
	return location;
}

void Town_Hall::deposit_gold(double deposit_amount){
	amount += deposit_amount;
}

bool Town_Hall::update(){
	if(amount >= 50 && state != 'u'){
		state = 'u';
		display_code = 'T';
		cout << "Town_Hall " << get_id() << " has been upgraded." << endl;
		return true;
	}
	else
		return false;
}

void Town_Hall::show_status(){
		cout << "Town Hall status: " << display_code << get_id() << " at location " << get_location() << " Contains " << amount << " gold. " ;
		if(state == 'u'){
			cout << "This Town Hall is upgraded." << endl;
		}
		else{
			cout << "This Town Hall is not upgraded." << endl;
		}
}

Town_Hall::~Town_Hall(){
	cout << "Town Hall " << get_id() << " destructed." << endl;
}