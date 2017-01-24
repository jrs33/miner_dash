#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "math.h"

#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"
#include "math.h"

using namespace std;
class Model; // Forward declaration

class Person : public Game_Object
{

	public:
	
		// Constructor prototypes and Destructor
		Person(); 
		Person(char);
		Person(char,int,Cart_Point);
		virtual ~Person();

		// Public member function prototypes
		void start_moving(Cart_Point);
		void stop();
		void show_status();
    
        // Used for Miners only
		virtual void start_mining(Gold_Mine*, Town_Hall*);

		bool is_alive();
		void take_hit(int);
    
        // Used for Soldiers only
		virtual void start_attack(Person*);
    
        // Used for the Inspectors only
        virtual void start_inspecting(Model*);
    
    
	protected:

		bool update_location();
		void setup_destination(Cart_Point);

	private:

		double speed;
		Cart_Point destination;
		Cart_Vector delta;
		
		int health;
};

#endif
