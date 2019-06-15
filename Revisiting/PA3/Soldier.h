#ifndef SOLDIER_H
#define SOLDIER_H

#include "Person.h"
#include "Miner.h"

using namespace std;

class Soldier:public Person{
private:
	int attack_strength;
	double range;
	Person* target;
public:
	Soldier();
	Soldier(int in_id, Cart_Point in_loc);
	~Soldier();
	void start_attack(Person* in_target);
	bool update();
	void show_status();
};


#endif
