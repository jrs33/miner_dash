#ifndef Inspector_h
#define Inspector_h

#include <iostream>

#include "Person.h"
#include "Model.h"

using namespace std;

// Inspector inherits from Person and is used to go around to each Gold Mine to report the status of the mine
class Inspector : public Person
{
    public:
        // Defining the constructors
        Inspector();
        Inspector(int, Cart_Point);
    
        // Defining public member functions
        void start_inspecting(Model*);
        bool update(); // Must define since update is pure virtual
        void show_status();
    
    private:
        Cart_Point inspector_location; // Denotes the location it started at, to assure that it has a trail to go outbound and inbound to
    
        // The following lists will be used to store information about the Inspectors trips
        list<Gold_Mine*> not_inspected;
        list<Gold_Mine*> lifo_mines; // Organize a lists with a LIFO organization, since inbound will visit mines in opposite order as outbound
        list<double> amounts_in_mines_outbound;
    
};

#endif
