#ifndef INPUT_HANDLING_H
#define INPUT_HANDLING_H

#include <iostream>

class Invalid_Input
{

	public: 
		Invalid_Input(const char* in_ptr) : msg_ptr(in_ptr) { }
		const char* const msg_ptr;
	
	private:
		Invalid_Input(); // No Default construction

};

#endif
