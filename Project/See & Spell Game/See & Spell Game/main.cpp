#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <graphics.h>
#include <windows.h>
#include <ctime>

#include "Shape.hpp"
#include "Score.hpp"

using namespace std;
void mainScreen();
void endScreen();

int main()
{
    int screenWidth = getmaxwidth();
    int screenHeight = getmaxheight();
    initwindow(screenWidth, screenHeight, "See and Spell Game");

    mainScreen();

    string imageFile = "fox.jpg";

    int imageWidth = 262;
    int imageHeight = 263;

    int x = screenWidth / 1.35;
    int y = screenHeight / 3.0;
    int dy = 50;

    readimagefile(imageFile.c_str(), x, y, x + imageWidth, y + imageHeight);

    delay(100);
    setbkcolor(BLACK);
    setcolor(WHITE);
    settextstyle(10, HORIZ_DIR, 3);
    settextjustify(1, 1);
    outtextxy(1155, 540, "What animal is this?");
    
    Box b(0, 670);
    b.setColor(COLOR(0, 0, 0), COLOR(189, 183, 107));

    Bomb c(300, 200, 40);
    c.setColor(COLOR(15, 0, 0), COLOR(220, 20, 60));
    c.setAlpha('!');


    string answer = "FOX";

    Alphabet* a;
    int n = answer.length();
    a = new Alphabet[n];

    for (int i = 0; i < n; i++)
    {
        a[i].setColor(COLOR(0, 0, 0), COLOR(30, 144, 255));
        a[i].setAlpha(answer[i]);
    }

    Shape* s[3] = { &b, &c };
    for (int i = 0; i < 2; i++)
    {
        s[i]->draw();
    }


    Score score(0);
    Life life(3);

    char ch;
    score.show();
    life.show();

    do
    {
        c.move();
        a->move();
        b.draw();

        if (kbhit())
        {
            ch = getch();
            b.move(ch);
        }

        if ((c.getX() >= b.getX()) && (c.getY() + 70 > b.getY()) && (c.getX() <= b.getX() + 100)
            && (c.getY() + 70 > b.getY()))
        {
            life.minusLife();
            life.show();
            c.undraw();
            c.positionDrop();
            PlaySound(TEXT("Error.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }

        if ((a->getLeft() <= b.getX() + 100) && (a->getTop() + 70 > b.getY())
            && (a->getRight() >= b.getX()) && (a->getBottom() + 70 > b.getY()))
        {
            score.addScore();
            score.show();
            a->undraw();
            a->positionDrop();

            PlaySound(TEXT("Match.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }

        delay(20);
    } while (ch != 27 && life.getLife() != 0);

    getch();
    endScreen();
    getch();

    return 0;
}

