// Programming Technique II (SCSJ1023)
// Semester 1, 2018/2019

// ? Tutorial 2: Introduction to Classess and Objects
// ? Program 1: Defining classes and creating objects
//include "circle.hpp"
#include <graphics.h>

// * ---------------------------------------------------------------------------------------------
// * Task 1: Declare the class specification (prototype) for the class Circle
// * ---------------------------------------------------------------------------------------------
// ? Notes on terms: class specification = class prototype = class declaration
//  ?                which means, the code only specify the structure and member 
// ?                 function headers (i.e., without the body)
// * ---------------------------------------------------------------------------------------------

class Circle
{
  private:
int x,y;
int radius;
int color;

  public:
Circle(int _x, int _y, int _radius, int _color);

void setX(int value);
void setY(int value);
void setRadius (int value);
void setColor (int value);

int getX()const;
int getY() const;
int getRadius() const;
int getColor()const;

void draw() const;
void undraw() const;
void move (int dx, int dy);
};

// * ---------------------------------------------------------------------------------------------
// * Task 2: Define each Write the code for the implementation of each method of the class Cirlce
// * ---------------------------------------------------------------------------------------------
// ? Notes on terms: class implementation = class definition
//  ?                i.e. each member function (method) is given or defined with its body code
// 
// * Methods to be defined:
//    (a). a constructor
//    (b). an accessor (or a getter) for each member variable (attribute), e.g., getX(), getY(), etc
//    (c). a mutator (or a setter) for each member variable (attribute), e.g., setX(), setY(), etc
//    (d). methods that deal with display, e.g., draw() and undraw()
//
//  ? Notes: methods (d) are also classified as accessor methods as they only access or use 
//  ?        the attribute values, without changing anything.
//
//  ? Note that, an accessor method is not necessarily identified by its name with the prefix "get ". 
//  ? Thus, you may also find an accesor method with the name like draw(), area(), etc.
// * ---------------------------------------------------------------------------------------------

Circle::Circle(int _x, int _y, int _radius, int _color){

	x= _x;
	y= _y;
	radius = _radius;
	color = _color;
}

void Circle::setX(int value){
	 x = value; 
} 

int Circle::getX() const{
	 return x; 
}

void Circle::setY(int value){
	 y = value; 
}
  
int Circle::getY() const{ 
	return y; 
}

void Circle::setRadius(int value){
	 radius = value; 
} 

int Circle::getRadius() const{ 
	return radius;
}

void Circle::setColor(int value){ 
	color = value; 
} 

int Circle::getColor() const{ 
	return color; 
}
 
void Circle::draw() const{
    setcolor(color);
    circle(x,y,radius);
}
 
void Circle::undraw() const{
    setcolor(0);
    circle(x,y,radius);
}
void Circle::move (int dx, int dy){
	x = x + dx;
	y = y + dy;
}

int main()
{
	int screenWidth = getmaxwidth();
	int screenHeight = getmaxheight();
	initwindow(screenWidth, screenHeight, "Tutorial 1");

	// * ---------------------------------------------------------------------------------------------
	// * Task 3: Create a Circle object
	// * ---------------------------------------------------------------------------------------------

	// * ---------------------------------------------------------------------------------------------
	// * Task 3: Display the circle
	// * ---------------------------------------------------------------------------------------------
	Circle c(200, 200, 100, COLOR(0,0,255));
	c.draw();
 
	getch();  

	// * ---------------------------------------------------------------------------------------------
	// * Task 4: Clear the circle from the screen
	// * ---------------------------------------------------------------------------------------------
	
	
	getch();

	// * ---------------------------------------------------------------------------------------------
	// * Task 4: Animate the circle by moving it from the left side of the window to the right side border.
	// ? write the code inside the loop below
	// * ---------------------------------------------------------------------------------------------
	
	// * ---------------------------------------------------------------------------------------------
	// * Task 5: Add to your code so that, when the circle reaches the window borders (left or right),
	//           it will change its direction of movement.
	// ? write the code inside the loop below
	// * ---------------------------------------------------------------------------------------------
int dx; int dy;

while (!kbhit())
	{
	c.draw();
	delay(33);
	c.undraw();

	int curX= c.getX();
	curX =+50;
	c.setX(curX);
  

	if (curX > screenWidth){
		 dx = -dx;
		 dy = -dy;
	}
	
	getch();
	return 0;
}
}
