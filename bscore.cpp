#include "bscore.h"

void drawScoreboard(s_brick wall[4][5])
{
    char *title[15]={"Brick Breaker"};
    char *score[15]={"Score"};
    char *vscore[2]={"10"};

    rectangle(0, 0, 500, 50);
    settextjustify(1, 1);  //positions text
    settextstyle(4, 0, 3);
    outtextxy(250, 25, *title);

    settextjustify(2, 0);  //positions text
    settextstyle(4, 0, 1);
    outtextxy(500-5, 25, *score);

    settextjustify(2, 0);  //positions text
    settextstyle(4, 0, 1);
    outtextxy(500-25, 40, *vscore);
}

int getScore(s_brick wall[4][5])
{
    int s=26;
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<5; j++)
        s-=wall[i][j].count;
    }

    return s;
}
