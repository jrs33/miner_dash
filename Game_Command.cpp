#include "Game_Command.h"

using namespace std;

void do_move_command(Model *model, int ID, int x, int y)
{

    // First check to be sure that we are within the grid
    if((x > 20) || (y > 20))
    {
        throw Invalid_Input("Enter within the bounds of the grid");
    }
    // Get person object to store the person from model for operation
	Cart_Point dest = Cart_Point(x,y);
	Person* p1 = model->get_Person_ptr(ID);
	p1->start_moving(dest);
	
}

void do_go_command(Model *model)
{
    
    cout<<"Advancing one tick."<<endl;
    // Call update on each object once by iterating through each array once
    model->update();
    model->show_status();

}

// Call update until it returns true or until 5 steps have been taken
void do_run_command(Model *model)
{
    
    cout<<"Advancing to next event."<<endl;
    int steps = 1;
    
    while(!model->update() && steps < 5)
    {

        steps++;
        
    }
    
    model->show_status();
    
}

void do_stop_command(Model *model, int ID)
{
    
    (model->get_Person_ptr(ID))->stop(); // Remember '->' == '(*).'

}

void do_list_command(Model *model)
{

    model->show_status();
    
}

void do_work_command(Model *model, int miner_id, int gold_mine_id, int town_hall_id)
{

    // Creating temporary storage to perform operation on the passed objects
    Person* p1;
    Gold_Mine* mine;
    Town_Hall* town_hall;
    
    // Find each of these objects and store them in the above initialized variables
    p1 = model->get_Person_ptr(miner_id);
    mine = model->get_Gold_Mine_ptr(gold_mine_id);
    town_hall = model->get_Town_Hall_ptr(town_hall_id);
    p1->start_mining(mine, town_hall);

    //model->display(view);
    
}

void do_quit_command(Model *model)
{
    
    model->~Model();

}


void do_attack_command(Model *model, int ID1, int ID2)
{

	// ID1 refers to the attacker, and ID2 refers to the object being attacked
	Person* attacker;
	Person* target;

	attacker = model->get_Person_ptr(ID1);
	target = model->get_Person_ptr(ID2);

	// Calls virtual function to be sure that the object is able to attack (ie: is a Soldier)
	attacker->start_attack(target);

	model->update();
	//model->display(view);

}

void do_new_command(Model* model, char objectType, int ID, int x, int y)
{

	model->handle_new_command(objectType,ID,x,y);

}


void do_inspect_command(Model* model, int ID)
{
    
    // Give the command for the inspector object to initiate action
    cout<<"Starting inspection trip"<<endl;
    (model->get_Person_ptr(ID))->start_inspecting(model);
    
}

