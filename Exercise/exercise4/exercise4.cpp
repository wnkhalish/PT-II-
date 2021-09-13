// Programming Technique II (SCSJ1023)
// Semester 1, 2018/2019

// ? Lab Exercise 4: Polymorphism
// Dec 2018

#include <graphics.h>
using namespace std;

//-------------------------------------------------------------------------------------------
// The class Geometry is given. Do nothing on this class
//-------------------------------------------------------------------------------------------

class Geometry{
	protected:
        int x, y;
        int color;

    public:
		Geometry(int _x=0, int _y=0, int _color=WHITE):x(_x), y(_y), color(_color)
        {}

        void setColor(int c){color=c;}
        void move(int dx, int dy)
        {   x += dx;
            y += dy;
        }

        virtual void draw()= 0;
		virtual void undraw()=0;
		virtual void scale(double factor) = 0;  // To change the size of the object
};

//-------------------------------------------------------------------------------------------
// Task 1
// Complete the class Circle including its relationship to class Geometry (refer to the class diagram)
// The draw and undraw methods are given (you need to uncomment the lines).
// Complete the remaining methods including the Constructor.
//-------------------------------------------------------------------------------------------
class Circle:public Geometry{
	protected:
		int radius;

	public:
		Circle(int x=0, int y=0, int r=0, int c=WHITE):Geometry(x,y,c),radius(r)
        {}

		void draw(){
            setfillstyle(SOLID_FILL,color);
            setcolor(color);
			fillellipse(x,y,radius,radius);
		}

		void undraw(){
             setfillstyle(SOLID_FILL,BLACK);
             setcolor(BLACK);
			 fillellipse(x,y,radius,radius);
		}

        // complete the code for the method scale which changes the radius of the circle
        void scale(double factor) {
            radius = radius * factor;

        }

};

//-------------------------------------------------------------------------------------------
// Task 2
// Complete the class Rect including its relationship to class Geometry (refer to the class diagram)
// The draw and undraw methods are given (you need to uncomment the lines).
// Complete the remaining methods including the Constructor.
//-------------------------------------------------------------------------------------------
class Rect:public Geometry {
	protected:
		int width, length;

	public:
		Rect(int x=0, int y=0, int w=0, int l=0, int c=WHITE): Geometry(x,y,c), width(w), length(l) { 
           width = w; 
           length = l; 
        }

		void draw(){
			 setfillstyle(SOLID_FILL,color);
             setcolor(color);
			 bar(x, y,  x + width, y + length);
		}

		void undraw(){
			setfillstyle(SOLID_FILL,BLACK);
             setcolor(BLACK);
			 bar(x, y, x + width, y + length );
		}

        // complete the code for the method scale which change the width and length of the rectangle
        void scale(double factor)  {
           width =  width * factor;
           length = length * factor;
        }

};

//-------------------------------------------------------------------------------------------
// Task 3
// Complete the class Controller including its relationship to class Geometry (refer to the class diagram)
// The header of each method (except setObject) is given. Complete the code of the body.
//-------------------------------------------------------------------------------------------

class Controller{

    protected:
     Geometry *g;
     
    public:
        Controller() { 
            g = NULL;
        }
        void setObject(Geometry *geo) {  // You need to determine the parameter for this method by yourself
            g = geo;
        }

        // To change the color of the selected object
        void changeObjectColor(int color) { 
            if(g!=NULL) { 
               g-> undraw(); 
               g-> setColor(color);
               g-> draw();
            }
        }

        // To move selected object by dx and dy
        void moveObject(int dx, int dy) { 
            if(g!=NULL) { 
               g-> undraw(); 
               g-> move(dx,dy);
               g-> draw();
            }
        }

        // To enlarge the selected object by 10% (i.e. scale of 1.1)
        void enlargeObject() { 
             if(g!=NULL) { 
               g-> undraw(); 
               g-> scale(1.1);
               g-> draw ();
            }
        }

        // To shrink the selected object by 10% (i.e. scale of 0.9)
        void shrinkObject() { 
              if(g!=NULL) { 
               g->undraw(); 
               g->scale(0.9);
               g->draw();
            }
        }

};

//-------------------------------------------------------------------------------------------
// Task 4
// Complete the code for the main function.
// Focus on the code for each "case".
//-------------------------------------------------------------------------------------------

int main( ) {
	int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();

	initwindow(screenWidth, screenHeight, "Lab Exercise 4: polymorphism");

    // Two geometrical objects have been created, a circle, c and rectangle,r, respectively
    // A controller object, ctrl, has also been created below.

	Controller ctrl;
    Circle c(100,100,100);
	Rect r(200,200,300,400);

	c.draw();
	r.draw();

	char ch;  // key pressed by the user

    while (true) {
        ch = 0;
        if ( kbhit()) {
            ch = getch();
            ch = toupper(ch);
            if (ch==27) break;  // 27 is Esc key - to terminate the program
            if (ch==0) ch = getch(); // for arrow keys need twice getch()
        }

		// The code structure for menu-driven interaction has been provided.
        // Complete each "case" accordingly.

        switch(ch){
            case 'C': // To choose the circle, c 
            ctrl.setObject(&c);
            break;

            case 'R': // To choose the rectangle, r 
            ctrl.setObject(&r);
            break;

            case 'B':  // To change the color of the selected object to BLUE
            ctrl.changeObjectColor(BLUE);
            break;

            case 'Y':  // To change the color of the selected object to YELLOW 
            ctrl.changeObjectColor(YELLOW);
            break;

            case 'L':  // To enlarge the selected object 
            ctrl.enlargeObject();
            break;

            case 'S':  // To shrink the selected object 
            ctrl.shrinkObject();
            break;

            case 75:   // To move the selected object to the left by 10 pixels 
            ctrl.moveObject(-10,0);
            break;

            case 77:  // To move the selected object to the right by 10 pixels 
            ctrl.moveObject(10,0);
            break;

            case 80:  // To move down the selected object by 10 pixels 
            ctrl.moveObject(0,10);
            break;

            case 72:  // To move up the selected object by 10 pixels 
            ctrl.moveObject(0,-10);
            break;
        }
    }

    return 0;
}
