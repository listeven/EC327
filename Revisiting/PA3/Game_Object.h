#ifndef	GAME_OBJECT_H
#define	GAME_OBJECT_H

#include "Cart_Point.h"
#include "Input_Handling.h"

using namespace std;

class Game_Object{
public:
	Game_Object(char in_code, int in_id);
	Game_Object(char in_code, int in_id, Cart_Point in_loc);
	virtual ~Game_Object();
	void drawself(char* ptr);
	virtual bool update() = 0;
	virtual void show_status();
	virtual bool is_alive();
	int get_id();
	char get_code();
	Cart_Point get_location();
protected:
	Cart_Point location;
	char display_code;
	char state;
private: 
	int id_num;
};

#endif