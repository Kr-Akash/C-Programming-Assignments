#include "Problem1.h"
#include <iostream>
using namespace std;

//Definition of the variables declared in Problem1.h file

int intArr10[10] = {10, 20, 30, 40, 50, 60 , 70, 80, 90, 100};
//int intArr10[10];
char *ch;
int (&ref)[10] = intArr10; 
char *stringArrayPtr[3] = {"Hello", "world!", "Bye!"};
char **characterPtrPtr;

const int constInt = 64;

int const* pointerToConstant;

const int* constPointer;
const double temp = 16.256;
const double *const constPointerDouble = &temp;

extern void defineVariables(){
	char A = 'A';
	ch = &A;
	characterPtrPtr = &ch; //pointer to a pointer
	cout << **characterPtrPtr << " is pointed by the pointer to a char pointer" << endl;
	characterPtrPtr = stringArrayPtr;
	pointerToConstant = &constInt;
	constPointer = pointerToConstant;
}
