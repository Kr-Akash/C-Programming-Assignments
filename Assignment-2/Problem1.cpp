#include<iostream>

using namespace std;

/*-------Below are DECLARATIONS of the following according to the question----------*/
//function taking arguments of type pointer to character and reference to integer and returning no value;
void function(char *, int &);

typedef void (*functionPtr)(char *, int &); // a pointer to such a function; 

void function2(functionPtr); // a function taking such a pointer as an argument

functionPtr function3(); //a function returning such a pointer.

functionPtr function4(functionPtr);//such a pointer as an argument and returns its argument as the return value

//function4 definition
functionPtr function4(functionPtr ptr){//such a pointer as an argument
	int x = 10;
	char ch = 'A';
	ptr(&ch, x);
	return ptr; //returns its argument as the return value
}

//function1 definition
void function(char *ptr, int &ref){
	cout << *ptr << " " << ref << endl; //just displaying the values to the console
	
}


int main(void){
	functionPtr ptr = &function;
	int x = 10;
	functionPtr retPtr = function4(ptr);
	
}