// Programming Technique II (SCSJ1023)
// Semester 1, 2018/2019
// ? Tutorial 1: Procedural Programming (PP) vs. Object-Oriented Programming (OOP)
// ! Program 3: Using OOP

#include <graphics.h>
using namespace std;

// ! Task 1: Define a class to represent the structure of a circle.
// !         It consists of information the circle's radius, center, and color. And
// !         The operations that the circle should have

class Circle
{
  	public:
	int x,y,r,c;

Circle(int _x, int _y, int _r, int _c)
{
	x =_x;
	y =_y;
	r =_r;
	c= _c;
}
void draw()
{
	setcolor(c);
	circle(x,y,r);
}

void undraw()
{
	setcolor(0);
	circle(x,y,r);
}
};
int main()
{
	int screenWidth = getmaxwidth();
	int screenHeight = getmaxheight();
	initwindow(screenWidth, screenHeight, "Tutorial 1");

	// ! Task 2: Create a circle object
	int _x = 200, int _y = 500, int _r = 200, int _c = COLOR(0, 255, 0);
	
	
	// ! Task 3: Display the circle
	draw(int _x, int _y, int _r, int _c);
	getch();

	// ! Task 4: Animate the circle by moving it from the left side of the window to the right side border.

	while (!kbhit())
	{
		// ? your code for Task 4 goes here

	}

	getch();


	// ! Task 5: Add another circle and do the same as the first circle does, except the second circle starts from the right side and moves to the left
	// ! That means, you will have two circles that move in opposite directions

	while (!kbhit())
	{
		// ? your code for Task 5 goes here

	}

	getch();


	return 0;
}
