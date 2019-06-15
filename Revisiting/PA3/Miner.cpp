#include "Miner.h"
#include <iostream>

// Need to change the show status of miner when it is getting gold at a mine or depositing at town hall
// It says it is still moving to the location

using namespace std;

Miner::Miner():Person('M'){
	amount = 0;
	mine = 0;
	home = 0;
	cout << "Miner default constructed." << endl;
}

Miner::Miner(int in_id, Cart_Point in_loc):Person('M', in_id, in_loc){
	amount = 0;
	mine = 0;
	home = 0;
	cout << "Miner constructed." << endl;
}

bool Miner::update(){
	switch(state){
		case 's': 
			break;
		case 'm': 
		{
			if(update_location()){
				state = 's';
				return true;
			}
			break;
		}
		case 'o': 
		{
			if(update_location()){
				state = 'g';
				return true;
			}
			break;
		}
		case 'g':
		{
			int gotAmt = mine->dig_gold();
			amount += gotAmt;
			cout << display_code << get_id() << ": Got " << gotAmt << " gold." << endl;
			setup_destination(home->get_location());
			state = 'i';
			return true;
			break;
		}
		case 'i':
		{
			if(update_location()){
				state = 'd';
				return true;
			}
			break;
		}
		case 'd':
		{
			cout << display_code << get_id() << ": Deposit " << amount << " gold." << endl;
			home->deposit_gold(amount);
			amount = 0;
			if(mine->is_empty()){
				state = 's';
				cout << display_code << get_id() << ": More work?" << endl;
				return true;
			}
			else{
				setup_destination(mine->get_location());
				state = 'o';
				cout << display_code << get_id() << ": Going back for more. " << endl;
				return true;
			}
		}
		case 'x':
		{
			break;
		}
	}
	return false;
}

void Miner::show_status(){
	cout << "Miner status: " << display_code << get_id() << " at " << location;
	switch(state){
		case 's': 
		{
			cout << " with health of " << get_health() << " is stopped." << endl;
			break;
		}
		case 'm': 
		{
			Person::show_status();
			cout << endl;
			break;
		}
		case 'o':
		{	
			Person::show_status();
			cout << " is outbound to a mine." << endl;	
			break;
		} 
		case 'g': 
		{
			Person::show_status();
			cout << " is getting gold from mine." << endl;
			break;
		}
		case 'i':
		{
			Person::show_status();
			cout << " is inbound to home with load: " << amount << endl;
			break;
		}
		case 'd':
		{
			Person::show_status();
			cout << " is depositing gold." << endl;	
			break;
		}
		case 'x':
		{
			Person::show_status();
			break;
		}
	}
}

void Miner::start_mining(Gold_Mine* inputMine, Town_Hall* inputHome){
	if(state == 'x'){
		cout << "Miner " << get_id() << " is dead and cannot perform an action." << endl;
	}
	else{
		mine = inputMine;
		home = inputHome;
		setup_destination(mine->get_location());
		state = 'o';
		//cout << "Miner " << get_id() << " mining at Gold_Mine " << inputMine->get_id() << " and depositing at Town_Hall " << inputHome->get_id() << "." << endl;
		cout << display_code << get_id() << ": Yes, my lord." << endl;		
	}
}

Cart_Point Miner::get_location(){
	cout << "Miner status: ";
	Person::show_status();
	return location;
}

Miner::~Miner(){
	cout << "Miner " << get_id() << " destructed." << endl;
}