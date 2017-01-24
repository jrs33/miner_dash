#include "Game_Object.h"

using namespace std;

// Defining constructors
Game_Object::Game_Object(char in_code, int in_id)
{
	
	// Initializing member variables to input
	display_code = in_code;
	this->id_num = in_id; // Access hidden data field using the this pointer '(*this).id_num'

	// Initializing a cart point object to (0,0) and setting location
	Cart_Point p;
	location = p; // Location is stored within the cart object, which we will access via location

	cout<<"Game_Object constructed."<<endl;

}

Game_Object::Game_Object(char in_code, int in_id, Cart_Point in_loc)
{
	
	// Initializing member variables to input
	display_code = in_code;
	this->id_num = in_id;

	// Initialize Cart_Point
	location = in_loc; // Sets the inputted Cart_Point object to be stored in the location member variable

	cout<<"Game_Object constructed."<<endl;
}

Game_Object::~Game_Object()
{

	cout << "Game_Object destructed." << endl;

}

// Defining member functions
Cart_Point Game_Object::get_location()
{

	// Returning the location of the Cart_Point object stored in the location member variable
	return location;

}
int Game_Object::get_id() 
{

	// Getter member function for the private id_num variable;
	return id_num;

}

void Game_Object::show_status()
{

	cout<<display_code<<get_id()<<" at "<<get_location();	

}

// The following function is utilized for the ASCII View display
void Game_Object::drawself(char* ptr)
{
	if(ptr[0] == '.' && ptr[1]==' ')
	{
		ptr[0] = display_code;
		ptr[1] = (char)(48+id_num);
    }else{
		ptr[0] = '*';
		ptr[1] = ' ';

	}
}

bool Game_Object::is_alive()
{

	// Implemented to create polymorphic finding of inherited objects alive status
	return true;

}


