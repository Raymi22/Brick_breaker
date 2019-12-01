/**************************************/
/* bball.h - contains functions related to the ball */
/* Author: Nemeth Raymond */
/**************************************/


#ifndef BBALL_H_INCLUDED
#define BBALL_H_INCLUDED

#include <graphics.h>
#include "bmap.h"
#include "bplatform.h"

typedef struct s_ball
{
    int x, y, r;
    int xSpeed, ySpeed;
};

// touchBorder checks for any collision between ball and borders and returns a number corresponding to a border//
//Returns:  1  right side
//          2  left side
//          3  bottom
//          4  top
//          5  top right corner
//          5  bottom right corner
//          7  top left corner
//          8  bottom left corner
int touchBorder(s_ball ball, s_map map);

int touchPlatform(s_ball ball, s_platform platform);

void drawBall(s_ball &ball);
void setSpeed(s_ball &ball, s_map map, s_platform platform);
void moveBall(s_ball &ball);

#endif // BBALL_H_INCLUDED
