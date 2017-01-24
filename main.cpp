#include <iostream>

#include "Game_Command.h"
#include "Model.h"

#include "Input_Handling.h"
//#include <stdexcept>

using namespace std;



int main()
{
    ///// GETTING WEIRD ERROR WITH THROW AND do_new_command; THINKING THE ERRORS ARE WITH THE LISTS SINCE IT SAYS MEMORY IS CORRUPTING????////////////////////////
    cout<<"EC327: Introduction to Software Engineering"<<endl;
    cout<<"Fall 2016"<<endl;
    cout<<"Programming Assignment 3"<<endl;
    Model *model = new Model();
    model->show_status();
    
    View* v1 = new View();
    model->display(v1);
    char command = '\0';
		while(command != 'q')
		{
			cout<<"Enter command: ";
			int ID,x,y;
			
			try{
                cin>>command;
				switch(command)
				{
			    		case 'm':
					    cin >> ID;
                        if(!cin>>ID){
                            throw Invalid_Input("Please enter a valid input");
                        }
					    cin >> x;
                        if(!cin>>x){
                            throw Invalid_Input("Please enter a valid input");
                        }
					    cin >> y;
                        if(!cin>>y){
                            throw Invalid_Input("Please enter a valid input");
                        }
			        	do_move_command(model, ID, x, y);
						model->display(v1);
						break;
			
					case 'w':
					    cin >> ID;
                        if(!cin>>ID){
                            throw Invalid_Input("Please enter a valid input");
                        }
					    cin >> x;
                        if(!cin>>x){
                            throw Invalid_Input("Please enter a valid input");
                        }
                        cin >> y;
                        if(!cin>>y){
                            throw Invalid_Input("Please enter a valid input");
                        }
					    do_work_command(model, ID, x, y);
						model->display(v1);
					    break;

					case 's':
					    cin >> ID;
                        if(!cin>>ID){
                            throw Invalid_Input("Please enter a valid input");
                        }
					    do_stop_command(model, ID);
						model->display(v1);
					    break;

					case 'g':
					    do_go_command(model);
						model->display(v1);
					    break;

					case 'r':
					    do_run_command(model);
						model->display(v1);
					    break;

					case 'q':
					    do_quit_command(model);
					    break; 
		
					case 'l':
					    do_list_command(model);
					    break;
		
					case 'a':
					    int ID1, ID2;
					    cin>>ID1;
                        if(!cin>>ID1){
                            throw Invalid_Input("Please enter a valid input");
                        }
					    cin>>ID2;
                        if(!cin>>ID2){
                            throw Invalid_Input("Please enter a valid input");
                        }
					    do_attack_command(model, ID1, ID2);
						model->display(v1);
						break;
                    case 'i':
                        cin>>ID;
                        if(!cin>>ID)
                        {
                            throw Invalid_Input("Please enter a valid input");
                        }
                        do_inspect_command(model, ID);
                        model->display(v1);
                        break;
					case 'n':
					    char newObj;
					    cin>>newObj;
                        if(!cin>>newObj){
                            throw Invalid_Input("Please enter a valid input");
                        }
					    cin>>ID;
                        if(!cin>>ID){
                            throw Invalid_Input("Please enter a valid input");
                        }
					    cin>>x;
                        if(!cin>>x){
                            throw Invalid_Input("Please enter a valid input");
                        }
                        cin>>y;
                        if(!cin>>y){
                            throw Invalid_Input("Please enter a valid input");
                        }
					    do_new_command(model, newObj,ID,x,y);
						model->display(v1);
						break;
					default:
                        // Any possible case that isnt the above commands will trigger an exception throw
					    throw Invalid_Input("Please enter a valid input");
						break;

				}
			}
			// Catches the thrown exception for invalid input
			catch(Invalid_Input& exception) 
			{
				cout << "Invalid Input - " << exception.msg_ptr << endl;
				cin.clear();
				cin.ignore();				
			}
            
		}
		cout << "Terminating program" << endl;
   		return 0;

}

