////////////////////////////////////////////////////////////////////////////////
// Faculty of Computing, Universiti Teknologi Malaysia
// SCSJ1023- Programming Technique II
// Semester 2, 2016/2017
// Skill-based Test 1
// 22 March 2016
// Solution 3: Advanced answer, simplfying the code using arrays
////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<string>
#include<cmath>

using namespace std;

// The defintion of function that converts a number in word to its integer value (6 marks)
int textToNumber(string txt)
{
	const string NUMBERS[5] = {"one", "two","three", "four", "five"};

	for (int i=0; i<5; i++)
		if (txt == NUMBERS[i]) return i+1;
	
	return 0;
}

int main()
{
	// Reading the user input (1 mark)
	string text;
	cout <<"What is: ";
	getline(cin, text);
	
	int len = text.length();
	
	
	// Extracting words of the first and second operands as well as the operator (6 marks)
	int pos1 = text.find(' ');
	int pos2 = text.find(' ', pos1+1);
	int pos3 = text.find(' ', pos2+1);
	
	string operand1 = text.substr(0,pos1);
	string oper     = text.substr(pos1+1,pos2-pos1-1);
	string operand2 = text.substr(pos2+1,pos3-pos2);
	string strResult;
	
	// Converting the operands from words to integers (2 marks)
	int number1 = textToNumber(operand1);
	int number2 = textToNumber(operand2);
	
	// Performing the arithmetic calculation accordingly, i.e., addition or subtraction (3 marks)
	int result;
	if (oper=="plus") result = number1 + number2;
	else if (oper=="minus") result = number1 - number2;
	
	// Converting the result from integer to word (12 marks)
	
	const string NUMBERS[11] = {"zero",	"one","two","three","four","five","six","seven","eight","nine","ten"};
	int n = abs(result);
	string s = NUMBERS[n];	
	if (result<0) s = "negative " + s;
	
	// Printing the answer (1 mark)
	cout << "Answer: " << text << " is " << s << endl;
	
	return 0;
}
