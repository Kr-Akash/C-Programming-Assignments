#include<iostream>
using namespace std;

int count;

/*
	More appropriate for this scenario is the local static variable since global variable can be modified
	from some other functions which might not be desired.
	we cannot use local variable (non-static) because for each function call, an Activation record is created
	and those local variables are all stored in the stack section of the memory which will be lost when the function
	returns back to the call location.
	However both global and static variables are stored in the other secion of memory which remains available
	till the lifecycle of the application.

*/

void display_message_global(){ // uses global variable count
	cout << "I have been called " << ++count << " times!\n";
}

void display_message(){ //uses static variable  countVar
	static int countVar = 0;
	cout << "I have been called " << ++countVar << " times!\n";
	
}

int main(void){
	count = 0;
	cout << "Using global variable" << endl;
	for(int i = 0; i<10; ++i)
		display_message_global();
	cout << "\nUsing static variable" << endl;
	for(int i = 0; i<10; ++i)
		display_message();
}