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

	void set(double _x, double _y, double _r);
	double operator- (Circle right); 
	double operator* (Circle right); 
//	friend bool overlap(Circle c1, Circle c2);   
	friend void inputCircle( Circle &c);
};

//--------------------------------------------
// Function declaration
//--------------------------------------------
bool overlap(Circle &c);
void inputCircle(Circle &c) {     
	cout<<c.x<< " " << c.y<< " "<<c.r<< " ";
} 

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
	inputCircle(firstCircle);
	
 
	cout << "Enter the center and radius of another circle (x y r) => ";
	inputCircle(secondCircle);
	
   if (firstCircle * secondCircle)         
   cout << "The circles overlap" << endl;
   
        
   else         
   cout << "The circles do not overlap" << endl;
  
   
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

void Circle::set(double _x, double _y, double _r) {    
 	x =_x;    
  	y =_y;    
   	r =_r; 
   	

// double Circle::operator- (Circle right) {     
// double dx = x - right.x;     
// double dy = y - right.y;     
// double dist = sqrt(dx*dx + dy*dy);     
// return dist;
  }
  
double Circle::operator* (Circle right) {     
 double dy = y + right.y;     
 double dx = x + right.x;     
 double dist = sqrt(dx*dx + dy*dy);     
 return dist <= (r + right.r);
  }
  
//-------------------------------------------------------
// Function definition
//-------------------------------------------------------
bool overlap(Circle c1, Circle c2) {     
double d = c1 - c2; 
return d <=(c1.r + c2.r); 
} 
