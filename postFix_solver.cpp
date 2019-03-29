/*
*	Type in a post fix ecpression and teh solution will be evaluated!!
*	C++ Classes and Data Structures Ch2 Problem 14
	Code Last Updated: 3-28-2019
*/



#include <stack>
#include <iostream>
#include <iomanip>
#include <string>
#include <ctype.h> 
#include <math.h> //fmod
using namespace std;



int main() {

	stack <float> theStack, newStack;
	string postFix_exp;
	float operand2 = 0, operand1 = 0, x = 0, res = 0;

	retry_expression://***
	cout << "Type in an expression to be evaluated:\n";
	cin >> postFix_exp;

	if (postFix_exp.empty())
	{
		cout << "Please type in an expression!"; goto retry_expression; //***
	}
	else
	{
		int i = 0;
		while (i < postFix_exp.length()) { //keep looping until postfix is empty
			if (isdigit(postFix_exp[i]))  // Determine if string is int digit
			{
				x = postFix_exp[i] - '0';
				theStack.push(x);
				i++;
			}
			else //token is operator
			{
				operand2 = theStack.top(); 
				theStack.pop();
					if (operand2 == 0 && (postFix_exp[i] == '/' || postFix_exp[i] == '%'))
					{
					cout << "Your have divided by 0!\n";
					exit;
					}

				operand1 = theStack.top(); theStack.pop();
			
				switch (postFix_exp[i])//way to evaluate a char operator
				{
					case '+':
						res = operand1 + operand2;
						break;
					case '-':
						res = operand1 - operand2;
						break;
					case '*':
						res = operand1 * operand2;
						break;
					case '/':
						res = operand1 / operand2;
						break;
					case '%':
						res = fmod(operand1, operand2);
						break;
				}
				theStack.push(res);
				i++;
			}
		}
		
	}
	while (!theStack.empty()) {// Removes any additional digits w/o proper operator to evaluate
		newStack.push(theStack.top()); theStack.pop();
	}
	cout << fixed << showpoint << setprecision(2);
	cout << "Your result is: " << newStack.top() ; cout << "\n"; 


	while (!newStack.empty()) {// empties the stack that stored results
		newStack.pop();
	}
}