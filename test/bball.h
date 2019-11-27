#ifndef BBALL_H_INCLUDED
#define BBALL_H_INCLUDED

#include <graphics.h>

typedef struct s_ball
{
    int x, y, r;
    int xSpeed, ySpeed;
};

//int wx=600, wy;
//s_ball ball;

int eventBall(s_ball ball, int wx, int wy);
//Checks for events related to the ball //
//Returns:  1 if ball touches right side
//          2 if ball touches left side
//          3 if ball touches bottom
//          4 if ball touches top

void drawBall(s_ball &ball);

void setSpeed(s_ball &ball, int wx, int wy);

void moveBall(s_ball &ball);

#endif // BBALL_H_INCLUDED
