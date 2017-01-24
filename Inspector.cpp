#include "Inspector.h"

using namespace std;

// Defining constructors
Inspector::Inspector() : Person('I')
{
    
    this->state = 's';
    this->inspector_location = get_location();
    cout<<"Inspector default constructed"<<endl;
    
}

Inspector::Inspector(int in_id, Cart_Point in_loc) : Person('I', in_id, in_loc)
{
    
    this->state = 's';
    this->inspector_location = get_location();
    cout<<"Inspector constructed"<<endl;
    
}


// Defining member functions

void Inspector::start_inspecting(Model* model)
{
    
    // First error check to be sure that we have Gold Mines to actually inspect
    if(model->get_Gold_Mine_list().empty())
    {
        
        cout<<"Inspection not possible; no Gold Mines exist"<<endl;
        return;
        
    }
    
    else // Since the list isn't empty, we can now allow the inspector to inspect
    {
        list<Gold_Mine*> mine_list = model->get_Gold_Mine_list();
        // Setup the inspecting environment by storing all of the Gold Mines in Model into the not_inspected lists
        for(list<Gold_Mine*>::iterator it = mine_list.begin(); it != mine_list.end(); ++it)
        {
            
            // Store all of the mines in the not_inspected list to start
            not_inspected.push_back((*it));
            
        }
        
    }
    
    // Then sets the destination to be the closest mine and sets the Inspector to the outbound state
    double shortest_distance = 100;
    Gold_Mine* first_mine;
    
    for(list<Gold_Mine*>::iterator it = model->get_Gold_Mine_list().begin(); it != model->get_Gold_Mine_list().end(); ++it)
    {
        // First calculating to find the Mine that is the shortest distance from the current point
        if(abs(cart_distance((*it)->get_location(), this->get_location())) < shortest_distance)
        {
            
            shortest_distance = abs(cart_distance((*it)->get_location(), this->get_location()));
            first_mine = (*it);
            
        }
        
    }
    
    lifo_mines.push_back(first_mine);
    this->setup_destination(first_mine->get_location());
    this->state = 'o';
    
}

bool Inspector::update() // Only returns true when the inspector has arrived at the destination
{
    // Possible states include outbound ('o') inbound ('i') and stopped ('s')
   
    switch(this->state)
    {
            
            case 's':
            
                return false;
            
            case 'o':
            
                if(update_location()) // Checks if we are one step away, and sets the state to stop if this is true
                {
                    this->state = 'r';
                    return true;
                }
                else
                {
                    
                    return false; // Stay in the moving state
                    
                }
            
            case 'i':
            
                if(update_location()) // Checks if we are one step away, and sets the state to stop if this is true
                {
                    this->state = 'r';
                    return true;
                }
                else
                {
                    
                    return false; // Stay in the moving state
                    
                }
            
            case 'r': // Store the amount at the mine, manipulate lists to reflect this change, and calculate the next mine to go to
            
                // Remove the visited mine from the not inspected list
                for(list<Gold_Mine*>::iterator it = not_inspected.begin(); it != not_inspected.end(); ++it)
                {
                    
                    if((this->get_location().x == (*it)->get_location().x) && (this->get_location().y == (*it)->get_location().y))
                    {
                        
                        it = not_inspected.erase(it);
                        
                    }
                    
                }
                
                if(not_inspected.empty()) // if the not_inspected list is empty, we are then traversed back to the inbound state
                {
                    
                    // Setup the destination
                    for(list<Gold_Mine*>::iterator it = lifo_mines.begin(); it != lifo_mines.end(); ++it)
                    {
                        
                        if((this->get_location().x == (*it)->get_location().x) && (this->get_location().y == (*it)->get_location().y))
                        {
            
                            if(*it == lifo_mines.front())
                            {
                                this->setup_destination(inspector_location); // If we are at the first element in the LIFO, send back to original location
                            }
                            else
                            {
                                this->setup_destination((*prev(it))->get_location()); // Setup the destination to the previous element in the list
                            }
                            
                        }
                    
                        else if((this->get_location().x == inspector_location.x) && (this->get_location().y == inspector_location.y))
                        {
                            
                            // This covers the end case of the inbound state, and we set the inspector stopped at home
                            this->state = 's';
                            
                        }
                    
                    }
                    this->state = 'i';
                    return false;
                    
                }
                
                // Then calculates the shortest distance again and sets up the next mine destination; change state accordingly
                double shortest_distance = 100;
                Gold_Mine* next_mine;
                
                for(list<Gold_Mine*>::iterator it = not_inspected.begin(); it != not_inspected.end(); ++it)
                {
                    // First calculating to find the Mine that is the shortest distance from the current point
                    if(abs(cart_distance((*it)->get_location(), this->get_location())) < shortest_distance)
                    {
                        
                        next_mine = (*it);
                        
                    }
                    
                }
                
                lifo_mines.push_back(next_mine);
                this->setup_destination(next_mine->get_location());
                this->state = 'o';
                
                return false;
                
            }
            
    
    
    return false; // Handles edge case where nothing is returned
    
}


void Inspector::show_status()
{
    
    cout<<"Inspector status: ";
    if(this->state == 'i')
    {
        
        Game_Object::show_status();
        cout<<". Inbound"<<endl;
        for(list<Gold_Mine*>::iterator it = lifo_mines.begin(); it != lifo_mines.end(); ++it)
        {
            if((this->get_location().x == (*it)->get_location().x) && (this->get_location().y == (*it)->get_location().y))
            {
                
                cout<<"INSPECTOR READING: Amount of gold removed from this mine is "<<abs(amounts_in_mines_outbound.back() - (*it)->get_gold_amount())<<" gold."<<endl;
                amounts_in_mines_outbound.remove(amounts_in_mines_outbound.back()); // Pop the value off the stack to prep for the next mine read
                
            }
            
        }
        
    }
        
    else if(this->state == 'r')
    {
        
        Game_Object::show_status();
        for(list<Gold_Mine*>::iterator it = lifo_mines.begin(); it != lifo_mines.end(); ++it)
        {
            if((this->get_location().x == inspector_location.x) && (this->get_location().y == inspector_location.y))
            {
                cout<<". Inspection trip completed"<<endl;
                this->state = 's';
            }
            else
            {
                cout<<". Inspecting the mine..."<<endl;
                //cout<<"INSPECTOR READING: This mine contains "<<(*it)->get_gold_amount()<<" gold."<<endl;
            }
        }
        
    }
        
    else if(this->state == 'o')
    {
        
        Game_Object::show_status();
        cout<<". Outbound"<<endl;
        for(list<Gold_Mine*>::iterator it = lifo_mines.begin(); it != lifo_mines.end(); ++it)
        {
            
            if((this->get_location().x == (*it)->get_location().x) && (this->get_location().y == (*it)->get_location().y))
            {
                
                cout<<"INSPECTOR READING: This mine contains "<<(*it)->get_gold_amount()<<" gold."<<endl;
                amounts_in_mines_outbound.push_back((*it)->get_gold_amount());
                
            }
            
        }
        
    }
    
    else if(this->state == 's')
    {
        
        Person::show_status();
        
    }
    
}


