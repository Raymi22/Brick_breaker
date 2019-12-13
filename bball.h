/**************************************/
/* bball.h - contains functions related to the ball */
/* Author: Nemeth Raymond */
/**************************************/

#ifndef BBALL_H_INCLUDED
#define BBALL_H_INCLUDED

#include <graphics.h>

#define TEST 10

typedef struct
{
    int x, y, r;
    int xSpeed, ySpeed;
} s_ball;

void drawBall (s_ball ball);
void setSpeed (s_ball *ball, int platformEvent, int mapEvent, int brickEvent);
void moveBall (s_ball *ball);
void initBall (s_ball *ball);

#endif // BBALL_H_INCLUDED
