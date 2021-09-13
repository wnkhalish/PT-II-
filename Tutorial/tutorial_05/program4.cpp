#include<iostream>
#include<string>
#include<cctype>

using namespace std;

// Task 1: Define the function lowercase that converts a string to lower case
string lowercase(string s)
{
	for(int i = 0; i < s.length(); i++)
		s[i] = tolower(s[i]);
		
	return s;	
}

string numberToText(int i)
{
	const string NUMBERS[5] = {"zero", "one","two", "three", "four"};
	
	if(i < 0) return "negative " + NUMBERS[-i];
	return NUMBERS[i];
}

// Task 2: Define the function textToNumber that converts a number in word to its integer value
int textToNumber(string txt)
{
//	const string NUMBERS[5] = {"zero", "one","two", "three", "four"};
//	for (int i=0; i<5; i++)
//		if (txt==NUMBERS[i]) return i;
	if (txt == "zero") return 0;
	if (txt == "one") return 1;
	if (txt == "two") return 2;
	if (txt == "three") return 3;
	if (txt == "four") return 4;
}

int main()
{
	// Task 3a: Read user input
	string text;
	cout <<"What is: ";
	//getline(cin,text);
	
	text = "ONE minus Four"; // one plus two
	
	// Task 3b: Convert the user input to lower case
	text = lowercase(text);
	
	int len = text.length();
	
	
	// Task 4: Extract words of the first and second operands as well as the operator
	int pos1 = text.find(" ");
	int pos2 = text.find(" ", pos1+1);
	int pos3= text.length();
	string operand1 = text.substr(0,pos1);
	string operation = text.substr(pos1+1,pos2-pos1-1);
	string operand2= text.substr(pos2+1, pos3-pos2-1);
	

	// Task 5: Convert the operands from words to integers
	int value1, value2;
	value1 = textToNumber(operand1);
	value2 = textToNumber(operand2);

	// Task 6: Perform the arithmetic calculation accordingly, i.e., addition or subtraction
	int result;
	
//	if( operation.compare("plus") == 0 ) result = value1 + value2;
//	else if( operation.compare("minus")  == 0 ) result = value1 - value2;
	
	if(operation == "plus") result = value1 + value2;
	else if(operation == "minus") result = value1 - value2;

	// Task 7: Convert the result from integer to word
	string sResult = numberToText(result);

	cout << sResult << endl;
	return 0;

	
	// Task 8: Print the answer
	string output = text;
	output = output +  " is " + sResult;
	
	cout << output << endl;
	
	cout << endl << endl;
//	system("pause"); //! remove this line if you are using Dev C++
	return 0;
}
