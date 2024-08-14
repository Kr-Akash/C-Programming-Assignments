#include <iostream>

using namespace std;

int main(){
	long double x, rounded;
	int k;
	cout << "Enter the real numbe: " << endl;
	cin >> x;
	cout << "Enter the value of K: " << endl;
	cin >> k;
	rounded = x * k;
	rounded = (long int) (rounded+0.5f); 
	rounded /= k;
	cout << "Rounded value to the Kth place: " << rounded << endl;
	
	return 0;
}
