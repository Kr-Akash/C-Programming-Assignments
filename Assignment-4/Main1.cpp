#include<iostream>
#include<stdlib.h>
#include "Problem1.h"

using namespace std;


int main(){
	defineVariables();
	cout << *ch <<  ": is pointed by the char pointer " << endl; //a pointer to a character
	cout << "Array of 10 integers " << endl;
	for(int i = 0; i<10; ++i)
		cout << intArr10[i] << " "; //an array of 10 integers
	cout << endl;
	cout << "Reference to an array of 10 integers: " << endl;
	for(int i = 0; i<10; ++i)
		cout << ref[i] << " "; //a reference to an array of 10 integers
	cout << endl;
	cout << "Printing using the pointer to an array of character strings" << endl;
	for(int i = 0; i<3; ++i)
		cout << stringArrayPtr[i] << endl; //a pointer to an array of character strings
	cout << "Value of constant Integer variable : " << constInt << endl;
	cout << "Value of pointer to constant integer: " << *pointerToConstant << endl;
	cout << "Value of constant pointer of type integer: " << *constPointer << endl;
	cout << "constant pointer to a constant double pointed value is: "<<*constPointerDouble << endl;
	return 0;
}
