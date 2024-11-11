#include<iostream>
#include<fstream>

using namespace std;

int main(){
	ifstream inFile("File.txt", ios::in);
	if(inFile.fail()){
		cout << "Couldn't open file" << endl;
		return -1;
	}
	char ch;
	int sum = 0;
	while(inFile.get(ch)){
		sum += ch;
		cout << "The char Added was : " << ch << " With ASCII value: " << int(ch) << endl;
	}
	cout << "The Sum is : " << sum << endl;
	
	
	return 0;
}
