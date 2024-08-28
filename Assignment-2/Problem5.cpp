#include <iostream>

/*
	Explanations:
	The following program creates a 2d array of size 3x5, and calls f1 function and the values in 
	that 2d array is modified. Each value is increased by 2.
	m[i][j] = m[i][j] +2; //line is adding 2 to each element of the 2d array by iterating on i and j indices respectively.
	
	Is it valid to pass a 2d array to a function without passing the first dimension? why?
	Answer: Yes, it is valid.
	The 2d array will be stored in memory as 1 2 3 4 5 11 12 13 14 15 21 22 23 34 25 , i.e, row major order
	void f1(int m[][5], int dim1)
	Here we tell the compiler that parameter m is an array of unspecified length(which will decay to pointer)
	to arrays of dimension [5]. That is, a pointer to 5 ints all in a row next to each other.
	Also  at the level where the array is declared, we can say things like m[0] and the type of m[0] technically, 
	it's the address of the 0th row of m, which is itself  of type int[5].
	

*/

void f1(int m[][5],int dim1){
	for(unsigned int i=0;i<dim1;i++)
		for(unsigned int j=0;j<5;j++)
			m[i][j] = m[i][j]+2;
}
int main(){
	// initialize a 2d array.
	int m[3][5] {{1,2,3,4,5},{11,12,13,14,15}, {21,22,23,34,25}};
	f1(m,3);
	for(unsigned int i=0;i<3;i++){
		for(unsigned int j=0;j<5;j++)
			std::cout << m[i][j] << " ";
		std::cout << "\n";
	}
}
