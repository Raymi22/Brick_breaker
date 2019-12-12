#include <graphics.h>
#include "bball.h"
#include <stdio.h>

void setSpeed(s_ball &ball, int platformEvent, int mapEvent, int brickEvent)
{
    if (platformEvent==2 || mapEvent==2 || brickEvent==2) ball.xSpeed=0-ball.xSpeed;       //inverses speed on x axe
    else if (platformEvent==3 || mapEvent==3 || brickEvent==3) ball.ySpeed=0-ball.ySpeed;        //inverses speed on y axe
    else if (platformEvent==1 || mapEvent==1 || brickEvent==1)        // inverses speed on both axes
    {
        ball.xSpeed=0-ball.xSpeed;
        ball.ySpeed=0-ball.ySpeed;
    }
}

void moveBall( s_ball &ball )
{
    ball.x+=ball.xSpeed;
    ball.y+=ball.ySpeed;
}

void drawBall( s_ball &ball )
{
    setfillstyle(1, 15);
    fillellipse( ball.x, ball.y, ball.r, ball.r );
    printf("%d, %d, %d\n", ball.x, ball.y, ball.r);
}

void initBall(s_ball &ball)
{
    int ps=1; //step value
    ball.x=500/2;
    ball.y=400;
    ball.r=20;
    ball.xSpeed=ps;
    ball.ySpeed=-ps;
}
