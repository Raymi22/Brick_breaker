#include "bcollisions.h"

int touchCorner(s_ball ball, int x, int y)
{
    if (sqrt(pow(ball.x-x, 2)+pow(ball.y-y, 2))<=ball.r) return 1;
    else return 0;
}

int touchLine(s_ball ball, int x1, int y1, int x2, int y2)
{

}

int touchMapCorner(s_ball ball, int x, int y)
{
    if (abs(ball.x-x)<=ball.r and abs(ball.x-x)==abs(ball.y-y)) return 1;
    else return 0;
}
