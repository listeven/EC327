#include "Game_Command.h"
#include <iostream>

using namespace std;

void do_move_command(Model* mod ,int id, double x, double y){
	Person* pPtr = mod->get_Person_ptr(id);
	Cart_Point p1 = Cart_Point(x,y);
	cout << "Telling " << pPtr->get_code() << id << " to move to " << p1 << endl;
	pPtr->start_moving(p1);
	
}

void do_work_command(Model* mod, int id1, int id2, int id3){
	Person* pPtr = mod->get_Person_ptr(id1);
	Gold_Mine* gPtr = mod->get_Gold_Mine_ptr(id2);
	Town_Hall* tPtr = mod->get_Town_Hall_ptr(id3);
	cout << "Telling " << pPtr->get_code() << id1 << " to start mining at Mine " << id2 << " and depositing gold at Town Hall " << id3 << "." << endl;
	pPtr->start_mining(gPtr, tPtr);
}

void do_stop_command(Model* mod, int id){
	Person* pPtr = mod->get_Person_ptr(id);
	cout << "Telling " << pPtr->get_code() << id << " to stop." << endl;
	pPtr->stop();
}

void do_go_command(Model* mod, View &myView){
	cout << "Advancing one tick." << endl;
	mod->update();
	mod->show_status();
	mod->display(myView);
}


void do_run_command(Model* mod, View &myView){
	cout << "Advancing to next event. " << endl;
	for(int i = 0; i < 5; ++i){
		//cout << "Enter run command. Cycle: " << i << endl;
		if(mod->update()){
			//cout << "Enter if statement clause. Cycle: " << i << endl;
			break;
		}
	}
	mod->show_status();
	mod->display(myView);
}

void do_new_command(Model* mod, View &myView, char type, int id, double x, double y){
	mod->handle_new_command(type, id, x, y);
	mod->display(myView);

}


void do_attack_command(Model* mod, View &myView, int id1, int id2){
	Person* attacker = mod->get_Person_ptr(id1);
	Person* target = mod->get_Person_ptr(id2);
	cout << "Telling " << attacker->get_code() << id1 << " to try attacking " << target->get_code() << id2 << endl;
	attacker->start_attack(target);
	//mod->show_status();
	//mod->display(myView);

}

void do_quit_command(Model* mod){
	cout << "Terminating program." << endl;
	delete mod; 				
}

bool checkForMoreInputs(istream& inpStream){			// Returns true if there are more inputs
	string myString;
	getline(inpStream, myString);
	myString.erase(std::remove_if(myString.begin(), myString.end(), ::isspace), myString.end());
	if(myString.empty()){
		return false;
	}
	else{
		return true;
	}
}