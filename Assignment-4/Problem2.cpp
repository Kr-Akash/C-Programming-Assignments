#include <iostream>
int main()
{
	const char* str1 = "We love C++ programming\n";
	char str2[100];
	char *p = str2;/*name of an array is implicitly converted
			to pointer to the first element.*/
	while(*p++ = *str1++){}
	/*
		Explanation: 
		const char* str1 = "We love C++ programming\n"; //str1 is a pointer pointing to the base address of the
		string "We love C++ programming\n", i.e., the very first character of the given string.
		let's say base address of str2[100] is 0x200
		let's say str1 character pointer points to base address 0x600
		now char *p = str2 makes a char pointer p pointing to base address of str2[], i.e, 0x200
		while(*p++ = *str1++){} 
		the while loop assigns each cell of the memory pointed by the p pointer the value of the str1 pointer
		For example
		memory cell 0x200 <- data of 0x600
		both p and str1 pointer are incremented by one
		so this will continue until the null character is encountered after the \n character which is to mark
		the end of the string, and at that instant the while loop terminates
		because value of *p is assigned null which breaks the loop
		And hence the whole string is copied from str1 to str2 character by character.
		
	*/
	std::cout << str2;
}
