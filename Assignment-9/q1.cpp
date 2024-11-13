#include<iostream>
#include<fstream>
#include<string>

using namespace std;

/* A file descriptor type */
class fileRA{
	fstream file;
	public:
	fileRA(const char* fname){
		file.open(fname, ios::out | ios::in);
		if (!file){
			cout << "File did not open \n";
			exit(1);
		}
	}
	fstream &operator[](int x){
		file.seekp(x, ios::beg);
		return file;
	}
	fstream &operator=(char ch){
		file << ch;
		return this->file;
	}
	
};
int main()
{
	/* Opens the file in read and write mode */
	fileRA fobj("Test.txt");
	fobj[4] = 'A'; // random writing to file
	
	return 0;
}
