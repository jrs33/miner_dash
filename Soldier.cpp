#include "Soldier.h"

using namespace std;


// Defining a constructor
Soldier::Soldier(int in_id, Cart_Point in_loc):Person('S', in_id, in_loc)
{

	// Setting the private member variables to their default values
	this->attack_strength = 2;
	this->range = 2.0;
	this->state = 's';

}

Soldier::~Soldier()
{

	cout<<"Soldier destructed."<<endl;

}

void Soldier::start_attack(Person* in_target)
{

	if(state == 'x')
	{
		cout<<"I cant attack Im dead."<<endl;
		return;
	}

	// First checks to see whether the distance between the target and soldier is within the range of 2
	double distance = sqrt(pow(in_target->get_location().x - this->get_location().x,2) + pow(in_target->get_location().y - this->get_location().y,2));
	
	if(distance <= range) // If the calculated distance is less than the range of attack
	{

		cout<<"Clang!"<<endl;
		this->state = 'a';	
		this->target = in_target; // Save pointer	

	}
	else // It is too far away
	{

		cout<<"Target is out of range"<<endl;

	}

}

bool Soldier::update()
{
	double distance;

	switch(this->state)
	{

		case 'x': // DEAD
			return false;
			break;
		
		case 's': //Stopped
			return false;
			break;
	
		case 'm': //Moving
			if(update_location())
			{
				this->state = 's';
				return true;			
			}
			else	
			{

				return false; // Stay in the moving state

			}
		break;
		case 'a': //Attacking
			distance = sqrt(pow(target->get_location().x - this->get_location().x,2) + pow(target->get_location().y - this->get_location().y,2));
			if(distance <= range && this->state != 'x') // Checks if the target is within range, and if true, we enter the if statement
			{

				if(target->is_alive()) // Subsequently check if there is a live object to attack, and then attacks the object with a hit
				{

					cout<<"Clang!"<<endl;
					target->take_hit(attack_strength);
					return false; // Stays in the attacking phase

				}
				else // if the targetted object is dead
				{

					cout<<"I triumph!"<<endl;
					this->state = 's'; // Stop the soldier
					return true; // Indicates the state changed
				
				}

			}
			
			this->state = 's'; // Handles the case where the target is out of range, and stops the soldier
			return true;
			break;
		default:
			return false; 
			break;

	}

}

void Soldier::show_status()
{

	cout<<"Soldier status: ";
	Person::show_status();
	if(this->state == 'a')
	{
	
		cout<<"attacking."<<endl;
	
	}
	else
	{

		cout<<"not attacking."<<endl;

	}

}













