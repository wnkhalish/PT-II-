// Programming Technique II (SCSJ1023)
// Semester 1, 2018/2019

// ? Lab Exercise 4: Polymorphism
// Dec 2018

#include <graphics.h>
using namespace std;

// The class Geometry is given.

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
		virtual void scale(double factor) = 0;       
};

// Complete the class Circle including its relationship to class Geometry (refer to the class diagram)
class Circle : public Geometry{
	protected:
		int radius;

	public:
		Circle(int x=0, int y=0, int r=0, int c=WHITE) :Geometry(x,y,c), radius(r)
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
		
        void scale(double factor) { radius *= factor;}
		
};

// Complete the class Rectangle including its relationship to class Geometry (refer to the class diagram)
class Rect:public Geometry{
	protected:
		int width, length;  
	public:
		Rect(int x=0, int y=0, int w=0, int l=0, int c=WHITE):Geometry(x,y,c), width(w), length(l)
        {}
		
		void draw(){
			setfillstyle(SOLID_FILL,color);
            setcolor(color);
			bar(x, y, x+width, y + length );
		}
				
		void undraw(){
			setfillstyle(SOLID_FILL,BLACK);
            setcolor(BLACK);
			bar(x, y, x+width, y+length);
		}

        void scale(double factor) { width *= factor; length *= factor; }
};

// Complete the class Controller including its relationship to class Geometry (refer to the class diagram)
// The structure of the methods are given. Complete the code.

class Controller{
    
    protected:
        Geometry *object;

    public:
        Controller() : object(NULL){}
        void setObject(Geometry * _object) { object = _object;}

        // To change the color of the selected object 
        void changeObjectColor(int color)
        { 
          if (!object) return; 
          object->setColor(color);
          object->draw();
        }

        // To move selected object by dx and dy 
        void moveObject(int dx, int dy)
        { 
            if (!object) return; 
            
            object->undraw();
            object->move(dx, dy);
            object->draw();
        }

        // To enlarge the selected object by 10% (i.e. scale of 1.1)
        void enlargeObject()
        { 
            if (!object) return; 
            
            object->scale(1.1);
            object->draw();
        }

        // To shrink the selected object by 10% (i.e. scale of 0.9)
        void shrinkObject()
        { 
            if (!object) return; 
            
            object->undraw();
            object->scale(0.9);
            object->draw();
        }

};

int main( )
{
	int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();
    
	initwindow(screenWidth, screenHeight, "Lab Exercise 4: polymorphism");
	
    // Two geometrical objects have been created, a circle, c and rectangle,r, respectively
    // A controller object has also been created below.

	Controller ctrl;
    Circle c(100,100,100);
	Rect r(200,200,300,400);

	c.draw();
	r.draw();

	char ch;  // key pressed by the user

    while (true){  
		
        ch = 0;

        if ( kbhit() ){
            ch = getch();
            ch = toupper(ch);
            if (ch==27) break;  // 27 is Esc key - to terminate the program
            if (ch==0) ch = getch(); // for arrow keys need twice getch()
        }

		// The code structure for menu-driven interaction has been provided.
        // Complete the "cases" accordingly.

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

            case 75:  // To move the selected object to the left by 10 pixels
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
