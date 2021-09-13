// Programming Technique II (SCSJ1023)
// Semester 1, 2018/2019

// ? Exercise 2: Class and Object Manipulations

#include <iostream>
#include <cmath>
using namespace std;
//-----------------------------------------------------------------------------------------------------------
// Class declaration
//-----------------------------------------------------------------------------------------------------------
class Circle
{
  private:
	double x, y, r;

  public:
	Circle(int _x = 0, int _y = 0, int _r = 0);
    double getX() const;
    double getY() const;
    double getR() const;
    void setX(double value);
    void setY(double value);
    void setR(double value);

};

//--------------------------------------------
// Function declaration
//--------------------------------------------



//--------------------------------------------
// The main function
//--------------------------------------------

int main()
{
	Circle firstCircle, secondCircle;

	// test with these user inputs:
	// 0 0 10   5 0 5              (overlap case)
	// 10 10 10   50 50 10         (non-overlap case)

	double x, y, r;

	cout << "Enter the center and radius of a circle (x y r) => ";
	cin >> x >> y >> r;

	cout << "Enter the center and radius of another circle (x y r) => ";
	cin >> x >> y >> r;

	cout << endl;

	cout << endl;

	system("pause");

	return 0;
}



//-------------------------------------------------------
// Class definition
//-------------------------------------------------------
Circle::Circle(int _x, int _y, int _r) : x(_x), y(_y), r(_r)
{}

double Circle::getX() const { return x; }
double Circle::getY() const { return y; }
double Circle::getR() const { return r; }

void Circle::setX(double value) { x = value; }
void Circle::setY(double value) { y = value; }
void Circle::setR(double value) { r = value; }

//-------------------------------------------------------
// Function definition
//-------------------------------------------------------
