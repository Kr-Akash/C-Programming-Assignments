#include <iostream>
using namespace std;

struct X
{
    X() { cout << "default constructor\n"; };
    X(X &&x) { cout << "move constructor\n"; };
    X(const X &x) { cout << "copy constructor\n"; };
    X &operator=(const X &)
    {
        cout << "copy assignment\n";
        return *this;
    };
    ~X() { cout << "Destructor\n"; };
};

X foo(X x)
{
    return x;
}
int main()
{
    X obj; //default constructor is invoked and "default constructor" is printed
    obj = foo(obj); /*foo(X obj) method is invoked so a copy of the obj for the formal parameter X x is created, copy constructor explicitly defined is invoked and "copy constructor" gets printed. 
    returning the x object of foo type is not returned as referenced type, so the life cycle of the formal parameter x is going to end so the x object is moved to the return type X and move constructor is invoked and "move constructor" is printed. At end,the returned object is assigned to obj  and copy assignment is called which prints "copy assignment"
    As the main function returns, destructor is invoked first for the formal parameter X x in the foo(X x) method, and
    then the returned x which was moved get destructed and another "Destructor" string is printed, and finally for the 
    X obj Destructor is invoked, another "Destructor" message is printed and obj is destructed.	
    		    */
   return 0;
}
