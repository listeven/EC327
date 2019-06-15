
#include <iostream>

#include "Cart_Vector.h"
#include "Cart_Point.h"
#include "Game_Object.h"
#include "Town_Hall.h"
#include "Gold_Mine.h"
#include "Miner.h"
#include "Person.h"
#include "Game_Command.h"
#include "Model.h"
#include "Input_Handling.h"
#include "View.h"
#include <sstream>
#include <string>

#include <fstream>

using namespace std;


// Change it so it prints person list then mine then thall
// Can use switch or if clauses for display code when printing messages
// Needs to check if not enough inputs are entered (Like w 1 1 is missing town hall input)
// What is private member Model(const Model&)

// Move to bad location?

// Using !(myStream.eof()) works if we just use cin.
// However, when reading from a file, because of the whitespaces (\n), we need to use a different method
// Solution: Using erase + remove_if to remove spaces and check if string is empty.

// Done for now. Currently set up to read input from a file. 


int main()
{
	bool gameRunning = true;    
	char cmd, type;
	int ID1, ID2, ID3;
	double x, y;
	string cmdString, cinString, typeString;

	// For reading from sample input file
	//////////////
	string line;
	ifstream myFile("pa4_sample_input4.txt");
	//////////////

    Model* myModel = new Model();
    View myView = View();

    cout << endl << "Welcome to the game." << endl;
    cout << "Command List:" << endl;
    cout << "Move: m (personID) (xValue) (yValue)" << endl;
    cout << "Work: w (personID) (Gold_Mine_ID) (Town_Hall_ID)" << endl;
    cout << "Stop: s (personID)" << endl;
    cout << "Attack: a (personID) (targetID)" << endl;
    cout << "Go: g" << endl;
    cout << "Run: r" << endl;
    cout << "Quit: q" << endl << endl;
    myModel->show_status();
    myModel->display(myView);
    cout << endl;

    while(gameRunning){
    	cout << "Enter your command: ";
    	try{

    		// FOR CIN 
    		/*
    		getline(cin, cinString);
    		stringstream myStream(cinString);
			*/
    		// FOR READING FROM FILE
    		////////////////
    		stringstream myStream;
    		if(myFile.is_open()){
    			getline(myFile, line);		
    			myStream.str(line);
    		}
    		else{
    			getline(cin, cinString);
    			myStream.str(cinString);
    		}
    		cout << myStream.str() << endl;

    		//////////////

    		//getline(myStream, cmdString, ' ');
    		if( !(myStream >> cmdString)){
    			throw Invalid_Input("FAILED COMMAND!");
    		}
    		if(cmdString.length() != 1){
    			throw Invalid_Input("Incorrect command. Please refer to the command list.");
    		}
    		else{
    			cmd = cmdString[0];
    		}

	     	switch(cmd){
	    		case 'm':{
	    			if( !(myStream >> ID1 >> x >> y)){
	    				throw Invalid_Input("Incorrect command format. Please refer to the command list.");
	    			}
	    			else{
	    				if(checkForMoreInputs(myStream)){
	    					throw Invalid_Input("Too many inputs. Please refer to the command list.");
	    				}
	    				else{
	    					do_move_command(myModel, ID1, x, y);
	    				}
	    			}
	    			break;
	    		}

	    		case 'w':{
	    			if( !(myStream >> ID1 >> ID2 >> ID3) ){
	    				throw Invalid_Input("Incorrect command format. Please refer to the command list.");
	    			}
	    			else{
	    				if(checkForMoreInputs(myStream)){
	    					throw Invalid_Input("Too many inputs. Please refer to the command list.");
	    				}
	    				else{
		    				do_work_command(myModel, ID1, ID2, ID3);
	    				}
	    			}
	    			break;
	    		}

	    		case 's':{
	    			if( !(myStream >> ID1) ){
	    				throw Invalid_Input("Incorrect command format. Please refer to the command list.");
	    			}
	    			else{
	    				if(checkForMoreInputs(myStream)){
	    					throw Invalid_Input("Too many inputs. Please refer to the command list.");
	    				}
	    				else{
		    				do_stop_command(myModel, ID1);
	    				}
	    			}
	    			break;
	    		}

	    		case 'g':{
    				if(checkForMoreInputs(myStream)){
    					throw Invalid_Input("Too many inputs. Please refer to the command list.");
    				}
    				else{
	    				do_go_command(myModel, myView);
    				}
	    			break;
	    		}

	    		case 'r':{
    				if(checkForMoreInputs(myStream)){
    					throw Invalid_Input("Too many inputs. Please refer to the command list.");
    				}
    				else{
		    			do_run_command(myModel, myView);
    				}
	    			break;
	    		}

	    		case 'n':{
		    		if(!(myStream >> typeString)){
		    			throw Invalid_Input("Incorrect type detected.");
		    		}
		    		if(typeString.length() != 1){
		    			throw Invalid_Input("Incorrect type detected.");
		    		}
		    		else{
		    			type = typeString[0];
		    		}	

	    			if( !(myStream >> ID1 >> x >> y) ){
	    				throw Invalid_Input("Incorrect command format. Please refer to the command list.");
	    			}
	    			else{
	    				if(checkForMoreInputs(myStream)){
	    					throw Invalid_Input("Too many inputs. Please refer to the command list.");
	    				}
	    				else{
		    				do_new_command(myModel, myView, type, ID1, x, y);
	    				}
	    			}
	    			break;
	    		}

	    		case 'a':{
	    			if( !(myStream >> ID1 >> ID2) ){
	    				throw Invalid_Input("Incorrect command format. Please refer to the command list.");
	    			}
	    			else{
	    				if(checkForMoreInputs(myStream)){
	    					throw Invalid_Input("Too many inputs. Please refer to the command list.");
	    				}
	    				else{
		    				do_attack_command(myModel, myView, ID1, ID2);
	    				}
	    			}
	    			break;

	    		}

	    		case 'q':{
    				if(checkForMoreInputs(myStream)){
    					throw Invalid_Input("Too many inputs. Please refer to the command list.");
    				}
    				else{
	    				do_quit_command(myModel);
	    				gameRunning = false;
	    				myFile.close(); 
	    			}
	    			break;	    			
	    		}

	    		default:{
	    	    	throw Invalid_Input("Incorrect command. Please refer to the command list.");
	    		}

	    	}
	    	cout << endl;   		
    	}


    	catch(Invalid_Input& except){
    		cerr << "Invalid input - " << except.msg_ptr << endl;
    		cerr << "Input a valid command." << endl << endl;
    	}
    }

    return 0;

}

