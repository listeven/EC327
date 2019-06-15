#include <iostream>
#include "Miner.h"
#include "Town_Hall.h"
#include "Gold_Mine.h"

using namespace std;

void showAndUpdate(Miner *m1){
	m1->update();
	m1->show_status();
}

int main(){

	Gold_Mine gMine_1 = Gold_Mine(0, Cart_Point(4,10));
	Gold_Mine gMine_2 = Gold_Mine(1, Cart_Point(5,30));
	Town_Hall tHall_1 = Town_Hall(1, Cart_Point(0,0));
	Miner miner_1 = Miner(0, Cart_Point(6,9));

	gMine_1.show_status();
	gMine_2.show_status();
	tHall_1.show_status();
	miner_1.show_status();

	miner_1.start_mining(&gMine_1, &tHall_1);
	miner_1.show_status();

	for (int i = 0; i < 15; ++i)
	{
		showAndUpdate(&miner_1);
		gMine_1.show_status();
		tHall_1.show_status();
		showAndUpdate(&miner_1);
		gMine_1.show_status();
		tHall_1.show_status();
	}

	
	return 0;
}
