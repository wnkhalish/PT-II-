// Programming Technique II (SCSJ1023)
// Semester 1, 2018/2019

// Exercise 1: Constructors and Desctructors

#include <iostream>
using namespace std;

// * ---------------------------------------------------------------------------------------------
// * Task 1: Declare and define the class Line
// * ---------------------------------------------------------------------------------------------
// 12:15 starts - 12:30
class Line
{
  private:
	double m, c;

  public:
	Line();
	Line(double, double);
	Line(double, double, double, double);
	~Line();

	double getM() const;
	double getC() const;
	void setM(double);
	void setC(double);
	void printEquation() const;
};

int main()
{
	// * ---------------------------------------------------------------------------------------------
	// * Task 2: Create the object 'line1'
	// * ---------------------------------------------------------------------------------------------

	Line line1(2.0, -5.0);
	line1.printEquation();

	// * ---------------------------------------------------------------------------------------------
	// * Task 3: Create the object 'line2'
	// * ---------------------------------------------------------------------------------------------
	Line line2(0, 0, 2, 8);
	line2.printEquation();

	// * ---------------------------------------------------------------------------------------------
	// * Task 4: Create the object 'line3'
	// * ---------------------------------------------------------------------------------------------
	Line line3;
	double slope, intercept;

	cout << "Enter the slope and y-intercept of the line,  m  c => ";
	cin >> slope >> intercept;
	cout << endl;

	line3.setM(slope);
	line3.setC(intercept);
	line3.printEquation();

	system("pause"); // ! remove this line if you are using Dev C++

	return 0;
}

Line::Line()
{
	m = c = 0;
}

Line::Line(double _m, double _c) : m(_m), c(_c)
{
}

Line::Line(double x1, double y1, double x2, double y2)
{
	m = (y2 - y1) / (x2 - x1);
	c = y1 - m * x1;
}

Line::~Line()
{
	cout << "The object is being destroyed" << endl;
}

double Line::getM() const
{
	return m;
}

double Line::getC() const
{
	return c;
}

void Line::setM(double value)
{
	m = value;
}

void Line::setC(double value)
{
	c = value;
}

void Line::printEquation() const
{
	if (c == 0)
		cout << "Eq.  y=" << m << "x" << endl;
	else if (c < 0)
		cout << "Eq.  y=" << m << "x" << c << endl;
	else
		cout << "Eq.  y=" << m << "x+" << c << endl;

	cout << endl;
}
