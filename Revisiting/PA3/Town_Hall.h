#ifndef TOWN_HALL_H
#define TOWN_HALL_H

#include "Game_Object.h"
using namespace std;

class Town_Hall:public Game_Object{
public:
	Town_Hall();
	Town_Hall(int inputId, Cart_Point inputLoc);
	~Town_Hall();
	Cart_Point get_location();
	void deposit_gold(double deposit_amount);
	bool update();
	void show_status();
private:
	double amount;
};

#endif