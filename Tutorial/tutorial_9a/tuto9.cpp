// SCSJ1023, Programming Technique II
// Semester 1, 2018/2019
// Tutorial 9a (Polymorphism and Dynamic Allocated Objects)
// Nov 2018

#include <iostream>
#include <graphics.h>

using namespace std;

// The definition for the class Geometry, Circle and Rect are given. However, you may want to add other methods if necessary

class Geometry
{   // Notes: Geometry becomes an "Abstract base" class, as it contains "pure" virtual methods.
	//   Please consult the lecture slide for details
  public:
	Geometry() {}

	virtual void draw() = 0; // This is how to define a pure virtual function
	virtual void undraw() = 0;
	virtual void move(int dx, int dy) = 0;
	virtual void input() = 0;
};

class Circle : public Geometry
{
  protected:
	int x, y, r;

  public:
	Circle(int _x = 0, int _y = 0, int _r = 0)
	{
		x = _x;
		y = _y;
		r = _r;
	}

	void draw()
	{
		setcolor(WHITE);
		circle(x, y, r);
	}

	void undraw()
	{
		setcolor(BLACK);
		circle(x, y, r);
	}

	void move(int dx, int dy)
	{
		x += dx;
		y += dy;
	}

	void input()
	{
		cout << "enter circle data (x  y  r) =>";
		cin >> x >> y >> r;
	}
};

class Rect : public Geometry
{
  protected:
	int x1, y1; // top left corner
	int x2, y2; // bottom right corner
  public:
	Rect(int _x1 = 0, int _y1 = 0, int _x2 = 0, int _y2 = 0)
	{
		x1 = _x1;
		y1 = _y1;
		x2 = _x2;
		y2 = _y2;
	}

	void draw()
	{
		setcolor(WHITE);
		rectangle(x1, y1, x2, y2);
	}

	void undraw()
	{
		setcolor(BLACK);
		rectangle(x1, y1, x2, y2);
	}

	void move(int dx, int dy)
	{
		x1 += dx;
		y1 += dy;
		x2 += dx;
		y2 += dy;

	}
	void input()
	{
		cout << "enter a rectangle data  =>";
		cin >> x1 >> y1 >> x2>> y2;
	}
};

int menu()
{
	cout << "=========== Operations =========" << endl;
	cout << "1. Add a circle to the list" << endl;
	cout << "2. Add a rectangle to the list" << endl;
	cout << "3. Display the list" << endl;
	cout << "4. Move the positions of the objects" << endl;
	cout << "5. Exit" << endl;
	cout << endl;
	cout << "Enter the operation to perform => ";

	int operation;
	cin >> operation;

	cout << endl
		 << endl;

	return operation;
}

int main()
{
	int graphic_window_width = getmaxwidth() / 2;
	int graphic_window_height = getmaxheight() / 2;

	initwindow(graphic_window_width, graphic_window_height, "Tutorial 7: polymorphism and dynamic objects");

	Geometry *objects[50];
	int nObject = 0;

	int choice = menu();

	// ************** Complete the rest of the main function ****************
	//  Please consider to use the following code construct:
	//    a. loop
	//    b. switch-case

	while (choice != 5)
	{

		switch (choice)
		{
		case 1:
		

			objects[nObject] = new Circle();
			objects[nObject]->input();
			nObject++;

			break;

		case 2:
			Rect *r;
			r = new Rect();
			r->input();

			objects[nObject] = r;
			nObject++;
			break;
		case 3:
			for (int i = 0; i < nObject; i++)
			{
				objects[i]->draw();
			}

			break;

		case 4:

		for(int i=0;i<nObject;i++ )	
		{
			objects[i]->undraw();
			objects[i]->move(100,50);
			objects[i]->draw();
			
		}	
			break;

		case 5:
			return -1;
			break;
		}

		choice = menu();
	}

	return 0;
}
