#include<iostream>
#include<string>
#include<cstdlib>


using namespace std;

int main()
{
    string expression;
	string operand1, operand2, operation;
    double value1, value2, result;
    
    // Task 1: Read the string of arithmetic expression and put it into the variable "expression"
	cout <<"Enter an arithmetic expression, e.g. 20 + 30  => ";
//	expression = "20 + 3"; // $expression =~ /(\d+)\s+([+-*/])\s+(\d+)/;
	
	getline(cin, expression);
	//_____________________________________________
	
    
    // Task 2: Extract the operator and both operands from "expression" and 
	//           put them into the variables "operation", "operand1", and "operand2", accordingly
	
	int i = expression.find(" ");
	operand1 = expression.substr(0,i);
	operation = expression.substr(i+1,1);
	int n = expression.length() - (i+3);
	operand2 = expression.substr(i+3,n);
    // ___________________________;
    // ___________________________;
    // ___________________________;
    
	// Task 3:  Convert the string operands to numbers. 
	//            Put the numbers into variables "value1" and "value2", respectively
	
	value1 = atoi(operand1.c_str());
	value2 = atoi(operand2.c_str());
	   
    // Task 4: Determine the type of operation (i.e., either +, -, *, or / ) and perform the arithmetic calculation accordingly.
    //          Put the result of the calculation into the variable "result".
   
//   	if (operation=="+") result = value1 + value2;
//   	else if (operation.compare("-")==0) result = value1 -value2;
	switch (operation[0])	{  // char and int  . Can't use for double, float string
	
		case '+' : result = value1+value2; break;
		case '-' : result = value1-value2; break;
	}



	cout << endl << endl;	
    cout << "The value of the expression " << expression << " is " << result << endl << endl;
    
//    system("pause"); //! remove this line if you are using Dev C++
    return 0;
}









