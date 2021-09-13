#include <graphics.h>


	Alphabet::Alphabet(int _x, int _y, int _w, int _h , int _colorOutline, int _colorFill)	{
		x = _x;
		y = _y;
		w = _w;
		h = _h;
		colorOutline = _colorOutline;
		colorFill = _colorFill;
	}

	void Alphabet::setAlpha(char value) {
		alphabet = value;
	}
	char Alphabet::getAlpha()const {
		return alphabet;
	}
	void Alphabet::showAlpha()const {
	char a[2];
	a[0] = alphabet;
	a[1] = 0 ;
	setbkcolor(BLACK);
	setcolor(WHITE);
	settextjustify(0,2);
	settextstyle(10, HORIZ_DIR, 6);
	outtextxy( x +15, y - 15, a);

	}
	void Alphabet::init(int dist) {
		alphabet = 'A' + rand () % 25;
		boxColor = rand() % 13 +1;
		speed = rand() % 20 +5;
	}
	// Mutators
	void Alphabet::setX(int _x) { x = _x; }
	void Alphabet::setY(int _y) { y = _y; }
	void Alphabet::setTopLeft(int _x, int _y) {	x = _x;	y = _y;	}
	
	void Alphabet::setW(int _w) { w = _w; }
	void Alphabet::setH(int _h) { h = _h; }
	void Alphabet::setDimension(int _w, int _h) { w = _w; h = _h; }

	void Alphabet::setOutlineColor(int _colorOutline) { 
		colorOutline = _colorOutline; 
	}
	void Alphabet::setFillColor(int _colorFill) { 
		colorFill = _colorFill; 
	}
	void Alphabet::setColor(int _colorOutline, int _colorFill) { 
		colorOutline = _colorOutline, colorFill = _colorFill; 
	}

	// Accessors
	int Alphabet::getX() const { return x; }
	int Alphabet::getY() const { return y; }
	int Alphabet::getW() const { return w; }
	int Alphabet::getH() const { return h; }

	int Alphabet::getOutlineColor() const { return colorOutline; }
	int Alphabet::getFillColor() const { return colorFill; 	}
	int Alphabet::getMaxX() const { return x + w; }
	int Alphabet::getMaxY() const { return y + h; }

	void Alphabet:: draw() const {
		setcolor(colorOutline);
		setfillstyle(SOLID_FILL, colorFill);
		
		bar(x, y, x + w, y + h);
		
		char a[2]={alphabet, 0};
	
		setcolor(WHITE);
		setbkcolor(colorFill);
		settextjustify(0,2);
		settextstyle(10, HORIZ_DIR, 6);
		outtextxy( x + 30, y + 30, a);		
	}

	void Alphabet:: undraw() const{
		setcolor(0);
		setfillstyle(SOLID_FILL, 0);
		bar(x, y, x + SIZE, y + SIZE);
	}
	void Alphabet::move(int dx, int dy) {
		draw();	
		delay(100);
		undraw();
		x += dx;
		y += dy;
	}

