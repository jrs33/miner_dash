#include "Gold_Mine.h"

using namespace std;

// Constructor definitions
Gold_Mine::Gold_Mine():Game_Object('G', 0)
{

	// Default set values
	//this->display_code = 'G';
	this->state = 'f';
	this->amount = 100;

	// Default values from default constructor
	//this->id_num = 0;
	//Cart_Point p1; // Default constructor for Cart_Point invoked to create object p1
	//this->location = p1;

	// Signifying default constructor use
	cout<<"Gold_Mine default constructed"<<endl;

}

Gold_Mine::Gold_Mine(int inputId, Cart_Point inputLoc):Game_Object('G', inputId, inputLoc)
{
	// Default set values
	//this->display_code = 'G';
	this->state = 'f';
	this->amount = 100;

	// Values set from non-default constructor input
	//this->id_num = inputId;
	//this->location = inputLoc;

	cout<<"Gold_Mine constructed"<<endl;

}

Gold_Mine::~Gold_Mine()
{

	cout << "Gold_Mine destructed" << endl;

}

// Defining member functions

// This function checks whether the gold mine is empty or not
bool Gold_Mine::is_empty()
{

	// Checks to see if the amount of gold is zero or not to inform the user
	if(this->amount == 0)
	{
		return true;		
	}	
	else if(this->amount > 0)
	{
		return false; // the amount is greater than 0, so it is not empty and returns false 
	}
	else
	{
		// Handles error case
		cout<<"ERROR: AMOUNT OF GOLD LESS THAN 0!"<<endl;		
		return false;
	}
}

double Gold_Mine::dig_gold(double amount_to_dig) // Set with a DEFAULT value
{

	if(this->amount >= amount_to_dig) // Handles case where we are digging LESS gold than available
	{
		this->amount -= amount_to_dig; // Decrement amount by amount dug
		return amount_to_dig;
		//this->update();
	}
	else // Dug more gold than available, so we now have an empty mine
	{
		amount_to_dig = this->amount; // Stores temp variable to later inform user about amount of gold before the mine is empty
		this->amount = 0; // Sets amount to zero since the mine is empty
		//this->update();
		return amount_to_dig;
			
	}

}

// This function checks if the gold mine is depleted and changes states accordingly
bool Gold_Mine::update()
{
	
	if(this->amount == 0 && this->state != 'e') // Marks the mine state as 'e'='empty' 
	{
		this->state = 'e';
		this->display_code = 'g';
		cout<<"Gold Mine "<<get_id()<<" has been depleted"<<endl;
        //show_status();
		return true;
	}
	else // The mine is not depleted
	{
        //show_status();
		return false;
	}
	
}

// This function outputs in proper formatting the current status and metrics of the mine
void Gold_Mine::show_status()
{
	cout<<"Gold Mine status: ";
	cout<<display_code<<get_id()<<" at location "<<get_location();
	cout<<" Contains "<<this->amount<<"."<<endl;

}

// This function is a simple getter function to be used by the Inspector object
double Gold_Mine::get_gold_amount()
{
    
    return amount;
    
}







