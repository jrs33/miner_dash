#ifndef GOLD_MINE_H
#define GOLD_MINE_H

#include <iostream>
#include "Cart_Point.h"
#include "Game_Object.h"

using namespace std;

class Gold_Mine:public Game_Object
{
// Inherits from Game_Object
	public:
		// Constructors and Destructor
		Gold_Mine(); //Default constructor
		Gold_Mine(int, Cart_Point);
		~Gold_Mine();

		// Public member functions
		bool is_empty();
		double dig_gold(double amount_to_dig = 35.0); // Setting default value
		bool update();
		void show_status();
    
        // The following added for Inspector functionality
        double get_gold_amount();
    

	private:
		// Defining private member variables
		double amount;

};

#endif
