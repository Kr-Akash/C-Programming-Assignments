#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Helper
{

    private:
        std::iostream& stream;
        int index;
    public:
        Helper(std::iostream& stream, int index) : stream(stream), index(index) { }
        operator char() const
        {
            stream.seekg(index);
            char ch = stream.get();
            return ch;
        }
        Helper& operator=(char ch)
        {
            stream.seekp(index);
            stream.put(ch);
            return *this;
        }
};



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
	/*fstream &operator[](int x){
		file.seekp(x, ios::beg);
		return file;
	}*/
	
	Helper operator[](int index)
        {
            return Helper { file, index };
        }
	/*fstream &operator=(char ch){
		file << ch;
		return this->file;
	}*/
	int get_size(){
		int count =  0;
		char ch;
		while(file.get(ch)){
			++count;
		}
		cout << "cvount " << count << endl;
		return count;
	
	}
	
};
int main()
{
	/* Opens the file in read and write mode */
	fileRA fobj("Test.txt");
	fobj[4] = 'A'; // random writing to file
	/* print the contents of the file */
	for(unsigned int i=0;i<fobj.get_size();i++)
	std::cout << fobj[i];
	char c = fobj[1]; // implicit conversion to char
	std::cout << "Char is = " << c << std::endl;
	return 0;
}
