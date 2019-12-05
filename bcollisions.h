#ifndef BCOLLISIONS_H_INCLUDED
#define BCOLLISIONS_H_INCLUDED
#include <math.h>
#include "bball.h"

//returns 0 when no collision
//returns 1 when there is collision
int touchCorner(s_ball ball, int x, int y);

int touchLine(s_ball ball, int x1, int y1, int x2, int y2);

int touchMapCorner(s_ball ball, int x, int y);

#endif // BCOLLISIONS_H_INCLUDED
