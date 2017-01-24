#ifndef TOWN_HALL_H
#define TOWN_HALL_H

#include <iostream>
#include "Game_Object.h"

using namespace std;

class Town_Hall: public Game_Object 
{ 
// Inherits from Game_Object

	public:
		// Constructors and Destructor
		Town_Hall(); // Default constructor
		Town_Hall(int, Cart_Point);
		~Town_Hall();

		// Public member functions
		//Cart_Point get_location();
		//int get_id();
		void deposit_gold(double);
		bool update();
		void show_status();


	private:
		// Defining private member variables
		//char display_code;	
		//int id_num;
		//char state;
		double amount;
		//Cart_Point location;

};

#endif	
