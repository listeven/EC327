#ifndef MODEL_H
#define MODEL_H

#include <list>

#include "Input_Handling.h"
#include "Miner.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "View.h"
#include "Soldier.h"

using namespace std;

class Model{
public:
	Model();
	~Model();
	Person* get_Person_ptr(int id);
	Gold_Mine* get_Gold_Mine_ptr(int id);
	Town_Hall* get_Town_Hall_ptr(int id);
	bool update();
	void display(View &view);
	void show_status();
	void handle_new_command(char type, int id, double x, double y);
private:
	int time;

	list<Game_Object*> object_ptrs;
	list<Game_Object*> active_ptrs;
	list<Person*> person_ptrs;
	list<Gold_Mine*> mine_ptrs;
	list<Town_Hall*> hall_ptrs;
};

#endif