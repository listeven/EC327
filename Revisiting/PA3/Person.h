#ifndef PERSON_H
#define PERSON_H

#include "Gold_Mine.h"
#include "Town_Hall.h"
using namespace std;

class Person:public Game_Object{
public:
	Person();
	Person(char in_code);
	Person(char in_code, int in_id, Cart_Point in_loc);
	virtual ~Person();
	void start_moving(Cart_Point dest);
	void stop();
	void show_status();
	virtual void start_mining(Gold_Mine* inputMine, Town_Hall* inputHome);
	bool is_alive();
	void take_hit(int attack_strength);
	virtual void start_attack(Person* target);
	int get_health();
protected:
	bool update_location();
	void setup_destination(Cart_Point dest);
private:
	double speed;
	Cart_Point destination;
	Cart_Vector delta;
	int health;
};

#endif