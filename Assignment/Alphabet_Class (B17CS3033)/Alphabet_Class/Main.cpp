#include "Alphabet.hpp"

int main(){
	int screenWidth = getmaxwidth();
	int screenHeight = getmaxheight();
	initwindow( screenWidth, screenHeight, "Alphabet");

	string soundFile = "Pim Poy Long.wav";
	PlaySound(TEXT(soundFile.c_str()), NULL, SND_ASYNC);
	getch();

	Alphabet alpha[8]={Alphabet(300, 100, 100, 100),Alphabet(400, 100, 100, 100),
						Alphabet(500, 100, 100, 100),Alphabet(600, 100, 100, 100),
						Alphabet(700, 100, 100, 100),Alphabet(800, 100, 100, 100),
						Alphabet(900, 100, 100, 100),Alphabet(1000, 100, 100, 100)};

	alpha[0].setColor(COLOR(255, 0, 0), COLOR(148,0,211));
	alpha[0].setAlpha('R');
	alpha[0].draw();

	alpha[1].setColor(COLOR(255, 0, 0), COLOR(127,255,0));
	alpha[1].setAlpha('G');
	alpha[1].draw();

	alpha[2].setColor(COLOR(255, 0, 0), COLOR(255,69,0));
	alpha[2].setAlpha('I');
	alpha[2].draw();

	alpha[3].setColor(COLOR(255, 0, 0), COLOR(255,0,255));
	alpha[3].setAlpha('A');
	alpha[3].draw();

	alpha[4].setColor(COLOR(255, 0, 0), COLOR(255,215,0));
	alpha[4].setAlpha('L');
	alpha[4].draw();

	alpha[5].setColor(COLOR(255, 0, 0), COLOR(0,0,255));
	alpha[5].setAlpha('O');
	alpha[5].draw();

	alpha[6].setColor(COLOR(255, 0, 0), COLOR(220,20,60));
	alpha[6].setAlpha('L');
	alpha[6].draw();

	delay(800);
	setcolor(COLOR(255,255,255));
	setbkcolor(BLACK);
	settextstyle(3, HORIZ_DIR, 18);
	outtextxy(10, 10, "Ready!!!.. Spell!!!");
	delay(1000);
	setcolor(COLOR(0,0,0));
	outtextxy(10, 10, "Ready!!!.. Spell!!!");
	delay(900);
	
	while (!kbhit()) {
		
		alpha[0].undraw();
		alpha[0].setY(alpha[0].getY() + 55);

		for (int i=0; i<6; i++){
		alpha[0].draw();
		delay(150);
		}
		alpha[3].undraw();
		alpha[3].setY(alpha[3].getY() + 83);

		for (int i=0; i<6; i++){
		alpha[3].draw();
		delay(150);
		}
		alpha[5].undraw();
		alpha[5].setY(alpha[5].getY() + 65);

		for (int i=0; i<6; i++){
		alpha[5].draw();
		delay(150);
		}
		alpha[2].undraw();
		alpha[2].setY(alpha[2].getY() + 55);	

		for (int i=0; i<6; i++){
		alpha[2].draw();
		delay(150);
		}
		alpha[4].undraw();
		alpha[4].setY(alpha[4].getY() + 70);

		for (int i=0; i<6; i++){
		alpha[4].draw();	
		delay(150);
		}
		alpha[1].undraw();
		alpha[1].setY(alpha[1].getY() + 50);

		for (int i=0; i<6; i++){
		alpha[1].draw();
		delay(150);
		}

		alpha[6].undraw();
		alpha[6].setY(alpha[6].getY() + 80);

		for (int i=0; i<6; i++){
		alpha[6].draw();
		delay(150);
		}	
		
	}
	return 0;
}
