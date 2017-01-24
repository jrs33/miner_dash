#ifndef SOLDIER_H
#define SOLDIER_H

#include <iostream>
#include "Person.h"

using namespace std;

class Soldier : public Person
{

	public:
		// Constructor
		Soldier(int,Cart_Point);

		// Destructor
		~Soldier();		

		// Public member functions
		void start_attack(Person*);
		bool update();
		void show_status();

	private:
		int attack_strength;
		double range;
		Person* target;

};

#endif
