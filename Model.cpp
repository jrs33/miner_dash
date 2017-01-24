#include "Model.h"

using namespace std;

// Defining the constructor and destructor
Model::Model() 
{

	this->time = 0;
	// Creating instances of Game Objects and storing in STL list

	person_ptrs.push_back(new Miner(1, Cart_Point(5,1)));
	person_ptrs.push_back(new Miner(2, Cart_Point(10,1)));

	person_ptrs.push_back(new Soldier(3, Cart_Point(5,15)));
	person_ptrs.push_back(new Soldier(4, Cart_Point(10,15)));
    
    person_ptrs.push_back(new Inspector(5, Cart_Point(5,5)));

	mine_ptrs.push_back(new Gold_Mine(1, Cart_Point(1,20)));
	mine_ptrs.push_back(new Gold_Mine(2, Cart_Point(10,20)));

	hall_ptrs.push_back(new Town_Hall());
	

	for(list<Person*>::iterator it = person_ptrs.begin(); it != person_ptrs.end(); ++it) 
	{
	
		object_ptrs.push_back(*it);
		active_ptrs.push_back(*it);

    }
	for(list<Gold_Mine*>::iterator it = mine_ptrs.begin(); it != mine_ptrs.end(); ++it) 
	{
        
		object_ptrs.push_back(*it);
		active_ptrs.push_back(*it);

	}
	for(list<Town_Hall*>::iterator it = hall_ptrs.begin(); it != hall_ptrs.end(); ++it) 
	{
        
		object_ptrs.push_back(*it);
		active_ptrs.push_back(*it);

	}

 	cout << "Model constructed"<<endl;

}

Model::~Model()
{
    
    cout<<"Terminating program."<<endl;
for(list<Game_Object*>::iterator it = object_ptrs.begin(); it != object_ptrs.end(); ++it)
    {
        delete *it;
    }
    
	cout << "Model destructed." << endl;

}

// Member function definitions

// Pointer return functions check over lists to find the proper id that corresponds to an instance and returns the pointer to that object, or returns a NULL pointer if it could not find the object with an appropriate message
Person* Model::get_Person_ptr(int id)
{	
	
	for(list<Person*>::iterator it = person_ptrs.begin(); it != person_ptrs.end(); it++)
	{	
		int new_id = (*it)->get_id();
		// If the id matches the input id we return a pointer to that object in the index
		if(new_id == id)
		{
			return *it;
		}

	}
	
	cout<<"ERROR: COULD NOT FIND PERSON"<<endl;
	return NULL;	

}

Gold_Mine* Model::get_Gold_Mine_ptr(int id)
{
	
	for(list<Gold_Mine*>::iterator it =mine_ptrs.begin(); it != mine_ptrs.end(); ++it)
	{
		int new_id = (*it)->get_id();
			// If the id matches the input id we return a pointer to that object in the index
			if(new_id == id)
			{
				return *it;
			}
	}
	cout << "Error: Could not find mine" << endl;
	return NULL;		

}

Town_Hall* Model::get_Town_Hall_ptr(int id)
{
	
	for(list<Town_Hall*>::iterator it = hall_ptrs.begin(); it != hall_ptrs.end(); ++it)
	{
		int new_id = (*it)->get_id();
			// If the id matches the input id we return a pointer to that object in the index
			if(new_id == id)
			{
				return *it;
			}
	}

	cout << "Error: Could not find hall" << endl;
	return NULL;

}

bool Model::update() 
{

	bool output = false;

	// Increment the time
	time += 1;	

	// First iterates through the active pointer list and updates each object
	for(list<Game_Object*>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); ++it)
	{
		// Updating each object in the object array
		if((*it)->update())
		{
			// Set the output to true if any objects update call returns true
			output = true;
		}
	}

	// It next iterates again and removes objects who are dead (ie: state of 'x')
	for(list<Game_Object*>::iterator it =active_ptrs.begin(); it != active_ptrs.end();)
	{
		if(!(*it)->is_alive())
		{
            // If the object does not have live status, we must remove it from the list
            it = active_ptrs.erase(it); // erase then returns an iterator to the next element in the list to avoid segfaults (valgrind: the 'impossible' has happened)
			cout<<"Dead object removed"<<endl;		

		}
        else
        {
            // If the object is alive, continue to iterate through the list
            ++it;
            
        }

	}

	return output;

}

void Model::display(View* view)
{
    
    // First clear the output
    view->clear();

    // Then add the object locations to the 3D grid using plot

 	for(list<Game_Object*>::iterator it = active_ptrs.begin(); it != active_ptrs.end(); ++it)
	{
		// Set the output to true if any objects update call returns true
		view->plot(*it);

	}

    // Finally, output the graphical depiction of the 3D grid array
    view->draw();

}

void Model::show_status()
{

	cout<<"Time: "<<this->time<<endl;	

	for(list<Game_Object*>::iterator it = object_ptrs.begin(); it != object_ptrs.end(); ++it)
	{
		(*it)->show_status();
	}
}


