#ifndef GOLD_MINE_H
#define GOLD_MINE_H

//#include "Cart_Point.h"
#include "Game_Object.h"
using namespace std;

class Gold_Mine:public Game_Object{
public:
	Gold_Mine();
	Gold_Mine(int inputId, Cart_Point inputLoc);
	~Gold_Mine();
	bool is_empty();
	double dig_gold(double amount_to_dig = 35.0);
	bool update();
	void show_status();
private:
	double amount;
};

#endif