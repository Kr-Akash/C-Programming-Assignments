#ifndef HEADER_H
#define HEADER_H

extern char *ch; //  a pointer to a character declaration
extern int intArr10[10]; // an array of 10 integers declaration

extern int (&ref)[10];  //a reference to an array of 10 integers declaration

extern char *stringArrayPtr[]; //a pointer to an array of character strings declaration

extern char **characterPtrPtr; //a pointer to a pointer to a character declaration

extern const int constInt; // a constant integer declaration

extern int const* pointerToConstant; // a pointer to a constant integer declaration
extern const int* constPointer; //a constant pointer to an integer declaration

extern const double *const constPointerDouble; // a constant pointer to a constant double declaration

extern void defineVariables(); // function that initiailze the declared variabls of this file declaration

#endif
