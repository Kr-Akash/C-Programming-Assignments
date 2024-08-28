#include<iostream>

typedef int (&rifii) (int, int); 
/*
	we get a type of rifii which is a reference of a function which has return type of int, and two int as a parameter.
	it allows us to do the following:
	riffi functionRef1, functionRef2;
	here functionRef1 and functionRef2 would be reference of a function which has return type of int and two int parameters.
	the reference of a function compared to the pointer to a function mandates that the user to pass anything but NULl.
	So pointer to a function can point to nullptr but reference to a function will not allow null, hence we don't need to check
	for null for cases where the function is mandatory.
	For example in some function such as sort having a parameter ,'riffi compare_function', will not accept null and it may useful when a comparator is 
	required for comparing two values, for which the logic is a must.
	
*/

//to demonstrate the usefulnees of 'typedef int (&rifii) (int, int);'
int compare_function(int x, int y){
	if(x > y)
		return 1;
	return 0;
	
}

int main(void){
	rifii ref_compare = compare_function;
	//ref_compare can't be null
	//ref_compare can be passed in some other funcdtion as a parameter,
	//for example: void	sort(int *arr, int size, rifii ref_compare);
	return 0;
}