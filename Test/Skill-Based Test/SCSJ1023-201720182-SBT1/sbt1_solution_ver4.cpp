////////////////////////////////////////////////////////////////////////////////
// Faculty of Computing, Universiti Teknologi Malaysia
// SCSJ1023- Programming Technique II
// Semester 2, 2017/2018
// Skill-based Test 1
// March 11, 2018
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cmath>
using namespace std;

// Task 1: Complete the definition of class Date.
class Date 
{
	private: 
		string desc;
		int month, day, year; //2M
	
	public:	
		Date(string = "", int = 0, int = 0, int = 0);
		
		int getYear() const  {return year;} //Accessors = 6M
		int getMonth() const {return month;}
		int getDay() const {return day;}
		
		Date operator- (Date right);
		
		friend ostream & operator<< (ostream &, const Date &);	
		friend istream & operator>> (istream &, Date &);
};

//A constructor with default arguments = 6M
Date::Date(string ds, int d, int m, int y) //2 
{
	desc = ds;
	day = d;
	month = m;
	year = y; //4
}

//An overloaded operator- = 6M
Date Date::operator- (Date right) //2 
{
	Date difDate; //0.5
	difDate.year = abs(year - right.year);    //1		
	difDate.month = abs(month - right.month); //1
	difDate.day = abs(day - right.day);       //1
	
	return difDate;	 //0.5				
}

//Overloaded operator>> = 3M
// complete the definition for this operator to read input (day, month, year) from the keyboard
istream & operator>> (istream &inp, Date &obj) 
{
	cout << "Enter your date (day, month, year): ";
	cin >> obj.day >> obj.month >> obj.year; //3
			
	return inp; 
}	

//Overloaded operator<< = 4M	
// Complete the definition for this operator to print the date onto the screen

ostream & operator<< (ostream &out, const Date &obj) 
{
	out << obj.desc << ": " << obj.day << "-" 
		<< obj.month << "-" << obj.year; //4
			
	return out; 
}


// Task 2: The following function is partialy given. 
// The function is meant to print the difference between two dates specified in d.
// Complete the code of the function (5M)

void displayDiff(Date d) 
{
	cout << "The difference: ";
	if (d.getYear() > 0) //5
		cout << d.getYear() << " year(s)" << endl;
	else
	if (d.getMonth() > 0)
		cout << d.getMonth() << " month(s)" << endl;
	else
		cout << d.getDay() << " day(s)" << endl;
	cout << endl;	
}


int main()
{
	// Task 3: Create an array to hold three(3) dates and initialize 
	// the description of each date with specified values.
	Date dates[3] = {Date("SBT"), Date("Test"), Date("Final")}; //4M
	
	
	// Task 4: Using a loop and an appropriate functions(s), enter the values
	// of day, month and year from the keyboard for the array
	for (int i = 0; i < 3; i++) // 1m
		cin >> dates[i]; //2m	
	
	
	// Task 5: Create two objects named date1 and date2 with the specified data.
	Date date1("TODAY", 5, 3, 2018);  // 2m
	Date date2("Date of birth", 23, 11, 1999); //2m
	
	
	// Task 6: Using an appropriate function and another loop, print all the dates 
	// and the difference between date1 and other dates (7M)
	cout << endl << date1 << endl << endl;
	cout << date2 << endl; //1.5
	displayDiff(date1 - date2); //1.5
	
	for (int i = 0; i < 3; i++) // 1m
	{
		cout << dates[i] << endl; //1.5
		displayDiff(date1-dates[i]); //1.5
	}
		
	return 0;
}
