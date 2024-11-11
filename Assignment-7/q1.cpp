#include <iostream>
using namespace std;
struct X
{
    int i;
    X(int i)
    {
        this->i = i;
    }
    X operator+(int x)
    {

        return X(this->i + x);
    }
};
struct Y
{
    int i;
    Y(X x)
    {
        this->i = x.i;
    }
    Y operator+(X x)
    {
        return Y(X(x.i + this->i));
    }
    operator int()
    {
        return this->i;
    }
};
ostream &operator<<(ostream &os, Y y)
{
    os << y.i;
    return os;
}
ostream &operator<<(ostream &os, X x)
{
    os << x.i;
    return os;
}
extern X operator*(X x, Y y)
{
    return X(x.i * y.i);
}
extern int f(X x)
{
    return x.i;
}
X x = 1;
Y y = x;
int i = 2;
int main()
{
    cout << "i+10= " << i + 10 << endl;             // int + int
    cout << "y+Y(10)= " << y + Y(10) << endl;       // 10 is explicitly type casted to Y
    cout << "y+X(10)*y= " << y + X(10) * y << endl; // 10 is explicitly type casted to X so that overloaded * operator paramters are matched and then y + returned value X from overloaded * operator is performed
    cout << "x+y+i= " << x + y + i << endl;         // x+y where y is converted to int and x+y is performed and returned X and then i is converted to X and then returned X value + converted i is added
    cout << "(x * x + i)=" << (x * x + i) << endl;  // for x*x overloaded operator * is called and second parameter is Y type so second x is converted to Y type and the returned result is X type and then returned X + i performed and the final result is of X type
    cout << "f(7) = " << f(7) << endl;              // f(7) is implicitly converted to f(X) and int value is returned
    cout << "f(int(y))= " << f(int(y)) << endl;     // y is explicitly converted to int and then the converted int is explicitly casted to X type
    cout << "y+y= " << y + y << endl;               // y + y i
    cout << "106+y= " << 106 + y << endl;
