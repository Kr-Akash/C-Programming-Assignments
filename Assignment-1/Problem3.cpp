
#include<iostream>

int main(){
	char vowel1, vowel2, vowel3, vowel4, vowel5;
	char capVowel1, capVowel2, capVowel3, capVowel4, capVowel5;
	long double x,y;
	std::cout << "Enter lowercase vowels: " << std::endl;
	std::cin >> vowel1 >> vowel2 >> vowel3 >> vowel4 >> vowel5;
	std::cout << "vowel2-vowel1: " << vowel2 - vowel1 << std::endl; // yes, valid expressions vowel2 - vowel1 
	std::cout << "vowel5-vowel2: " <<vowel5 - vowel2 << std::endl; //yes, valid expressions vowel5 - vowel2
	
	std::cout << "Enter upppercase vowels: " << std::endl;
	std::cin >> vowel1 >> vowel2 >> vowel3 >> vowel4 >> vowel5;
	std::cout << "vowel2-vowel1: " << vowel2 - vowel1 << std::endl; // yes, valid expressions vowel2 - vowel1 
	std::cout << "vowel5-vowel2: " <<vowel5 - vowel2 << std::endl; //yes, valid expressions vowel5 - vowel2
	/*Yes capVowel2-capVowel1 have the same value of vowel2-vowel1 because the ASCII value for 
	 uppercase and lowercase differs, but they are contiguous in ASCII format according to alphabetical order
	 so the gap between A to E is same as a to e, i.e., in ASCII values 65 to 69 for uppercase and 97 to 101 for
	 lowercase is equal to 4;
	*/
	
	//2nd part of the question: expression 
	std::cout << "\n2nd part of the question : " << std::endl;
	std::cout << "Enter the value of y varible: " << std::endl;
	std::cin >> y;
	x = y - 20 * 6/9; //incorrect since the 6/9 expression wil give out an integer value as it is implicit in nature.
	std::cout << "The GIVEN expression evaluates to: " << x << std::endl;
	x = y - 20 * 6/9.0f; //Correct form of expressing for decimals
	std::cout << "The MODIFIED expression evaluates to: " << x << std::endl;
	
	
	
	
	
	return 0;
}
