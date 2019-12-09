#ifndef BBRICK_H_INCLUDED
#define BBRICK_H_INCLUDED
#include <graphics.h>
#include "bball.h"
#include "bmap.h"

typedef struct
{
    int left, top, right, bottom;
    int count;
}s_brick;

int touchBrick(s_ball ball, s_brick brick);//checks the collision between ball and bricks

void drawBrick(s_brick brick, s_map map);// draws one brick

void drawWall(s_map map) //draws all the bricks

#endif // BBRICK_H_INCLUDED
