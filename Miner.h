#ifndef MINER_H
#define MINER_H

#include <iostream>
#include "Person.h"
#include "Town_Hall.h"
#include "Gold_Mine.h"

using namespace std;

class Miner:public Person
{

	public:

		// Constructors and Destructor
		Miner();
		Miner(int, Cart_Point);
		~Miner();
		
		// Member Function prototypes
		bool update();
		void start_mining(Gold_Mine*, Town_Hall*);
        Cart_Point get_location();
		void show_status();

	private:

		// Defining private member variables
		double amount;
		Gold_Mine* mine;
		Town_Hall* home;

};

#endif
