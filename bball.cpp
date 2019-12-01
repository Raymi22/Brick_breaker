#include <graphics.h>
#include "bball.h"
#include "bplatform.h"
#include "bmap.h"

int touchBorder(s_ball ball, s_map map)
{
    // Checks for any collision between ball and borders //
    int state=0;
    if (ball.x+ball.r>=map.right)// right side
    {
        if (ball.y-ball.r<=map.top) state = 5;             // top right corner -> 5
        else if (ball.y+ball.r>=map.bottom) state = 6;     // bottom right corner -> 6
        else state = 1;                                    // right side -> 1
    }
    else if (ball.x-ball.r<=map.left ) //left side
    {
        if (ball.y-ball.r<=map.top) state = 7;              // top left corner -> 7
        else if (ball.y+ball.r>=map.bottom) state = 8;      // bottom left corner -> 8
        else state = 2;                                     // left side -> 2
    }
    else if (ball.y+ball.r>=map.bottom) state = 3;          // bottom -> 3
    else if (ball.y-ball.r<=map.top) state = 4;             // top -> 4
    return state;
}


//  REBUT !!!!!!!!
int touchPlatform(s_ball ball, s_platform platform) //  REBUT !!!!!!!!
{
    int state=0;                                            // 0 if ball and platform do not collide
    if (ball.y+ball.r==platform.top)
    {
        if (ball.x<=platform.right && ball.x>=platform.left) state=1; //ball touches top of platform
    }
    if (ball.y+ball.r>=platform.top and ball.y<platform.top)
    {
        if (ball.x-ball.r<=platform.right and ball.x>platform.right) state=2; //lower half of ball touches right side of platform
        else if (ball.x-ball.r<=platform.left and ball.x>platform.left) state=3; //lower half of ball touches left side of ball
    }
    else if (ball.y>platform.top)
    {
        if (ball.x-ball.r==platform.right || ball.x+ball.r==platform.left) state=4; //other sides of the ball touch the platform
    }
    return state;
}

void setSpeed(s_ball &ball, s_map map, s_platform platform)
{
    int be=touchBorder(ball, map);
    int pe=touchPlatform(ball, platform);
    if (be==1 || be==2 || pe==4) ball.xSpeed=0-ball.xSpeed;             //iverses speed on x axe
    else if (be==3 || be==4 || pe==1) ball.ySpeed=0-ball.ySpeed;        //iverses speed on y axe
    else if (be==5 || be==7 || be==6 || be==8 || pe==2 || pe==3)        // inverses speed on both axes
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
    circle( ball.x, ball.y, ball.r );
    floodfill( ball.x, ball.y, 15 );
}
