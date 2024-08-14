#include<iostream>

long double expression(long double x){
	return (x+ (1/(x+(1/(x + (1/x))))));
	
}

int main(){
	long double x, y;
	std::cout << "Enter a  real number" << std::endl;
	std::cin >> x;
	
	y = expression(x);
	std::cout << "The evalutated expression value : " << y << std::endl;
	return 0;
	
}
