#include "bscore.h"
#include <stdio.h>

char title[15]="Brick Breaker";
char score[15]="Score";


void drawScoreboard(s_brick wall[4][5], int s)
{
    char vs[3];
    int tens=s/10;
    int units=s%10;
    vs[0]=tens+'0';
    vs[1]=units+'0';
    vs[3]=' ';

    char *vscore=vs;

    rectangle(0, 0, 499, 50);
    settextjustify(1, 1);  //positions text
    //settextstyle(4, 0, 3);
    outtextxy(250, 25, title);

    settextjustify(2, 0);  //positions text
    //settextstyle(4, 0, 1);
    outtextxy(500-5, 25, score);

    //settextstyle(4, 0, 1);
    outtextxy(500-25, 40, vscore);
}

int getScore(s_brick wall[5][5])
{
    int s=26;
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        s-=wall[i][j].count;
    }
    return s;
}
