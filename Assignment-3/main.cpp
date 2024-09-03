#include<string>
#include<iostream>
#include "revwords.h"

using namespace std;

int main(void){
	/* //static input output
	
	char str[] = "University of Cambridge!";
	cout << "String before reversing:\n" << str << endl;
	reverse_words(str);
	cout << "String after reversing:\n" << str << endl;
	*/
	
	//user input output at run time
	string s;
	cout << "Enter the string to reverse the words in it:" << endl;
	getline(cin, s);
	//the given function reverse_words(char[])accepts char array, std::string cannot be used directly
	char *ch = &s[0]; 
	cout << "Input String:\n" << ch << endl;
	reverse_words(ch);
	cout << "String after reversing the words in it:\n" << ch << endl;
	return 0;
}
