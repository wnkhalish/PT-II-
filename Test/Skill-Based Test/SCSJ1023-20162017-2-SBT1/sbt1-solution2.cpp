////////////////////////////////////////////////////////////////////////////////
// Faculty of Computing, Universiti Teknologi Malaysia
// SCSJ1023- Programming Technique II
// Semester 2, 2016/2017
// Skill-based Test 1
// 22 March 2016
// Solution 2: Using C-strings
////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<cmath>

using namespace std;

// The defintion of function that converts a number in word to its integer value (6 marks)
int textToNumber(const char *txt)
{
	if (strcmp(txt,"one")==0) return 1;
	if (strcmp(txt,"two")==0) return 2;
	if (strcmp(txt,"three")==0) return 3;
	if (strcmp(txt,"four")==0) return 4;
	if (strcmp(txt,"five")==0) return 5;
	
	return 0;
}

int main()
{
	// Reading the user input (1 mark)
	char text[100];
	cout <<"What is: ";
	cin.getline(text,100);
	
	int len = strlen(text);
	char operand1[20]="";
	char oper[20]="";
	char operand2[20]="";
	char *p;
	
	// Extracting words of the first and second operands as well as the operator (6 marks)

	// To extract the first operand
	p = strstr(text," ");
	strncpy(operand1,text, p-text);

	// To extract the operation
	strcpy(text, p+1);
	p = strstr(text," ");
	strncpy(oper,text, p-text);

	// The remaining word is the second operand
	strcpy(operand2, p+1);

	// Converting the operands from words to integers (2 marks)
	int number1 = textToNumber(operand1);
	int number2 = textToNumber(operand2);
	
	// Performing the arithmetic calculation accordingly, i.e., addition or subtraction (3 marks)
	int result;
	if (strcmp(oper,"plus")==0) result = number1 + number2;
	else result = number1 - number2;
	
	// Converting the result from integer to word (12 marks)
	int n=abs(result);

	char s[20]="";

	if (n == 0)      strcpy(s,"zero");
	else if (n == 1) strcpy(s,"one");
	else if (n == 2) strcpy(s,"two");
	else if (n == 3) strcpy(s,"three");
	else if (n == 4) strcpy(s,"four");
	else if (n == 5) strcpy(s,"five");
	else if (n == 6) strcpy(s, "six");
	else if (n == 7) strcpy(s,"seven");
	else if (n == 8) strcpy(s,"eight");
	else if (n == 9) strcpy(s,"nine");
	else if (n == 10) strcpy(s,"ten");
	
	if (result<0) strcat("negative ", s);
	
	// Printing the answer (1 mark)
	cout << "Answer: " << operand1 <<" " << oper << " " << operand2 << " is " << s << endl;
	
	return 0;
}
