//import std;
#include<iostream>
int main(){
	int totalDays, remainingDays, years, weeks;
	std::cout << "Enter a number" << std::endl;
	std::cin >> totalDays;
	
	years = totalDays/365;
	remainingDays = totalDays % 365;
	
	weeks = remainingDays/7;
	remainingDays = remainingDays % 7;
	
	std::cout << years << " Years, " << weeks << " weeks, " << remainingDays << " days" << std::endl; 

	return 0;
	
}
