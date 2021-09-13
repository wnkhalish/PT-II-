// Programming Technique II (SCSJ1023)
// Semester 1, 2018/2019

// Exercise 1: Constructors and Desctructors

#include <iostream>
using namespace std;

// * ---------------------------------------------------------------------------------------------
// * Task 1: Declare and define the class Line
// * ---------------------------------------------------------------------------------------------
class Line
{
  private:
	double m;  // the slope of the line
	double c;  // the y-intercept
	double x1,y1,x2,y2;

  public:
  Line();//default constructor
  Line(double,double);//A constructor that accepts two parameters to set the attributes m and c, respectively
  Line(double,double,double,double);//A constructor that accepts four parameters which are x1, y1, x2, and y2, representing the coordinates x and y of two points that the line passes through
  double getm() const;//accessors
  double getc()const;

  void setm(double value);//mutators
  void setc(double value);

  double printEquation(double, double) const;

};

  Line::Line()
  {
	  m=c=x1=x2=y1=y2=0;
  }
  Line::Line(double _m,double _c)
  {
	  m=_m;
	  c=_c;
  }
  Line::Line(double _x1,double _y1,double _x2,double _y2)
  {
	  x1=_x1;
	  y1=_y1;
	  x2=_x2;
	  y2=_y2;
  }
  double Line::getm() const
  {
	  return m;
  }
  double Line::getc()const
  {
	  return c;
  }

  void Line::setm(double value)
  {
	  m=value;
  }
  void Line::setc(double value)
  {
	  c=value;
  }

  double Line::printEquation(double m, double c) const
  {
	  if (c == 0)
	  {
		  cout << "y= "<<m<<"x"<<endl;
	  }
	  if (c>0)
	  {
		  cout <<"y= "<<m<<"x +"<<c<<endl;
	  }
	  if (c<0)
	  {
		  cout << "y= "<<m<<"x-"<<c<<endl;
	  }
  }
int main()
{
	double slope, intercept;
	// * ---------------------------------------------------------------------------------------------
	// * Task 2: Create the object 'line1'
	// * ---------------------------------------------------------------------------------------------
	Line line1; 
	slope=2;
	intercept = -5;
	line1.printEquation(slope, intercept);


	// * ---------------------------------------------------------------------------------------------
	// * Task 3: Create the object 'line2'
	// * ---------------------------------------------------------------------------------------------
	Line line2(0,0,2,8);
	
	slope=8-2/0-0;
	intercept=0-(slope*0);
	line2.printEquation(slope,intercept);


	// * ---------------------------------------------------------------------------------------------
	// * Task 4: Create the object 'line3'
	// * ---------------------------------------------------------------------------------------------
	Line line3;
	//line 3.setM(slope);
	//line3.setC(intercept);
	//line3.printEquation();
	

	cout << "Enter the slope and y-intercept of the line  m  c => ";
	cin >> slope >> intercept;
	line3.printEquation(slope,intercept);

//line::~Line();

 // ! remove this line if you are using Dev C++

	return 0;
}
