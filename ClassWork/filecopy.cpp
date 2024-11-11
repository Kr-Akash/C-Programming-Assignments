#include<iostream>
#include<fstream>

using namespace std;

int main(){
	ifstream inFile("original.txt", ios::in);
	ofstream outFile("copied.txt", ios::out);
	if(outFile.fail() || inFile.fail()){
		cout << "Couldn't open file" << endl;
		return -1;
	}
	string str = "";
	while(getline(inFile, str)){
		outFile << str << endl;
	}
	
	return 0;
}
