#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <list>
#include <vector>

#include "Miner.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "Soldier.h"
#include "Inspector.h"
#include "View.h"
#include "Input_Handling.h"

using namespace std;


class Model {


	public:
		// Defining constructors
		Model();

		// Defining destructor
		~Model();

		// Member functions
		Person* get_Person_ptr(int id);
		Gold_Mine* get_Gold_Mine_ptr(int id);
		Town_Hall* get_Town_Hall_ptr(int id);
		bool update();
		void display(View* view);
		void show_status();

		void handle_new_command(char,int,int,int);
    
        // Getter function to be used by the Inspector class to trace path
        list<Gold_Mine*> get_Gold_Mine_list();

	private:
		int time; // Stores the simulated time

		// Pointer lists
		list<Game_Object*> object_ptrs;
		list<Game_Object*> active_ptrs; // Only stores live objects
		
		list<Gold_Mine*> mine_ptrs;
		list<Town_Hall*> hall_ptrs;
        list<Person*> person_ptrs;

};

#endif
