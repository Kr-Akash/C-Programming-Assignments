#include<iostream>

using namespace std;


class Expr{
	
public:
	const char* infix;
	const char* postfix;
	Expr(const char* expression){
		this->infix = expression;
	}
	
	void infix_to_postfix(){
		
	
	}
	
	int eval(){
		return 0;
	}
	
	void print(){
		cout << expression << endl;
	}

};


int main(void){
	Expr expr("8/4+3*4-3");
	expr.print();
	return 0;
}
