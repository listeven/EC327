#include "Soldier.h"
#include <iostream>

using namespace std;


Soldier::Soldier():Person('S'){
	attack_strength = 2;
	range = 2.0;
	cout << "Soldier default constructed." << endl;
}

Soldier::Soldier(int in_id, Cart_Point in_loc):Person('S', in_id, in_loc){
	attack_strength = 2;
	range = 2.0;
	cout << "Soldier constructed." << endl;
}

Soldier::~Soldier(){
	cout << "Soldier " << get_id() << " destructed." << endl;
}

void Soldier::start_attack(Person* in_target){

	if(state == 'x'){
		cout << "Soldier " << get_id() << " is dead and cannot perform an action." << endl;		
	}
	else if(!(in_target->is_alive())){
		cout << "Target is dead and cannot be attacked." << endl;
	}
	else{
		Cart_Point targetLocation = in_target->get_location();
		double distance = cart_distance(location, targetLocation);
		cout << display_code << get_id() << ": ";
		if(distance <= range){
			cout << "Target is in range!" << endl;
			target = in_target;
			state = 'a';
		}
		else{
			cout << "Target is out of range." << endl;
		}		
	}

}

bool Soldier::update(){
	switch(state){
		case 'x':
			break;
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
		case 'a':
		{
			Cart_Point targetLocation = target->get_location();
			double distance = cart_distance(location, targetLocation);
			cout << display_code << get_id() << ": ";
			if(distance <= range){
				if(target->is_alive()){
					cout << "Clang!" << endl;
					target->take_hit(attack_strength);
					return false;
				}
				else{
					cout << "I triumph!" << endl;
					state = 's';
					return true;
				}
			}
			else{
				cout << "Target is out of range." << endl;
				state = 's';
				return true;
			}
		}

	}
	return false;
}

void Soldier::show_status(){
	cout << "Soldier " << get_id() << " status: " << display_code << get_id() << " at " << location;
	if(state == 'a'){
		cout << " with health of " << get_health() << " is attacking " << target->get_code() << target->get_id() << "." << endl;
		//cout << " with health of " << get_health() << " is attacking. " << endl;
	}
	else if(state == 's'){
		cout << " with health of " << get_health() << " is not attacking." << endl;
	}
	else if(state == 'm'){
		Person::show_status();
		cout << " is not attacking." << endl;
	}
	else if(state == 'x'){
		Person::show_status();
	}
}