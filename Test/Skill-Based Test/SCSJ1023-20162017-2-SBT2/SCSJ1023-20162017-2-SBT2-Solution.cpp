////////////////////////////////////////////////////////////////////////////////
// Faculty of Computing, Universiti Teknologi Malaysia
// SCSJ1023- Programming Technique II
// Semester 2, 2016/2017
// Skill-based Test 2
// 3rd May 2017
// Solution
////////////////////////////////////////////////////////////////////////////////
// Test run start: 11:14

#include<iostream>
using namespace std;

class Point{
	private:
		int x, y;
	public:
		Point (int _x, int _y)
		{ x = _x; y = _y; }

		Point (const Point &p)
		{ x = p.x; y=p.y;}
		
		Point operator+(Point p)
		{	Point r( x + p.x, y+p.y);
			return r;}
			
		void display() const
		{ cout << "x= " << x << "\t" << "y=" << y << endl;
		}

		void display(string title) const
		{ cout << title << ": x= " << x << "\t" << "y=" << y << endl;
		}
		
		friend double slope (const Point &a, const Point &b);
};

double slope (const Point &a, const Point &b)
{
	return (b.y-a.y) / (b.x-a.x);
}

// 11:21

int main()
{
	Point a(1,2), b(3,4);
	Point c = a + b;
	a.display();
	b.display();
	c.display("Third Point");
	cout << "Slope = " << slope(a,b) << endl;
	return 0;
}

// 11:23
