#include <iostream>
using namespace std;


int main()
{
	const char *str = "India vs Pakistan, Asia Cup 2023"; //const keyword added 
	//str[7] = 'V'; //Commented out the line to fix the runtime error
	//String literals are immutable in c++, so modifying the string is illegal and results in runtime error. String literals are constant in nature and lifetime is throughout the lifetime of the runtime of the program.
	double darr[] = {2.3, 4.5, 5.5};
	*(darr+3) = 6.5;
	extern float f;
	float g = f * 100.5; /*this line results in linking error because variable f definition is not available anywhere, since extern float f is just declaration hence no memory is allocated for variable f. So to fix this issue  another file called Problem4Def.cpp is created and only variable f definition is written in that cpp file.
	To compile g++ Problem4.cpp Problem4Def.cpp command is used
	*/
	
	short int i = 89;
	void *v = &i;
	short int *ip = static_cast<short int*>(v); //corrected line
	//int *ip = static_cast<int*>(v); //commented out as it results in unwated behaviour
	// this explicit type casting results in an unwanted behaviour since the type casting from short int to int is done, because variable v void pointer is pointing to the short int i variable address. to fix this problem, we should use same date type
	cout << "integer = " << *ip;
}
