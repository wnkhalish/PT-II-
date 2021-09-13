// Programming Technique II (SCSJ1023)
// Semester 1, 2018/2019

// ? Tutorial 3: Class and Object Manipulations

#include <iostream>
#include <cmath>
using namespace std;
//-------------------------------------------------------
// Class declaration
//-------------------------------------------------------
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

	void set(double _x, double _y, double _r);

	double operator-(Circle right);
	double operator*(Circle right);

	friend bool overlap(Circle c1, Circle c2); // This is not a member to the class but a regular function. However
											   //  it has direct accesses to the private members as it is delcared
											   //  as a friend to the class.

	friend void inputCircle(Circle &c);
};

//-------------------------------------------------------
// The main function
//-------------------------------------------------------

int main()
{
	// Here, we are going to test the class
	Circle firstCircle, secondCircle;

	// test with these user -inputs:
	// 0 0 10   5 0 5              (overlap case)
	// 10 10 10   50 50 10         (non-overlap case)

	double x, y, r;

	cout << "Enter the center and radius of a circle (x y r) => ";
	inputCircle(firstCircle);

	cout << "Enter the center and radius of another circle (x y r) => ";
	inputCircle(secondCircle);

	cout << endl;

	if (firstCircle * secondCircle)
		cout << "The circles overlap" << endl;
	else
		cout << "The circles do not overlap" << endl;
	cout << endl;

	system("pause");
	return 0;

	return 0;
}

//-------------------------------------------------------
// Class definition
//-------------------------------------------------------

Circle::Circle(int _x, int _y, int _r) : x(_x), y(_y), r(_r)
{
}

double Circle::getX() const { return x; }
double Circle::getY() const { return y; }
double Circle::getR() const { return r; }

void Circle::setX(double value) { x = value; }
void Circle::setY(double value) { y = value; }
void Circle::setR(double value) { r = value; }
void Circle::set(double _x, double _y, double _r)
{
	x = _x;
	y = _y;
	r = _r;
}

double Circle::operator-(Circle right)
{
	double dx = x - right.x;
	double dy = y - right.y;
	double dist = sqrt(dx * dx + dy * dy);

	return dist;
}

double Circle::operator*(Circle right)
{
	double dx = x - right.x;
	double dy = y - right.y;
	double d = sqrt(dx * dx + dy * dy);

	return d <= (r + right.r);
}

//-------------------------------------------------------
// Function definition
//-------------------------------------------------------
bool overlap(Circle c1, Circle c2)
{
	double d = c1 - c2; // The overloaded operator minus is invoked here
						//  To get the distance between the circles.

	return d <= (c1.r + c2.r); // c1 and c2 are able to access directly to the private member r,
							   // as the function 'overlap' has been declared as a friend to class 'Circle'
}

void inputCircle(Circle &c)
{
	cin >> c.x >> c.y >> c.r;
}
