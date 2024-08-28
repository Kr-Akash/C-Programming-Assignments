#include<iostream>
#include<cstring>

using namespace std;

// selection sorting algorithm for integers
void sort1(int *a, int n){
	for(unsigned int i=0;i<n;i++)
		for(unsigned int j=i+1;j<n;j++)
			if(a[i] > a[j])
				swap(a[i],a[j]);
}

int compare_strings(char *a, char *b){
	int len1 = strlen(a);
	int len2 = strlen(b);
	for(int i = 0; i< min(len1,len2); ++i){
		if(a[i] > b[i]){ //first string is greater 
			return 1; // to swap
		}
		if(a[i] < b[i]){//first string is smaller lexicographically
			return 0; //dont swap
		}
	}
	//2nd string is longer in length but equal lexicographically upto the smaller length 1st string
	if(len2 < len1) //smaller string should be first.
		return 1;
	return 0;//else both are same
}

// selection sorting algorithm for strings
void sort2(char *a[], int n){
	char *temp;
	for(unsigned int i = 0; i<n; ++i){
		for(unsigned int j = i+1; j<n; ++j){
			if(compare_strings(a[i],a[j])){ 
			//if condition is 1(true), when the a[j] string is smaller than the a[i] string
			//so swap
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int main() {
	int a[] {-2,3,8,10,7,56,90};
	char* str[] {"hello", "world", "iacs","raining"};
	void (*sortInt)(int *, int );
	sortInt= &sort1;
	sortInt(a,7); // call via function pointer
	for(unsigned int i=0;i<7; i++)
	std::cout << a[i] << " ";
	std::cout << "\n";
	void (*sortString) (char*[], int);
	sortString = &sort2;
	sortString(str,4);
	for(unsigned int i=0;i<4; i++)
	std::cout << str[i] << " ";
	std::cout << "\n";
}
