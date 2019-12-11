#include "bcollisions.h"
#include <stdio.h>
#include <math.h>

int touchCorner(s_ball ball, int x, int y)
{
    if (sqrt(pow(ball.x-x, 2)+pow(ball.y-y, 2))<=ball.r) return 1;
    else return 0;
}

int touchHorizontalLine(s_ball ball,int x1,int y1,int x2,int y2)
{
    if((ball.x<x2 && ball.x>x1))
    {
        if(abs(ball.y-y1)==ball.r) return 1; //touches horizontal line
    }
    return 0; //no collisions
}

int touchVerticalLine(s_ball ball,int x1,int y1,int x2,int y2)
{
    if(ball.y<y2 && ball.y>y1){
        if(abs(ball.x-x1)==ball.r) return 1; //touches vertical line
    }
    return 0; //no collisions
}



int touchMapCorner(s_ball ball, int x, int y)
{
    if (abs(ball.x-x)<=ball.r && abs(ball.x-x)==abs(ball.y-y)) return 1;
    else return 0;
}
