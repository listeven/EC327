#include "Person.h"
#include <iostream>
#include <math.h>

using namespace std;

Person::Person():Game_Object('P', 0){
	state = 's';
	speed = 5;
	health = 5;
}

Person::Person(char in_code):Game_Object(in_code, 0){
	state = 's';
	speed = 5;
	health = 5;
	cout << "Person default constructed." << endl;
}

Person::Person(char in_code, int in_id, Cart_Point in_loc):Game_Object(in_code, in_id, in_loc){
	state = 's';
	speed = 5;
	health = 5;
	cout << "Person constructed." << endl;
}

void Person::start_moving(Cart_Point dest){
	if(state != 'x'){
		setup_destination(dest);
		state = 'm';
		cout << "Moving " << display_code << get_id() << " to " << dest << "." << endl;
		cout << display_code << get_id() << ": On my way." << endl;		
	}
	else{
		cout << "Person " << get_id() << " is dead and cannot perform an action." << endl;
	}
}

void Person::stop(){
	state = 's';
	cout << "Stopping " << get_id() << "." << endl;
	cout << display_code << get_id() << ": All right." << endl;
}

void Person::show_status(){
	if(is_alive())
		cout << " moving at speed of " << speed << " towards " << destination << " at each step of " << delta << " with health of " << health;
	else
		cout << " is dead." << endl;
}

bool Person::update_location(){
	if(fabs(destination.x - location.x) <= fabs(delta.x) && fabs(destination.y - location.y) <= fabs(delta.y)){
		location = destination;
		cout << display_code << get_id() << ": I'm there!" << endl;
		return true;
	}
	else{
		location = location + delta;
		cout << display_code << get_id() << ": step..." << endl;
		return false;
	}
}

void Person::setup_destination(Cart_Point dest){
	destination = dest;
	Cart_Vector v1;
	if (cart_distance(dest,location) == 0)
		delta = v1;
	else
		delta = (dest - location) * (speed / cart_distance(dest, location));
}

void Person::start_mining(Gold_Mine* inputMine, Town_Hall* inputHome){
	if(state == 'x'){
		cout << "Person " << get_id() << " is dead and cannot perform an action." << endl;
	}
	else{
		cout << display_code << get_id() << ": Sorry, I can't work a mine." << endl;
	}
}

void Person::start_attack(Person* target){
	if(state == 'x'){
		cout << "Person " << get_id() << " is dead and cannot perform an action." << endl;
	}
	else{
		cout << display_code << get_id() << ": I can't attack." << endl;
	}
}

bool Person::is_alive(){
	if(state == 'x')
		return false;
	else
		return true;
}

void Person::take_hit(int attack_strength){
	cout << display_code << get_id() << ": ";
	if(health > attack_strength){
		health -= attack_strength;
		cout << "Ouch! I've been hit!" << endl;
	}
	else{
		health = 0;
		cout << "Arrggh! I'm dying!" << endl;
		state = 'x';
	}

}

int Person::get_health(){
	return health;
}

Person::~Person(){
	cout << "Person " << get_id() << " destructed." << endl;
}