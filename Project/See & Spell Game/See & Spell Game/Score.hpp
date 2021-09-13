#ifndef SCORE_H
#define SCORE_H

void mainScreen();
void endScreen();

class Score
{
private:
    int score;

public:
    Score(int _score = 0)
    {
        score = _score;
    }
    void addScore()
    {
        score++;
    }
    void show()
    {
        char* s;
        s = new char[10];
        itoa(score, s, 10);

        setbkcolor(BLACK);
        setcolor(WHITE);
        settextstyle(10, HORIZ_DIR, 5);
        settextjustify(1, 1);
        outtextxy(1105, 60, s);

        outtextxy(1000, 60, "SCORE:");
        settextstyle(10, HORIZ_DIR, 5);
        settextjustify(1, 1);

        delete[] s;
    }
};

class Life
{
private:
    int life;

public:
    Life(int _life = 0)
    {
        life = _life;
    }
    int getLife()
    {
        return life;
    }

    void minusLife()
    {
        life--;
    }

    void show()
    {
        char* l;
        l = new char[10];
        itoa(life, l, 10);
        setcolor(WHITE);

        setbkcolor(BLACK);
        setcolor(WHITE);
        settextstyle(10, HORIZ_DIR, 5);
        settextjustify(1, 1);


        outtextxy(1230, 60, "LIFE:");
        settextstyle(10, HORIZ_DIR, 5);
        settextjustify(1, 1);
        outtextxy(1310, 60, l);
        delete[] l;
    }
};
void mainScreen()
{
    readimagefile("main.jpg", 0, 0, 1360, 750);
    getch();
    cleardevice();
}

void endScreen()
{
    cleardevice();
    readimagefile("end.jpg", 0, 0, 1360, 750);
    PlaySound(TEXT("GameOver.wav"), NULL, SND_FILENAME | SND_ASYNC);
    getch();
}
#endif
