#ifndef BBRICK2_H_INCLUDED
#define BBRICK2_H_INCLUDED

#include <graphics.h>
#include "bball.h"
#include "bmap.h"

typedef struct
{
    int left, top, right, bottom;
    int count;
} s_brick;


void initWall(s_map map, s_brick wall[5][5], int mapOption); //draws the wall made out of 20 bricks

void drawBrick(s_brick brick, int c);// draws one brick

void drawWall(s_brick wall[5][5]);

int touchBrick(s_ball ball, s_brick wall[5][5]); //checks the collision between ball and bricks



#endif // BBRICK2_H_INCLUDED
