#include "Miner.h"

using namespace std;

// Defining constructers
Miner::Miner():Person('M')
{
	// Setting mine and town hall pointers to NULL since they are not instantiated yet
	this->state = 's';
	this->amount = 0;
	this->mine = NULL;
	this->home = NULL;

	// Printing out affirmation message
	cout<<"Miner default constructed."<<endl; 

}

Miner::Miner(int in_id, Cart_Point in_loc):Person('M', in_id, in_loc)
{

	// Same as above, but gives the mine and home pointers a value
	this->state = 's'; 
	this->amount = 0;
	this->mine = 0;
	this->home = 0;

	cout<<"Miner constructed."<<endl;

}

Miner::~Miner()
{

	cout << "Miner destructed." << endl;

}

// Public member function definitions
bool Miner::update()
{
	
	// Returns true when the state is changed and false otherwise
	switch(this->state)
	{
		
		case 's': //Stopped

			return false;

		case 'm': //Moving to a destination
			
            if(update_location())
			{
				this->state = 's';
				return true;			
			}
			else	
			{

				return false; // Stay in the moving state

			}

		case 'o': //Outbound mining
			
			if(update_location()) // If we have arrived, we set the state to getting gold
			{
				this->state = 'g';
				return true;
			}
			else
			{
				//show_status();
				return false;
			}

		case 'g': //Getting gold
            
			// Digging gold from the mine and returning information
			amount = mine->dig_gold();
			cout<<this->display_code<<get_id()<<": Got "<< this->amount <<" gold."<<endl;
			
			// Setting destination to the home base (ie: town hall)			
			setup_destination(home->get_location());
			this->state = 'i';

			return true;

		case 'i': //Inbound mining

			if(this->update_location())
			{
				this->state = 'd';
				return true;
			}
			else
			{
                return false;
			}

		case 'd': //Depositing gold

			cout<<this->display_code<<get_id()<<": Deposit "<<this->amount<<" of gold."<<endl;
			home->deposit_gold(this->amount);
			this->amount = 0;
			
			if(mine->is_empty())
			{
				this->state = 's';
				cout<<this->display_code<<get_id()<<": More work?"<<endl;
				return true;			
			}
			else
			{
				Person::setup_destination(mine->get_location());
				this->state = 'o';
				cout<<this->display_code<<get_id()<<": Going back for more."<<endl;
				return true;
			}
		
		case 'x': //Dead; do nothing ever again RIP

			return false;

        	default:
            		cout<<"Problem encountered...state not assigned properly"<<endl;
           	 	return false;
	}

}

void Miner::show_status()
{
	cout<<"Miner status: ";
	Person::show_status();
	if(this->state == 'i')
	{
		
		cout<<" "<<this->amount<<endl;

	}

}

void Miner::start_mining(Gold_Mine* inputMine, Town_Hall* inputHome)
{

	if(state == 'x')
	{
		cout<<"I cant mine Im dead."<<endl;
		return;
	}

	// Sets up the Gold_Mine and Town_Hall member variables to match the input
	this->mine = inputMine;
	this->home = inputHome;
        setup_destination(mine->get_location());
        this->state = 'o';
    
    cout<<"Miner "<<this->get_id()<<" mining at Gold_Mine "<<mine->get_id()<<" and depositing at Town_Hall "<<home->get_id()<<"."<<endl;
    cout<<this->display_code<<this->get_id()<<": Yes, my lord."<<endl;
  
}

Cart_Point Miner::get_location()
{
    
    cout<<"Miner status: ";
    Person::show_status();
    return Game_Object::get_location();
    
}







