#include "initwin.h"

void startscreen()
{
    setactivepage(1);
    setvisualpage(1);
    cleardevice();
    int x1=250, y1=100;

    settextjustify(CENTER_TEXT, CENTER_TEXT);

    settextstyle(8, HORIZ_DIR, 6);
    outtextxy(x1, y1, "Brick Breaker");

    settextstyle(8, HORIZ_DIR, 3);
    outtextxy(x1, y1+150, "Press any key to start!");

    settextstyle(8, HORIZ_DIR, 1);
    outtextxy(x1, y1+300, "Move the platform with -> and <- buttons.");
}

void winScreen(int s)
{
    setactivepage(1);
    setvisualpage(1);
    cleardevice();


    char vs[3];
    int tens=s/10;
    int units=s%10;
    vs[0]=tens+'0';
    vs[1]=units+'0';
    vs[3]=' ';
    char *vscore=vs;

    int x1=250, y1=100;
    settextjustify(CENTER_TEXT, CENTER_TEXT);

    settextstyle(8, HORIZ_DIR, 6);
    outtextxy(x1, y1, "You won!");

    settextstyle(8, HORIZ_DIR, 3);
    outtextxy(x1, y1+150, "Your score is:");
    outtextxy(x1, y1+200, vscore);

    settextstyle(8, HORIZ_DIR, 1);
    outtextxy(x1, y1+300, "Press X to exit.");

    settextstyle(8, HORIZ_DIR, 1);
    outtextxy(x1, y1+350, "Press 1, 2 or 3 to choose another map.");
}

void gameover(int s)
{
    setactivepage(1);
    setvisualpage(1);
    cleardevice();



    char vs[3];
    int tens=s/10;
    int units=s%10;
    vs[0]=tens+'0';
    vs[1]=units+'0';
    vs[3]=' ';
    char *vscore=vs;

    int x1=250, y1=100;
    settextjustify(CENTER_TEXT, CENTER_TEXT);

    settextstyle(8, HORIZ_DIR, 6);
    outtextxy(x1, y1, "You lost!");

    settextstyle(8, HORIZ_DIR, 3);
    outtextxy(x1, y1+150, "Your score is:");
    outtextxy(x1, y1+200, vscore);

    settextstyle(8, HORIZ_DIR, 1);
    outtextxy(x1, y1+300, "Press X to exit.");

    settextstyle(8, HORIZ_DIR, 1);
    outtextxy(x1, y1+350, "Press 1, 2 or 3 to choose another map.");
}
