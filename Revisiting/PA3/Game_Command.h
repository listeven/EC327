#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H

#include "Model.h"
#include "Input_Handling.h"
#include "View.h"
#include <string>
#include <algorithm>

void do_move_command(Model* mod, int id, double x, double y);

void do_work_command(Model* mod, int id1, int id2, int id3);

void do_stop_command(Model* mod, int id);

void do_go_command(Model* mod, View &myView);

void do_run_command(Model* mod, View &myView);

void do_new_command(Model* mod, View &myView, char type, int id, double x, double y);

void do_attack_command(Model* mod, View &myView, int id1, int id2);

void do_quit_command(Model* mod);

bool checkForMoreInputs(istream& inpStream);


#endif