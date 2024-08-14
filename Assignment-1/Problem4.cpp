#include <iostream>

using namespace std;


void display(int x){
	int size;
	size = 32;
	bool bits[size];
	for(int i = 0; i<size; ++i){
		bits[i] = false;	
	}
	for(int i = 0; i<size; ++i){
		if(x&(1<<i)){
			bits[i] = true;
		}
	}
	
	//output representation in binary 
	
	for(int i = size-1; i>=0; --i){
		if(bits[i])
			cout << 1;
		else
			cout << 0;
	}
	cout << endl;
	
}

int main(){
	int x, y;
	cout << "Enter a positive and a negative integer " << endl;
	cin >> x >> y;
	cout << "In-Memory Representation of positive number: " << endl;
	display(x);
	cout << "In-Memory Representation of negative number: " << endl;
	display(y);
	/* If we input x as positive number and y = -x, and perform 2's complement on x we will get the same value
	as stored in y, So the in-memory representation follows 2s complement system*/
	
	return 0;
}
