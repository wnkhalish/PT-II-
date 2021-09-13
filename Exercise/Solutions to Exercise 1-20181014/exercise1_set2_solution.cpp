// Programming Technique II (SCSJ1023)
// Semester 1, 2018/2019

// Exercise 1: Constructors and Desctructors

#include <iostream>
using namespace std;

// * ---------------------------------------------------------------------------------------------
// * Task 1 and Task 2: Declare and define the class Arithmetic
// *   You can use either inline or separation style for these tasks
// * ---------------------------------------------------------------------------------------------

class Arithmetic
{
  private:
	double left, right; // The left and right operands
	char oper;			// The operator. it can be either '+', '-', '*', '/'

  public:
	Arithmetic();
	Arithmetic(char);
	Arithmetic(double, char, double);
	~Arithmetic();

	double getLeft() const;
	double getRight() const;
	char getOper() const;
	void setLeft(double);
	void setRight(double);
	void setOper(char);

	double evaluate() const;
};

int main()
{
	// * ---------------------------------------------------------------------------------------------
	// * Task 3: Create an Arithmetic object with an appropriate constructor to perform
	// *           the calculation of
	// *             5.0 / 2.0
	// *        and print the result onto the screen using an appropriate method
	// * ---------------------------------------------------------------------------------------------

	Arithmetic a1(5.0, '/', 2.0);
	cout << "a1 result = " << a1.evaluate() << endl
		 << endl;

	// * ---------------------------------------------------------------------------------------------
	// * Task 4: Create an Arithmetic object using a constructor that accepts only a parameter to set
	// *         the operation type to '*'
	// *         Then, set the left and right operands for the object with values entered from the keyboard
	// *         Finally, evaluate and print the result onto the screen
	// * ---------------------------------------------------------------------------------------------

	Arithmetic a2('*');
	double first, second;
	cout << "Enter the operands for a2 => ";
	cin >> first >> second;
	a2.setLeft(first);
	a2.setRight(second);

	cout << "a2 result = " << a2.evaluate() << endl
		 << endl;

	system("pause"); // ! remove this line if you are using Dev C++

	return 0;
}

Arithmetic::Arithmetic()
{
	left = right = oper = 0;
}

Arithmetic::Arithmetic(char _oper) : Arithmetic(0, _oper, 0)
{
}

Arithmetic::Arithmetic(double l, char o, double r) : left(l), oper(o), right(r)
{
}

Arithmetic::~Arithmetic()
{
	cout << "The Arithmetic object is being destroyed" << endl;
}

double Arithmetic::getLeft() const
{
	return left;
}

double Arithmetic::getRight() const
{
	return right;
}

char Arithmetic::getOper() const
{
	return oper;
}

void Arithmetic::setLeft(double value)
{
	left = value;
}

void Arithmetic::setRight(double value)
{
	right = value;
}

void Arithmetic::setOper(char value)
{
	oper = value;
}

double Arithmetic::evaluate() const
{
	switch (oper)
	{
	case '+':
		return left + right;
	case '-':
		return left - right;
	case '*':
		return left * right;
	case '/':
		return left / right;
	}
}

// 7:55
