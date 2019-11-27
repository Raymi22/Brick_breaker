#include <graphics.h>
#include "bball.h"


int eventBall(s_ball ball, int wx, int wy)
{
    // Checks for any event related to the ball //
    if (ball.x+ball.r<=wx && ball.x-ball.r>=0 && ball.y+ball.r<=wy && ball.y-ball.r>=0) return 0;
    else if (ball.x-ball.r>=0 && ball.y+ball.r<=wy && ball.y-ball.r>=0  && ball.x+ball.r>=wx) return 1;  //     1 if ball touches right side
    else if (ball.x+ball.r<=wx && ball.y+ball.r<=wy && ball.y-ball.r>=0  && ball.x-ball.r<0 ) return 2; //  2 if ball touches left side
    else if (ball.x+ball.r<=wx && ball.x-ball.r>=0 && ball.y-ball.r>=0 && ball.y+ball.r>wy ) return 3; //   3 if ball touches bottom
    else return 4; //                                                                                       4 if ball touches top
}

void setSpeed(s_ball &ball, int wx, int wy)
{
    int e=eventBall(ball, wx, wy);
    if (e==1 or e==2) ball.xSpeed=0-ball.xSpeed;
    if (e==3 or e==4) ball.ySpeed=0-ball.ySpeed;
}

void moveBall( s_ball &ball )
{
    ball.x+=ball.xSpeed;
    ball.y+=ball.ySpeed;
}

void drawBall( s_ball &ball )
{
    circle( ball.x, ball.y, ball.r );
    floodfill( ball.x, ball.y, 15 );
}
