#include <iostream>

using namespace std;

//valid declaration, it sets * and 45 as default value if not mentioned otherwise
void func(char='*', int=45);

int main(void){
	cout << "Overriding the default value in the function func(): " << endl;
	func('A', 10); //overrides the default value declared in the function declaration.
	cout << "calling the function without parameters which implies use of default values: " << endl;
	func(); //passes the default value of * and 45 as a parameter if not mentioned otherwise.
	return 0;
	
}

void func(char ch, int x){
	cout << "character argument: " << ch << " integer argument: " << x << endl;
}