#ifndef GAME_COMMAND_H
#define GAME_COMMAND_H

#include <iostream>

#include "Model.h"

using namespace std;

// This .h provides functions to control the MVC pattern via user input; function prototypes below

void do_move_command(Model*,int,int,int); // TOOK OUT PASSING VIEW BY REFERENCE
void do_go_command(Model*);
void do_run_command(Model*);
void do_stop_command(Model*,int);
void do_list_command(Model*);
void do_work_command(Model*,int,int,int);
void do_quit_command(Model*);

void do_attack_command(Model*,int,int);

void do_new_command(Model*, char, int , int , int );

void do_inspect_command(Model*, int);

#endif
