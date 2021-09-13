// Programming Technique II (SCSJ1023)
// Semester 1, 2018/2019

// Exercise 1: Constructors and Desctructors

#include <iostream>
using namespace std;

// * ---------------------------------------------------------------------------------------------
// * Task 1: Declare and define the class Date
// * ---------------------------------------------------------------------------------------------

class Date
{
  private:
	int day, month, year;

  public:
	Date();
	Date(int, int, int);
	~Date();

	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void print() const;
};

int main()
{
	// * ---------------------------------------------------------------------------------------------
	// * Task 2: Create a Date object for today's date
	// * ---------------------------------------------------------------------------------------------
	Date today(9, 9, 2018);
	today.print();

	// * ---------------------------------------------------------------------------------------------
	// * Task 3: Create a Date object for tomorrow's date
	// * ---------------------------------------------------------------------------------------------
	Date tomorrow(10,9,18);  // year must be set as 18 (not 2018)
	tomorrow.print();        // the output must be  10-9-2018  (not 10-9-18)

	// * ---------------------------------------------------------------------------------------------
	// * Task 4: Another Date object named 'anotherDay'
	// * ---------------------------------------------------------------------------------------------

	Date anotherDay;
	int d,m,y;
	cout << "Enter the the date (day month year)  => ";
	cin >> d >> m >> y;

	anotherDay.setDay(d);
	anotherDay.setMonth(m);
	anotherDay.setYear(y);
	anotherDay.print();

	system("pause"); // ! remove this line if you are using Dev C++

	return 0;
}

Date::Date() : Date(1, 1, 0)
{}

Date::Date(int d, int m, int y) : day(d), month(m)
{
	setYear(y);
}

Date::~Date()
{
	cout << "The destructor is invoked" << endl;
}

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }
void Date::setDay(int value) { day = value; }
void Date::setMonth(int value) { month = value; }
void Date::setYear(int value)
{
	// if the it is a 2-digit value, the year can be 19XX or 20XX
	if (value <= 18)
		year = 2000 + value;
	else if (value <= 99)
		year = 1900 + value;
	else
		year = value; // otherwise, consider it as a 4-digit year. Thus, take it as is
}

// The code for this method is given
void Date::print() const
{
	cout << "The date is " << day << "-" << month << "-" << year << endl << endl;
}

