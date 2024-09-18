#include <iostream>

using namespace std;

int numberOfMonths = 12;

struct Month{
	const char *monthName;
	int days;
};

void displayArray(const char *monthNames[], int days[]){
	cout << "Displaying month names and their number of days using arrays: " << endl;
	for(int i = 0; i < numberOfMonths; ++i){
		cout << monthNames[i] << "   " << days[i] << endl;
	}
	cout << endl;
}

void displayStructure(Month *Year){
	cout << "Displaying month names and their number of days using array of structure: " << endl;
	for(int i = 0; i< numberOfMonths; ++i){
		cout << Year[i].monthName << "   " << Year[i].days  << endl;
	}
	cout << endl;

}

int main(){
	const char *monthNames[numberOfMonths] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	int days[numberOfMonths]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	displayArray(monthNames, days);
	Month Year[numberOfMonths] = {
	{"January", 31}, {"February", 28}, {"March", 31}, {"April", 30}, {"May", 31}, {"June",30}, {"July", 31},{"August",31}, {"September",30}, {"October", 31}, {"November", 30}, {"December", 31},};
	displayStructure(Year);
	return 0;
}
