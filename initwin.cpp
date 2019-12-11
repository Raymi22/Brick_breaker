#include "initwin.h"

void startscreen(int x, int y){
    //int graphicdriver=DETECT,graphicmode;

	//calling initgraph with parameters
	//initgraph(&graphicdriver,&graphicmode,"c:\\turboc3\\bgi");
	//initilizing variables
    initwindow(x,y);
	int x1=250, y1=100;


        settextjustify(CENTER_TEXT, CENTER_TEXT);

		settextstyle(8, HORIZ_DIR, 6);
		outtextxy(x1, y1, "Brick Breaker");

        settextstyle(8, HORIZ_DIR, 3);
		outtextxy(x1, y1+150, "Press any key to start!");

		settextstyle(8, HORIZ_DIR, 1);
		outtextxy(x1, y1+300, "Move the platform with -> and <- buttons.");
}

void winScreen(int x, int y, int s)
{
    setactivepage(1);
    setvisualpage(1);
    cleardevice();

    initwindow(x,y);
    int x1=250, y1=100;

    char vs[2];
    sprintf(vs, "%d", s);
    char *vscore[2]={vs};

    settextjustify(CENTER_TEXT, CENTER_TEXT);

    settextstyle(8, HORIZ_DIR, 6);
    outtextxy(x1, y1, "You won!");

    settextstyle(8, HORIZ_DIR, 3);
    outtextxy(x1, y1+150, "Your score is:");
    outtextxy(x1, y1+130, *vscore);

    settextstyle(8, HORIZ_DIR, 1);
    outtextxy(x1, y1+300, "Press X to exit or R to start a new game");
}

void gameover(int x, int y, int s)
{
    setactivepage(1);
    setvisualpage(1);
    cleardevice();

    initwindow(x,y);
    int x1=250, y1=100;

    char vs[2];
    sprintf(vs, "%d", s);
    char *vscore[2]={vs};

    settextjustify(CENTER_TEXT, CENTER_TEXT);

    settextstyle(8, HORIZ_DIR, 6);
    outtextxy(x1, y1, "You lost!");

    settextstyle(8, HORIZ_DIR, 3);
    outtextxy(x1, y1+150, "Your score is:");
    outtextxy(x1, y1+130, *vscore);

    settextstyle(8, HORIZ_DIR, 1);
    outtextxy(x1, y1+300, "Press X to exit or R to start a new game");
}
