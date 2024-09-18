#include <iostream>

using namespace std;

void swap(int *x, int *y){ //function with pointer arguments
	int temp = *x;
	*x = *y;
	*y = temp;
}

void swap(int &x, int &y){ //function with reference arguments
	int temp = x;
	x = y;
	y = temp;
}

int main(){
	int a, b;
	cout << "Enter two numbers that need to be swapped: " << endl;
	cin >> a >> b;
	cout << "Using Pointers: " << endl;
	cout << "Before swapping: " << endl;
	cout << a << " " << b << endl;
	swap(&a, &b);	
	cout << "After swapping: " << endl;
	cout << a << " " << b << endl;
	cout << "Using References: " << endl;
	cout << "Before swapping: " << endl;
	cout << a << " " << b << endl;
	swap(a, b);	
	cout << "After swapping: " << endl;
	cout << a << " " << b << endl;
	
	return 0;
}
