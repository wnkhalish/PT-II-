// Programming Technique II (SCSJ1023)
// Semester 1, 2018/2019
// ? Tutorial 1: Procedural Programming (PP) vs. Object-Oriented Programming (OOP)
// ! Program 2: Using PP with struct

#include <graphics.h>
using namespace std;

// ! Task 1: Define a struct data type to hold information about a circle, i.e., center, and color
struct Circle{
	int x,y,r,c;
};

// ! Task 2: Define a function to draw a circle on the screen

void drawCircle(Circle aCircle)
{
	setcolor(aCircle.c);
	circle(aCircle.x, aCircle.y, aCircle.r);
}

// ! Task 3: Define a function to clear or undraw a circle from the screen
void undrawCircle(Circle aCircle)
{
	setcolor(0);
	circle(aCircle.x, aCircle.y, aCircle.r);
}

int main()
{
	int screenWidth = getmaxwidth();
	int screenHeight = getmaxheight();
	initwindow(screenWidth, screenHeight, "Tutorial 1");

	// ! Task 4: Define a circle with specified information from the struct data type
	Circle circ;
	circ.x = 200, circ.y = 500, circ.r = 200, circ.c = COLOR(0, 255, 0);
	
	// ! Task 5: Display the circle
	drawCircle(circ);
	getch();

	// ! Task 6: Animate the circle by moving it from the left side of the window to the right side border.

	while (!kbhit())
	{
	drawCircle(circ);
	delay(200);
	undrawCircle(circ);
	circ.x = circ.x + 50;	// ? your code for Task 6 goes here
	}

	getch();
	return 0;
}
