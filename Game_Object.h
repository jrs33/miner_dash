#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <iostream>
#include <stdio.h>
#include "Cart_Point.h"
#include "Cart_Vector.h"

using namespace std;

// Game_Object class is used as the base class for all the objects in the game
class Game_Object
{
	public: 
		// Constructors
		Game_Object(char,int); 
		Game_Object(char,int,Cart_Point); // Passing object instance by reference for efficiency
		virtual ~Game_Object();

		// Return location for the object		
		Cart_Point get_location();

		// Return num_id
		int get_id();
		virtual void show_status();
		virtual bool update() = 0;
    
        // The following will be used to draw the objects in View
        void drawself(char*);
		
		// The following will determine at runtime which object to apply the is_alive() boolean functionality to 
		virtual bool is_alive();
		
	// Defining the protected and private member variables
	protected:
		Cart_Point location;
		char display_code;
		char state;
	
	private:
		int id_num;

};

#endif