void Model::handle_new_command(char objectType, int ID, int x, int y)
{
    // Perform preliminary checks to be sure that the ID, x and y are correct types and that the ID, if it is an integer, is not greater than 9 to avoid double digit problems that may arise with the current grid structure
    if(!ID || !x || !y)
    {
        throw Invalid_Input("Please enter a valid input");
    }
    else if(ID > 9)
    {
        throw Invalid_Input("ID must be less than 10");
    }

	switch(objectType)
		{
		case 'g': // Gold Mine
            // Check that the current ID entered doesnt conflict with another current Gold Mines ID BEFORE adding into the mine_ptrs list; same with location
            for(list<Gold_Mine*>::iterator it = mine_ptrs.begin(); it != mine_ptrs.end(); ++it)
            {
            
                if((*it)->get_id() == ID)
                {
                    throw Invalid_Input("ID already in use in another Gold Mine");
                }
                
                if(((*it)->get_location().x == x) && ((*it)->get_location().y == y))
                {
                    throw Invalid_Input("Same location as another existing Gold Mine");
                }
                
            }
			mine_ptrs.push_back(new Gold_Mine(ID, Cart_Point(x,y)));
			for(list<Gold_Mine*>::iterator it = mine_ptrs.begin(); it != mine_ptrs.end(); ++it) {
				if((*it)->get_id() == ID) {
					object_ptrs.push_back((*it));
					active_ptrs.push_back((*it));
				}
			}
			cout<<"GOLD MINE CREATED"<<endl;
			break;				
			
		case 't': // Town Hall
            // Check that the current ID entered doesnt conflict with another current Town Halls ID; same for location
            for(list<Town_Hall*>::iterator it = hall_ptrs.begin(); it != hall_ptrs.end(); ++it)
            {
                    
                if((*it)->get_id() == ID)
                {
                    throw Invalid_Input("ID already in use in another Town Hall");
                }
                
                if(((*it)->get_location().x == x) && ((*it)->get_location().y == y))
                {
                    throw Invalid_Input("Same location as another existing Town Hall");
                }
                    
            }
			hall_ptrs.push_back(new Town_Hall(ID, Cart_Point(x,y)));
            for(list<Town_Hall*>::iterator it = hall_ptrs.begin(); it != hall_ptrs.end(); ++it)
            {
                    if((*it)->get_id() == ID)
                    {
                        object_ptrs.push_back((*it));
                        active_ptrs.push_back((*it));
                    }
            }
			cout<<"TOWN HALL CREATED"<<endl;
			break;			

		case 'm': // Miner
            // Check that the current ID entered doesnt conflict with another current Miners ID
            for(list<Person*>::iterator it = person_ptrs.begin(); it != person_ptrs.end(); ++it)
            {
                
                if((*it)->get_id() == ID)
                {
                    throw Invalid_Input("ID already in use in another Miner/Soldier/Inspector");
                }
                
                if(((*it)->get_location().x == x) && ((*it)->get_location().y == y))
                {
                    throw Invalid_Input("Same location as another existing Miner/Soldier/Inspector");
                }
                    
            }
			person_ptrs.push_back(new Miner(ID, Cart_Point(x,y)));
            for(list<Person*>::iterator it = person_ptrs.begin(); it != person_ptrs.end(); ++it)
            {
                if((*it)->get_id() == ID)
                {
                        object_ptrs.push_back((*it));
                        active_ptrs.push_back((*it));
                }
            }
			cout<<"MINER CREATED"<<endl;
			break;

		case 's': // Soldier
            // Check that the current ID entered doesnt conflict with another current Soldiers ID
            for(list<Person*>::iterator it = person_ptrs.begin(); it != person_ptrs.end(); ++it)
            {
                
                if((*it)->get_id() == ID)
                {
                    throw Invalid_Input("ID already in use in another Miner/Soldier/Inspector");
                }
                
                if(((*it)->get_location().x == x) && ((*it)->get_location().y == y))
                {
                    throw Invalid_Input("Same location as another existing Miner/Soldier/Inspector");
                }
                    
            }
            person_ptrs.push_back(new Soldier(ID, Cart_Point(x,y)));
            for(list<Person*>::iterator it = person_ptrs.begin(); it != person_ptrs.end(); ++it)
            {
                if((*it)->get_id() == ID)
                {
                        object_ptrs.push_back((*it));
                        active_ptrs.push_back((*it));
                }
            }
			cout<<"SOLDIER CREATED"<<endl;
			break;
                
        case 'i':
            // Check that the current ID entered doesnt conflict with another current Inspectors ID
            for(list<Person*>::iterator it = person_ptrs.begin(); it != person_ptrs.end(); ++it)
            {
                
                if((*it)->get_id() == ID)
                {
                    throw Invalid_Input("ID already in use in another Miner/Soldier/Inspector");
                }
                
                if(((*it)->get_location().x == x) && ((*it)->get_location().y == y))
                {
                    throw Invalid_Input("Same location as another existing Miner/Soldier/Inspector");
                }
                
            }
            person_ptrs.push_back(new Inspector(ID, Cart_Point(x,y)));
            for(list<Person*>::iterator it = person_ptrs.begin(); it != person_ptrs.end(); ++it)
            {
                if((*it)->get_id() == ID)
                {
                    object_ptrs.push_back((*it));
                    active_ptrs.push_back((*it));
                }
            }
            cout<<"INSPECTOR CREATED"<<endl;
            break;

		default: // Flags throw if none of the input object characters match
			throw Invalid_Input("Invalid Object type");
			break;

		}
	
	

}

// Getter function to be implemented by the Inspector object
list<Gold_Mine*> Model::get_Gold_Mine_list()
{
    
    list<Gold_Mine*> copied_mines;
    
    for(list<Gold_Mine*>::iterator it_qer = mine_ptrs.begin(); it_qer != mine_ptrs.end(); ++it_qer)
    {
        
        copied_mines.push_back(*it_qer);
        
    }
    
    return copied_mines;
    
}









