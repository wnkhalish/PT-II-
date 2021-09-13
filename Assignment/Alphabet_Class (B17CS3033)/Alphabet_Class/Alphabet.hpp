#ifndef ALPHABET_H
#define ALPHABET_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <graphics.h>
#include <string>

using namespace std;
//-----------------------------------------------------------------------------------------------------------
// Class declaration
//-----------------------------------------------------------------------------------------------------------
#define SIZE 100

class Alphabet { 
	int x, y,w,h;
	char alphabet;
	
	int colorOutline;
	int colorFill;
	int boxColor;
	
	int speed;

	//void* snapBackground;

  public:
  	
	// Constructor
	Alphabet(int _x = 0, int _y = 0, int _w = 0, int _h = 0, int _colorOutline = WHITE, int _colorFill = BLACK)	{
		x = _x;
		y = _y;
		w = _w;
		h = _h;
		colorOutline = _colorOutline;
		colorFill = _colorFill;
	//int imageLength = w*h;   
	//int size = imagesize(0, 0, imageLength, imageLength);  
	//snapBackground = new char[size]; }
	//~Alphabet(){
	//delete [] snapBackground; 
	}
	void setAlpha(char value) {
		alphabet = value;
	}
	char getAlpha()const {
		return alphabet;
	}
	void showAlpha()const {
	char a[2];
	a[0] = alphabet;
	a[1] = 0 ;
	setbkcolor(BLACK);
	setcolor(WHITE);
	settextjustify(0,2);
	settextstyle(10, HORIZ_DIR, 6);
	outtextxy( x +15, y - 15, a);
	//getimage(x-w,y-h,x+w,y+h, snapBackground);
	}
	void init(int dist) {
		alphabet = 'A' + rand () % 25;
		boxColor = rand() % 13 +1;
		speed = rand() % 20 +5;
	}
	// Mutators
	void setX(int _x) {
		 x = _x; 
	}
	void setY(int _y) { 
		y = _y; 
	}
	void setTopLeft(int _x, int _y) {
		x = _x;
		y = _y;
	}
	void setW(int _w) { 
		w = _w; 
	}
	void setH(int _h) { 
		h = _h; 
	}
	void setDimension(int _w, int _h) {
		w = _w; h = _h;
	}

	void setOutlineColor(int _colorOutline) { 
		colorOutline = _colorOutline; 
	}
	void setFillColor(int _colorFill) { 
		colorFill = _colorFill; 
	}
	void setColor(int _colorOutline, int _colorFill) { 
		colorOutline = _colorOutline, colorFill = _colorFill; 
	}

	// Accessors
	int getX() const { 
		return x; 
	}
	int getY() const { 
		return y; 
	}
	int getW() const { return w; }
	int getH() const { return h; }

	int getOutlineColor() const { 
		return colorOutline; 
	}
	int getFillColor() const { 
		return colorFill; 
	}
	int getMaxX() const { 
		return x + w; 
	}
	int getMaxY() const { 
		return y + h; 
	}

	void draw() const {
		setcolor(colorOutline);
		setfillstyle(SOLID_FILL, colorFill);
		
		bar(x, y, x + w, y + h);
		//getimage(x-w,y-h,x+w,y+h, snapBackground);
		
		char a[2]={alphabet, 0};
	
		setcolor(WHITE);
		setbkcolor(colorFill);
		settextjustify(0,2);
		settextstyle(10, HORIZ_DIR, 6);
		outtextxy( x + 30, y + 30, a);	
			
	}

	void undraw(int color =0) const {
		setcolor(color);
		setfillstyle(SOLID_FILL, color);
		bar(x, y, x + SIZE, y + SIZE);
		//putimage(x-w,y-w,snapBackground,COPY_PUT);
	}
	void move(int dx, int dy) {
		undraw();
		x += dx + 50;
		y += dy + 50;
		draw();
		delay(50);
	}
};

#endif