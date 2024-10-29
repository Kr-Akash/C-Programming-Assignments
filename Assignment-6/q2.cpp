#include<iostream>

using namespace std;

struct foo{
	foo(){cout << "foo()\n" ;}
	~foo(){cout <<"~foo()\n";}
	int i {5};
};
struct obj{
	const foo& getFoo(){return my_foo;}; //getFoo() method returns the refernce of the my_foo object
	foo my_foo; //constructor foo() is called since my_foo is created
};
int main(){
	obj *o = new obj(); //pointer o of type obj, is pointing to obj object and default constructor is called to initialize the members of the obj structure. Now my_foo of type foo object is created and it's constructor is called so "foo()\n" get printed to the console and variable int i get initialized to value 5.
	const foo& val = o->getFoo(); //alias val of my_foo is created, since o->getFoo() returns the reference of the my_foo object.
	cout << "val.i=" << val.i << std::endl; //prints the value of val.i which is equivalent o->my_foo.i since val is alias as explained in above line.
	delete o; //deleting the memory allocated by the new operator, so members of obj that is  my_foo object is also deleted. implicit Destructor is called for obj, which calls to explicitly defined destructor ~foo() which prints out "~foo()\n"
	cout << "val.i=" << val.i << std::endl; //since the memory for the members pointed by the obj *o is deallocated, so alias val of type foo is storing garbage value, which may lead to unexpected behaviour too.
}
