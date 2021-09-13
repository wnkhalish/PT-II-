// Programming Technique II (SCSJ1023)
// Semester 1, 2018/2019

// ? This program shows how to determine whether two circles overlap using the procedural programming

#include <iostream>
#include <cmath>
using namespace std;

// distance: To calculate the distance between two circles using the pythagoras’ theorem
//           (x1, y1) and (x2,y2) are the center point of the two circles, respectively.

double distance(double x1, double y1, double x2, double y2)
{
	double dx = x2 - x1;
	double dy = y2 - y1;

	return sqrt(dx * dx + dy * dy);
}

// overlap: To determine whether two circles overlap by using their distance
//           (x1, y1, r1) and (x2,y2, r2) are the coordinates x and y of the center, the radius, r of the two circles, respectively.

bool overlap(double x1, double y1, double r1, double x2, double y2, double r2)
{
	double d = distance(x1, y1, x2, y2);
	return d <= (r1 + r2);

	// The last line is equivalent to the following
	//   if (d<=r(r1+r2) ) return true;
	//      else return false;
}

int main()
{
	// Here, we are going to test the function
	double x1, y1, r1;
	double x2, y2, r2;

	// test with these user -inputs:
	// 0 0 10   5 0 5              (overlap case)
	// 10 10 10   50 50 10         (non-overlap case)

	cout << "Enter the center and radius of a circle (x y r) => ";
	cin >> x1 >> y1 >> r1;
	cout << "Enter the center and radius of another circle (x y r) => ";
	cin >> x2 >> y2 >> r2;

	cout << endl;

	if ( overlap(x1,y1,r1,x2,y2,r2) )
		cout << "The circles overlap" << endl;
	else
		cout << "The circles do not overlap" << endl;
	cout << endl;


	system("pause");
	return 0;
}
