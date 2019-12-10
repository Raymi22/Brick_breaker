#include <graphics.h>

#include "bmap.h"

#define mapLeft 0
#define mapRight 500
#define mapTop 50
#define mapBottom 600

void drawMap(s_map map)
{
    //(0, 0, map.right, map.top);
    line(map.left, map.top, map.left, map.bottom);
    line(map.right, map.top, map.right, map.bottom);
}

int touchMap(s_map map, s_ball ball)
{
    if (touchMapCorner(ball, map.left, map.top) || touchMapCorner(ball, map.right, map.top)) return 1; // ball touches top corners
    if (touchVerticalLine(ball, map.left, map.top, map.left, map.bottom) || touchVerticalLine(ball, map.right, 0, map.right, map.bottom)) return 2; // ball touches left or right side
    if (touchHorizontalLine(ball, map.left, map.top, map.right, map.top)) return 3; // ball touches top of map
    if (touchHorizontalLine(ball, map.left, map.bottom+2*ball.r, map.right, map.bottom+2*ball.r)) return 4; //ball gets out of map
    return 0; // ball does not touch anything
}


