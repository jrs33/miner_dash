#include "Person.h"

using namespace std;

// Constructor definitions (ASK IF WE PUT HEALTH IN THE CONSTRUCTORS
Person::Person():Game_Object('G', 0) { this->health = 5;}

Person::Person(char in_code):Game_Object(in_code, 0) 
{

	this->speed = 5;
	this->health = 5;
	cout<<"Person default constructed."<<endl;

}

Person::Person(char in_code, int in_id, Cart_Point in_loc):Game_Object(in_code, in_id, in_loc)
{

	this->speed = 5;
	this->health = 5;
	cout<<"Person constructed."<<endl;

}

Person::~Person()
{

	cout << "Person destructed." << endl;

}

// Public member function definition
void Person::start_moving(Cart_Point dest)
{
	
	if(state == 'x')
	{
		cout<<"I cant move Im dead."<<endl;
		return;
	}

	if((this->get_location().x == dest.x) && (this->get_location().y == dest.y))
	{
		// Handles edge case where the objects current location is entered; avoids segfaults
		this->state = 's';
		cout<<"Moving "<<get_id()<<" to "<<dest<<endl;
		cout<<display_code<<get_id()<<": I'm already there. see?"<<endl;

	}
	else
	{
		// Establishes the step size
		setup_destination(dest);
		// Set state to MOVING
		this->state = 'm';
	
		// Sets object in motion and informs the user of the update
		cout<<"Moving "<<get_id()<<" to "<<dest<<endl;
		cout<<display_code<<get_id()<<": On my way."<<endl;
	
	}
}

void Person::stop()
{

	// Set state to STOP
	this->state = 's';
	cout<<display_code<<get_id()<<": Stopped."<<endl;

}

void Person::show_status()
{
	if(this->state == 's')
	{
        	Game_Object::show_status();
		cout<<" is stopped. Health is "<<this->health<<endl;
	}	
	else if(this->state == 'm')
	{
		Game_Object::show_status();
		cout<<" moving at speed of "<<this->speed<<" towards ";
		cout<<this->destination;
		cout<<" at each step of ";
		cout<<this->delta;
		cout<<". Health is "<<this->health<<endl;
	}
	else if(this->state == 'o')
	{
		Game_Object::show_status();
		cout<<" moving at speed of "<<this->speed<<" towards ";
		cout<<this->destination;
		cout<<" at each step of ";
		cout<<this->delta;
		cout<<" is outbound to a mine. Health is "<<this->health<<endl;
	}
	else if(this->state == 'g')
	{
        	cout<<"Miner status: "<<"Health is "<<this->health<<" ";
		Game_Object::show_status();
		cout<<" moving at speed of "<<this->speed<<" towards ";
		cout<<this->destination;
		cout<<" at each step of ";
		cout<<this->delta;
		cout<<" is getting gold from mine. Health is "<<this->health<<endl;
	}
	else if(this->state == 'i')
	{
		Game_Object::show_status();
        cout<<"Health is "<<this->health;
		cout<<" moving at speed of "<<this->speed<<" towards ";
		cout<<this->destination;
		cout<<" at each step of ";
		cout<<this->delta;
		cout<<" is inbound to home with load: ";
    }
	else if(this->state == 'd')
	{
		Game_Object::show_status();
		cout<<" moving at speed of "<<this->speed<<" towards ";
		cout<<this->destination;
		cout<<" at each step of ";
		cout<<this->delta;
		cout<<" is depositing gold. Health is "<<this->health<<endl;
	}
	else if(this->state == 'x')
	{
		Game_Object::show_status();
		cout<<" is dead. Health is "<<this->health<<endl;
	}
	else if(this->state == 'a')
	{
		Game_Object::show_status();
	}
	else
	{
		cout<<"NO STATE MATCH"<<endl;
	}
}


// Protected function definitions

bool Person::update_location() ////ALL PROBLEMS WITH MOVEMENT START WITH THE TOP CONDITION
{
	//Checks if it is one step away by seeing if the x and y values would surpass or equal the location on the next step
   	if((fabs(this->destination.x - this->location.x) <= fabs(this->delta.x))&&(fabs(this->destination.y - this->location.y) <= fabs(this->delta.y)))
	{
		this->location = this->destination;
		cout<<display_code<<get_id()<<": Im there!"<<endl;
		return true;
	}
	else //It hasn't arrived, so we must continue moving
	{	
		this->location = this->location + this->delta;
		cout<<display_code<<get_id()<<": step..."<<endl;

		return false;
	}
	
}

void Person::setup_destination(Cart_Point dest)
{

/* Using Cart_Point and Game_Object derived members as well as Cart_Vector to store the final calculated value */
	
	// Sets the objects destination to the dest input
	this->destination = dest;

	// This function calculates the delta value to characterize the objects motion
	this->delta = (this->destination - this->location) * (this->speed/cart_distance(this->destination,this->location)); 

}

void Person::start_mining(Gold_Mine* g1, Town_Hall* t1)
{

	if(state == 'x')
	{
		cout<<"I cant mine Im dead."<<endl;
		return;
	}

	cout << "I can't work." << endl;

}



bool Person::is_alive()
{

	if(this->state != 'x')
	{

		return true;

	}

	else
	{

		return false;

	}

}

void Person::take_hit(int attack_strength)
{

	health -= attack_strength;
	
	if(health <= 0) // The object is then dead, and we must change it accordingly
	{

		cout<<"Arrggh!"<<endl;
		this->state = 'x';
	
	}

	else
	{

		cout<<"Ouch!"<<endl;

	}

}

void Person::start_attack(Person* target)
{
	
	if(state == 'x')
	{
		cout<<"I cant attack Im dead."<<endl;
		return;
	}

	cout<<"I can't attack."<<endl;

}

void Person::start_inspecting(Model* model)
{
    
    cout << "Sorry, I can't inspect" << endl;
    
}




