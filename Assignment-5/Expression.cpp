#include <iostream>
#include <bits/stdc++.h>
#include <stack>
#include <string>
using namespace std;

class Expr
{
    // ...
public:
    const char *expr;
    Expr(const char *expr)
    {
        this->expr = expr;
    }
    // Expr(const char *expr);
    int eval();   // returns the value of the expression
    void print(); // prints representation of the expression on cout
};

// Function to check the precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPostfix(const char *infix)
{
    stack<char> st;
    string p = "";
    for (int i = 0; i < strlen(infix); i++)
    {
        char c = infix[i];

        // If the scanned character is an operand, add it to
        // output string.
        if (isalnum(c))
        {
            p += c;
        }

        // If the scanned character is an '(', push it to
        // the stack.
        else if (c == '(')
            st.push('(');

        // If the scanned character is an ')', pop and to
        // output string from the stack until an '(' is
        // encountered.
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                p += st.top();
                st.pop();
            }
            st.pop();
        }

        // If an operator is scanned
        else
        {
            while (!st.empty() && precedence(c) <= precedence(st.top()))
            {
                p += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty())
    {
        p += st.top();
        st.pop();
    }
    return p;
    
}

int performOperation(int operand1, int operand2, char operation)
{
    switch (operation)
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        return operand1 / operand2;
    default:
        return 0;
    }
}

int Expr::eval()
{
    const char *infix = expr;
    string str = infixToPostfix(infix);
    const char *postfix = &str[0];
    //cout << "postfix  " << postfix <<  endl;;  
    stack<int> stack;

    for (int i = 0; i < strlen(postfix); i++)
    {
        char c = postfix[i];

        if (isdigit(c))
        {
            // Convert char digit to int and push onto the
            // stack
            stack.push(c - '0');
        }
        else
        {
            // Pop the top two elements for the operation
            int operand2 = stack.top();
            stack.pop();
            int operand1 = stack.top();
            stack.pop();

            // Perform operation and push the result back
            // onto the stack
            int result = performOperation(operand1, operand2, c);
            stack.push(result);
        }
    }
    // The final result should be the only item left in the
    // stack
    return stack.top();
}

void Expr::print()
{
    cout << expr << endl;
}

int main()
{
    Expr x("8/4+3*4-3");
    cout << "x = " << x.eval() << "\n";
    x.print();
    
    Expr y("9+2*3");
    cout << "y = " << y.eval() << "\n";
    y.print();
    return 0;
}
