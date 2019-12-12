#ifndef BBRICK_H_INCLUDED
#define BBRICK_H_INCLUDED
#include <graphics.h>

#include "bbrick.h"
#include "bmap.h"
#include "time.h"


void drawBrick(s_brick brick) //draws one brick
{
    bar(brick.left, brick.top, brick.right, brick.bottom);
}

void initWall(s_map map, s_brick wall[4][5]) //draws the wall made out of 20 bricks
{
    int xstart=map.left+5, ystart=map.top, blength=94, bwidth=40;
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<5;j++)
        {

            wall[i][j].left=(j+1)*xstart+j*blength;
            wall[i][j].top=(i+1)*ystart+bwidth;
            wall[i][j].right=blength+wall[i][j].left;
            wall[i][j].bottom=bwidth+wall[i][j].top;
            wall[i][j].count=1;
        }
        srand(time(NULL));
        int r1, r2;
        for (int i=0; i<2; i++)
        {
            r1=rand()%4; r2=rand()%5;
            if (wall[r1][r2].count>1) i--;
            else wall[r1][r2].count=2;
        }
        for (int i=0; i<2; i++)
        {
            r1=rand()%4; r2=rand()%5;
            if (wall[r1][r2].count>1) i--;
            else wall[r1][r2].count=3;
        }
    }

}

void drawWall(s_brick wall[4][5])
{
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<5;j++)
        {
            if (wall[i][j].count==1)
            drawBrick(wall[i][j]);
            else if (wall[i][j].count==2)
            {
                setcolor(YELLOW);
                drawBrick(wall[i][j]);
                setcolor(15);
            }
            else if (wall[i][j].count==3)
            {
                setcolor(RED);
                drawBrick(wall[i][j]);
                setcolor(15);
            }

        }
    }

}

int touchBrick(s_ball ball, s_brick wall[4][5])
{
    int state=0; //no collision
    for(int i=0;i<4;i++)
    {
        for (int j=0;j<5;j++)
        {
            if (wall[i][j].count>0)
            {
                if (touchCorner(ball, wall[i][j].left, wall[i][j].top)==1 || touchCorner(ball, wall[i][j].top, wall[i][j].right)==1 ||
            touchCorner(ball, wall[i][j].right, wall[i][j].bottom)==1 || touchCorner(ball, wall[i][j].left, wall[i][j].bottom)==1) //todo osszes sarok
            {
                wall[i][j].count--;
                state=1;          // touches any corner
            }
            else
            if (touchVerticalLine(ball, wall[i][j].left, wall[i][j].top, wall[i][j].left, wall[i][j].bottom)==1 ||
                 touchVerticalLine(ball, wall[i][j].right, wall[i][j].top, wall[i][j].right, wall[i][j].bottom)==1)
            {
                wall[i][j].count--;
                state=2;        // touches any vertical side of a brick
            }
            else
            if (touchHorizontalLine(ball, wall[i][j].left, wall[i][j].top, wall[i][j].right, wall[i][j].top)==1 ||
                 touchHorizontalLine(ball, wall[i][j].left, wall[i][j].bottom, wall[i][j].right, wall[i][j].bottom)==1)
            {
                wall[i][j].count--;
                state=3;        // touches any horizontal side of a brick
            }
            }
        }
    }
    return state;
}

#endif // BBRICK_H_INCLUDED
