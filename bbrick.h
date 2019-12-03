#ifndef BBRICK_H_INCLUDED
#define BBRICK_H_INCLUDED
#include <graphics.h>
#include "bball.h"
#include "bmap.h"

typedef s_brick
{
    int left, top, right, bottom;
    int count;
}

int touchBrick(s_ball ball, s_brick brick);

void drawBrick(s_brick brick);  // draws one brick

void drawWall(s_map map) //draws all the bricks

#endif // BBRICK_H_INCLUDED
