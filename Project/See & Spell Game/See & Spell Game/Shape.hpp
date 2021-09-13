#ifndef SHAPE_H
#define SHAPE_H

#define SIZE 80

using namespace std;

class Shape
{
protected:
    int x, y, colorOutline, colorFill;
    int dx, dy;

public:
    Shape(int _x = 0, int _y = 0, int _colorOutline = 0, int _colorFill = 0)
    {
        x = _x;
        y = _y;
        colorOutline = _colorOutline;
        colorFill = _colorFill;
    }
    void setX(int _x)
    {
        x = _x;
    }
    void setY(int _y)
    {
        y = _y;
    }

    int getX() const
    {
        return x;
    }
    int getY() const
    {
        return y;
    }

    void setOutlineColor(int _colorOutline)
    {
        colorOutline = _colorOutline;
    }
    void setFillColor(int _colorFill)
    {
        colorFill = _colorFill;
    }
    void setColor(int _colorOutline, int _colorFill)
    {
        colorOutline = _colorOutline, colorFill = _colorFill;
    }

    virtual void draw()
    {
    }
    virtual void undraw()
    {
    }
    virtual void move(int dx, int dy)
    {
    }
};

class Box : public Shape
{
public:
    Box(int _x = 0, int _y = 0)
    {
        x = _x;
        y = _y;
    }

    void draw()
    {
        setfillstyle(SOLID_FILL, colorFill);
        bar(x, y, x + 100, y + 20);
    }
    void undraw()
    {
        setfillstyle(SOLID_FILL, BLACK);
        bar(x, y, x + 100, y + 20);
    }
    void move(char key)
    {
        if (key == 0)
        {
            key = getch();
            switch (key)
            {
                case 77:
                    moveRight();
                    break;
                case 75:
                    moveLeft();
                    break;
            }
        }
    }
    void moveRight()
    {
        undraw();
        if (x < 730)
        {
            x = x + 50;
        }
        draw();
    }
    void moveLeft()
    {
        undraw();
        if (x > 0)
        {
            x = x - 50;
        }
        draw();
    }
};


class Alphabet : public Shape
{
protected:
    int x2, y2;
    char alphabet;

    int boxColor;

    int speed;

    Box b;

public:
    Alphabet(int _x = 0, int _y = 0, int _x2 = 0, int _y2 = 0)
    {
        setTopLeft(_x, _y);
        setBottomRight(_x2, _y2);
    }
    void setTopLeft(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    void setBottomRight(int _x2, int _y2)
    {
        x2 = _x2;
        y2 = _y2;
    }

    int getTop() const
    {
        return y;
    }
    int getLeft() const
    {
        return x;
    }
    int getBottom() const
    {
        return y2;
    }
    int getRight() const
    {
        return x2;
    }


    void setAlpha(char value)
    {
        alphabet = value;
    }
    char getAlpha() const
    {
        return alphabet;
    }
    void showAlpha() const
    {
        char a[2];
        a[0] = alphabet;
        a[1] = 0;
        setbkcolor(BLACK);
        setcolor(WHITE);
        settextjustify(0, 2);
        settextstyle(10, HORIZ_DIR, 6);
        outtextxy(x + 15, y - 15, a);
    }
    void init(int dist)
    {
        alphabet = 'A' + rand() % 25;
        boxColor = rand() % 13 + 1;
        speed = rand() % 20 + 5;
    }
    void draw()
    {
        setcolor(colorOutline);
        setfillstyle(SOLID_FILL, colorFill);

        bar(x, y, x + SIZE, y + SIZE);

        char a[2] = { alphabet, 0 };

        setcolor(WHITE);
        setbkcolor(colorFill);
        settextjustify(0, 2);
        settextstyle(10, HORIZ_DIR, 6);
        outtextxy(x + 19, y + 19, a);
    }

    void undraw()
    {
        setcolor(0);
        setfillstyle(SOLID_FILL, 0);
        bar(x, y, x + SIZE, y + SIZE);
    }
    void move()
    {
        undraw();
        y += 10;
        y2 += 10;
        draw();

        if (y == 750)
        {
            positionDrop();
        }
    }
    void positionDrop()
    {
        y = 0;
        y2 = 50;
        srand(time(NULL));
        int i = rand() % 7;
        switch (i)
        {
            case 0:
                x = 150;
                x2 = 100;
                break;
            case 1:
                x = 250;
                x2 = 200;
                break;
            case 2:
                x = 350;
                x2 = 300;
                break;
            case 3:
                x = 450;
                x2 = 400;
                break;
            case 4:
                x = 550;
                x2 = 500;
                break;
            case 5:
                x = 650;
                x2 = 600;
                break;
            case 6:
                x = 750;
                x2 = 700;
                break;
        }
    }
};
class Bomb : public Alphabet
{
protected:
    int r;

public:
    Bomb(int _x = 0, int _y = 0, int _r = 0)
    {
        x = _x;
        y = _y;
        r = _r;
    }
    void setCenter(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    void setRadius(int _r)
    {
        r = _r;
    }
    int getX() const
    {
        return x;
    }
    int getY() const
    {
        return y;
    }
    int getRadius() const
    {
        return r;
    }

    void draw()
    {
        setfillstyle(SOLID_FILL, colorFill);
        setcolor(colorOutline);
        circle(x, y, r);
        floodfill(x + 10, y + 10, colorOutline);

        setcolor(colorOutline);
        setfillstyle(SOLID_FILL, colorFill);

        char a[2] = { alphabet, 0 };

        setcolor(BLACK);
        setbkcolor(colorFill);
        settextjustify(0, 2);
        settextstyle(10, HORIZ_DIR, 5);
        outtextxy(x - 13, y - 13, a);
    }

    void undraw()
    {
        setcolor(0);
        setfillstyle(SOLID_FILL, 0);
        circle(x, y, r);
        floodfill(x - 10, y - 10, 0);
    }
    void move()
    {
        undraw();
        y += 10;
        draw();

        if (y == 750)
        {
            positionDrop();
        }
    }
    void positionDrop()
    {
        y = 0;
        srand(time(NULL));
        int i = rand() % 7;
        switch (i)
        {
            case 0:
                x = 275;
                break;
            case 1:
                x = 375;
                break;
            case 2:
                x = 475;
                break;
            case 3:
                x = 575;
                break;
            case 4:
                x = 675;
                break;
            case 5:
                x = 775;
                break;
            case 6:
                x = 875;
                break;
        }
    }
};

#endif
