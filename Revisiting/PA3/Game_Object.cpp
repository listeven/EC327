#include "Game_Object.h"
#include <iostream>

using namespace std;

Game_Object::Game_Object(char in_code, int in_id){
	id_num = in_id;
	location = Cart_Point();
	display_code = in_code;
	cout << "Game_Object default constructed" << endl;
}

Game_Object::Game_Object(char in_code, int in_id, Cart_Point in_loc){
	id_num = in_id;
	location = in_loc;
	display_code = in_code;
	cout << "Game_Object constructed" << endl;	
}

Cart_Point Game_Object::get_location(){
	return location;
}

int Game_Object::get_id(){
	return id_num;
}

char Game_Object::get_code(){
	return display_code;
}

void Game_Object::drawself(char* ptr){
	ptr[0] = display_code;
	int a = get_id();
	ptr[1] = '0' + a;	
}

bool Game_Object::update(){
	return true;
}

bool Game_Object::is_alive(){
	return true;
}

void Game_Object::show_status(){
	cout << display_code << " with ID " << id_num << " at location " << location << endl;
}

Game_Object::~Game_Object(){
	cout << "Game Object " << get_id() << " destructed." << endl;
}