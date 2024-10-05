#include<iostream>
#include<stack>
#include<cstring>

using namespace std;


class Expr{
	
public:
	const char* infix;
	string postfix;
	Expr(const char* expression){ 
	/*
		constructor that initializes the class variable infix to the expression passed as parameter
		when creating an instance of this class Expr.
		infix_to_postfix() function is called and class variable postfix then contains the string that is 
		postfix notation of the infix expression.
	*/
		this->infix = expression;
		infix_to_postfix();
	}
	
	bool isOperand(char symbol){ //this function returns true if the symbol is a digit
		 return (symbol >= '0' && symbol <= '9');

	}
	
	bool prcd(char a, char b){ 
	/*this function returns true when the operator a has higher precedence 
	 than operator b. It returns false otherwise*/
		return prcd(a) > prcd(b);
	}
	
	int prcd(char op){ //the higher the value the higher precedence
		if(op == '+'||op == '-')
    			return 1;
    		if(op == '*'||op == '/')
    			return 2;
    		return 0;
	}
	
	void infix_to_postfix(){ //called everytime when the instance of the class is created
	//function converts infix notation to postfix notation
		stack<char> opstk;
		for(int i = 0; i < strlen(infix); ++i){
			char symb = infix[i];
			if(isOperand(symb)){
				postfix += symb;
			}
			else{
				while(!opstk.empty() && prcd(opstk.top(), symb)){
					char topSymb = opstk.top();
					opstk.pop();
					postfix += topSymb;
				}
				opstk.push(symb);
			}
		}
		while(!opstk.empty()){
			char topSymb = opstk.top();
			opstk.pop();
			postfix += topSymb;
		}
	
	}
	
	int eval(){
	/*
		Function evaluates the postfix notation of the infix expression that was passed while creating 
		the instance of the class Expr.
		Returns the evaluated value of the epxression.
	*/
		stack<int> stack;
		for(char symb : postfix){
			if (isOperand(symb)) {
			stack.push(symb - '0');
		} 
		else
		{
			int operand2 = stack.top(); 
			stack.pop();
			int operand1 = stack.top();
			stack.pop();

			switch(symb){
		        	case '+': stack.push(operand1 + operand2); 
		        	break;
		        	case '-': stack.push(operand1 - operand2); 
		        	break;
		        	case '*': stack.push(operand1 * operand2); 
		        	break;
		        	case '/': stack.push(operand1 / operand2); 
		        	break;
		        	default: cout << "Operation not supported! Program terminated!" << endl;
		        	exit(0);
			}
		}
	    }
	    return stack.top();
	}
	
	void print(){ //prints the expression in the infix notation 
		cout << infix << endl;
		//cout << postfix << endl;
	}

};


int main(void){
	Expr x("8/4+3*4-3");
	cout << "x = " << x.eval() << "\n";
	x.print();
	
	Expr y("5+2*5");
	cout << "y = " << y.eval() << "\n";
	y.print();
	
	return 0;
}
