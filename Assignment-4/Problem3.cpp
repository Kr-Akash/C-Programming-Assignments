#include <iostream>
const char* createString(){
	return "Practice makes a man perfect";
}
int* createInt(){
	int x = 100;
	return &x;
}
int main(){
	const char *str = createString();
	std::cout << "string = " << str << std::endl;
	/*
	Lifetime or storage duration of "Practice makes a man perfect". String literals in C/C++ have static storage duration, meaning that they live "forever", i.e. as long as the program runs. So, the memory occupied by "Some text!!" is never released. Hence the string literal returned from the createString() function is still valid
	*/
	int *ip = createInt(); //error
	std::cout << "integer = " << *ip << std::endl;
	/*
		However this is not valid since the lifetime of the int variable *ip is limited to the Active Record of the function call. Hence when the function is returned the local variables memory are no more reserved. Since the createInt() function returns address of the local variable, this will lead to segmentation fault since the memory is released as soon as the function is returned.
	*/
}
