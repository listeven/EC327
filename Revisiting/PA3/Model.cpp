#include "Model.h"
#include <list>
#include <iostream>

using namespace std;

Model::Model(){
	time = 0;

	Miner* miner1 = new Miner(1, Cart_Point(5,1));
	Miner* miner2 = new Miner(2, Cart_Point(10,1));
	Gold_Mine* gMine1 = new Gold_Mine(1, Cart_Point(1,20));
	Gold_Mine* gMine2 = new Gold_Mine(2, Cart_Point(10,20));
	Town_Hall* tHall = new Town_Hall();

	Soldier* soldier1 = new Soldier(3, Cart_Point(5,15));
	Soldier* soldier2 = new Soldier(4, Cart_Point(10,15));

	Soldier* soldier3 = new Soldier(5, Cart_Point(5, 5));

	object_ptrs.push_back(miner1);
	active_ptrs.push_back(miner1);
	person_ptrs.push_back(miner1);
	object_ptrs.push_back(miner2);
	active_ptrs.push_back(miner2);
	person_ptrs.push_back(miner2);

	object_ptrs.push_back(gMine1);
	active_ptrs.push_back(gMine1);
	mine_ptrs.push_back(gMine1);
	object_ptrs.push_back(gMine2);
	active_ptrs.push_back(gMine2);
	mine_ptrs.push_back(gMine2);

	object_ptrs.push_back(tHall);
	active_ptrs.push_back(tHall);
	hall_ptrs.push_back(tHall);

	object_ptrs.push_back(soldier1);
	active_ptrs.push_back(soldier1);
	person_ptrs.push_back(soldier1);
	object_ptrs.push_back(soldier2);
	active_ptrs.push_back(soldier2);
	person_ptrs.push_back(soldier2);
	object_ptrs.push_back(soldier3);
	active_ptrs.push_back(soldier3);
	person_ptrs.push_back(soldier3);


	cout << "Model default constructed" << endl;
	cout << "Object Ptrs Size: " << object_ptrs.size() << endl;
	cout << "Person Ptrs Size: " << person_ptrs.size() << endl;
	cout << "Hall Ptrs Size: " << hall_ptrs.size() << endl;
}

Model::~Model(){
	for(list<Game_Object*>::iterator i = object_ptrs.begin(); i != object_ptrs.end(); ++i){
		delete *i;
	}

	cout << "Model destructed." << endl;
}

Person* Model::get_Person_ptr(int id){
	if(person_ptrs.size() > 0){
		for(list<Person*>::iterator i = person_ptrs.begin(); i != person_ptrs.end(); ++i){
			if((*i)->get_id() == id){
				return *i;
			}
		}
	}
	throw Invalid_Input("No such Person exists. Use a different Person ID.");
}

Gold_Mine* Model::get_Gold_Mine_ptr(int id){
	if(mine_ptrs.size() > 0){
		for(list<Gold_Mine*>::iterator i = mine_ptrs.begin(); i != mine_ptrs.end(); ++i){
			if((*i)->get_id() == id){
				return *i;
			}
		}
	}
	throw Invalid_Input("No such Gold Mine exists. Use a different Gold Mine ID.");

}


Town_Hall* Model::get_Town_Hall_ptr(int id){
	if(hall_ptrs.size() > 0){
		for(list<Town_Hall*>::iterator i = hall_ptrs.begin(); i != hall_ptrs.end(); ++i){
			if((*i)->get_id() == id){
				return *i;
			}
		}
	}
	throw Invalid_Input("No such Town Hall exists. Use a different Town Hall ID.");

}


bool Model::update(){
	time++;
	bool tempOutput = false;
	for(list<Game_Object*>::iterator i = active_ptrs.begin(); i != active_ptrs.end(); ++i){
		if((*i)->update())
			tempOutput = true;
	}

	for(list<Game_Object*>::iterator j = active_ptrs.begin(); j != active_ptrs.end(); ++j){
		if(!((*j)->is_alive())){
			j = active_ptrs.erase(j);
			--j;
		}
	}

	cout << "List after removing dead elements: ";
	for(list<Game_Object*>::iterator k = active_ptrs.begin(); k != active_ptrs.end(); ++k){
		cout << (*k)->get_code() << (*k)->get_id() << " ";
	}
	cout << endl;
	return tempOutput;
}

void Model::display(View &view){
	view.clear();
	for(list<Game_Object*>::iterator i = active_ptrs.begin(); i != active_ptrs.end(); ++i){
		view.plot(*i);
	}
	view.draw();
}

void Model::show_status(){
	cout << "Time: " << time << endl;
	list<Person*>::iterator personIt = person_ptrs.begin();
	list<Gold_Mine*>::iterator mineIt = mine_ptrs.begin();
	list<Town_Hall*>::iterator thallIt = hall_ptrs.begin();

	for(personIt; personIt != person_ptrs.end(); ++personIt){
		(*personIt)->show_status();
	}

	for(mineIt; mineIt != mine_ptrs.end(); ++mineIt){
		(*mineIt)->show_status();
	}

	for(thallIt; thallIt != hall_ptrs.end(); ++thallIt){
		(*thallIt)->show_status();
	}

}

void Model::handle_new_command(char type, int id, double x, double y){
	switch(type){
		case 'g': 
		{
			if(mine_ptrs.size() > 0){
				for(list<Gold_Mine*>::iterator i = mine_ptrs.begin(); i != mine_ptrs.end(); ++i){
					if((*i)->get_id() == id){
						throw Invalid_Input("A Gold Mine with that ID already exists.");
					}
				}
			}
			Gold_Mine* addedMine = new Gold_Mine(id, Cart_Point(x,y));
			object_ptrs.push_back(addedMine);
			active_ptrs.push_back(addedMine);
			mine_ptrs.push_back(addedMine);
			break;
		}

		case 't':
		{
			if(hall_ptrs.size() > 0){
				for(list<Town_Hall*>::iterator i = hall_ptrs.begin(); i != hall_ptrs.end(); ++i){
					if((*i)->get_id() == id){
						throw Invalid_Input("A Town Hall with that ID already exists.");
					}
				}
			}
			Town_Hall* addedHall = new Town_Hall(id, Cart_Point(x,y));
			object_ptrs.push_back(addedHall);
			active_ptrs.push_back(addedHall);
			hall_ptrs.push_back(addedHall);
			break;
		}

		case 'm':
		{
			if(person_ptrs.size() > 0){
				for(list<Person*>::iterator i = person_ptrs.begin(); i != person_ptrs.end(); ++i){
					if((*i)->get_id() == id){
						throw Invalid_Input("A Person with that ID already exists.");
					}
				}
			}
			Miner* addedMiner = new Miner(id, Cart_Point(x,y));
			object_ptrs.push_back(addedMiner);
			active_ptrs.push_back(addedMiner);
			person_ptrs.push_back(addedMiner);
			break;
		}

		case 's':
		{
			if(person_ptrs.size() > 0){
				for(list<Person*>::iterator i = person_ptrs.begin(); i != person_ptrs.end(); ++i){
					if((*i)->get_id() == id){
						throw Invalid_Input("A Person with that ID already exists.");
					}
				}
			}
			Soldier* addedSoldier = new Soldier(id, Cart_Point(x,y));
			object_ptrs.push_back(addedSoldier);
			active_ptrs.push_back(addedSoldier);
			person_ptrs.push_back(addedSoldier);
			break;
		}

		default:
			throw Invalid_Input("Invalid Type entered.");

	}	
}