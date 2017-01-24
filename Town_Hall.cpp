#include "Town_Hall.h"

using namespace std;


// Constructor definitions
Town_Hall::Town_Hall():Game_Object('t', 1) // Default constructor
{

	//this->display_code = 't';
	//this->id_num = 0;
	this->state = 'o';
	this->amount = 0;

	// Default constructing Cart_Point object p and storing it in location
	//Cart_Point p;
	//this->location = p;

	cout<<"Town_Hall constructed."<<endl;

}

Town_Hall::Town_Hall(int inputId, Cart_Point inputLoc):Game_Object('t', inputId, inputLoc)
{

	// All set to regular default value except for id_num and location
	//this->display_code = 't';
	//this->id_num = inputId;
	this->state = 'o';
	this->amount = 0;
	//this->location = inputLoc;

	cout<<"Town_Hall constructed."<<endl;
	
}

Town_Hall::~Town_Hall() 
{

	cout << "Town_Hall destructed." << endl;

}

// This getter returns the private variable location
/*Cart_Point Town_Hall::get_location() 
{

	return this->location;

}

// This getter returns the private variable id_num
int Town_Hall::get_id()
{

	return id_num; //PUT THE THIS-> BACK IN

}*/

// This function deposits a double value of gold and stores it into amount
void Town_Hall::deposit_gold(double deposit_amount)
{

	this->amount += deposit_amount;

}

// This function checks to see if the town hall needs to be upgraded and changes state accordingly
bool Town_Hall::update()
{

	if(this->amount >= 50 && this->state != 'u') // Marks the town hall as 'u'='upgraded'
	{
		this->state = 'u';
		this->display_code = 'T';
		cout<<"T"<<get_id()<<" has been upgraded"<<endl;
        //show_status();
		return true;
	}
	else
	{
		return false;
	}

}

// This function outputs the current metrics of the Town Hall
void Town_Hall::show_status()
{
	cout<<"Town Hall Status: ";
	Game_Object::show_status();
	cout<<" contains "<<this->amount<<" of gold";
	if(this->state == 'u')
	{		
		cout<<". Upgraded."<<endl;
	}	
	else
	{	
		cout<<". Not yet upgraded."<<endl;
	}

}










