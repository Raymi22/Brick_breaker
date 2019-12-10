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


int touchBrick(s_ball ball, s_brick wall[4][5]);//checks the collision between ball and bricks

void drawBrick(s_brick brick);// draws one brick

void drawWall(s_map map); //draws all the bricks

void initWall( s_map map, s_brick wall[4][5]);



#endif // BBRICK_H_INCLUDED
