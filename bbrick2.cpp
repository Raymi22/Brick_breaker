#ifndef BBRICK_H_INCLUDED
#define BBRICK_H_INCLUDED
#include <graphics.h>
#include <stdio.h>

#include "bbrick2.h"
#include "bcollisions.h"
#include "time.h"

void drawBrick(s_brick brick, int c)
{
    setfillstyle(1, c);
    bar(brick.left, brick.top, brick.right, brick.bottom);
    //floodfill(brick.left+2, brick.top+2, c);
    setfillstyle(1, 15);
}

void drawWall(s_brick wall[5][5])
{
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {

            if (wall[i][j].count==1)
            {
                drawBrick(wall[i][j], 2);
            }
            else if (wall[i][j].count==2)
            {
                drawBrick(wall[i][j], 14);
            }
            else if (wall[i][j].count==3)
            {
                drawBrick(wall[i][j], 4);
            }

        }
    }

}

void initWall(s_map map, s_brick wall[5][5]) //initialises the wall made out of 20 bricks
{
    switch(initWall)
    {

    case 1:
    int xstart=map.left+5, ystart=map.top+5, blength=94, bwidth=40;
    int spacing=5;
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {

            wall[i][j].left=xstart+(j+1)*spacing+j*blength;
            wall[i][j].top=ystart+(i+1)*spacing+i*bwidth;
            wall[i][j].right=blength+wall[i][j].left;
            wall[i][j].bottom=bwidth+wall[i][j].top;
            wall[i][j].count=1;
        }
    }
    srand(time(NULL));
    int r1, r2;
    for (int i=0; i<2; i++)
    {
        r1=rand()%5;
        r2=rand()%5;
        if (wall[r1][r2].count>1) i--;
        else wall[r1][r2].count=2;
    }
    srand(time(NULL));
    for (int i=0; i<2; i++)
    {
        r1=rand()%5;
        r2=rand()%5;
        if (wall[r1][r2].count>1) i--;
        else wall[r1][r2].count=3;
    }
    break;
    case 2:
    int xstart=map.left, ystart=map.top, blength=94, bwidth=40;
    int spacing=5;
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            wall[i][j].left=xstart+(j+1)*spacing+j*blength;
            wall[i][j].top=ystart+(i+1)*spacing+i*bwidth;
            wall[i][j].right=blength+wall[i][j].left;
            wall[i][j].bottom=bwidth+wall[i][j].top;
            wall[i][j].count=0;
            if (i==j)   wall[i][j].count=1;
            else if (i+j==4) wall[i][j].count=1;
            else if (i==1 and j==2 or i==2 and j==1 or i==2 and j==3 or i==3 and j==2)
            wall[i][j].count=1;
        }
    }

    srand(time(NULL));
    int r1, r2;
    for (int i=0; i<5; i++)
    {
        r1=rand()%5;
        r2=rand()%5;
        if (wall[r1][r2].count>1 || wall[r1][r2].count==0) i--;
        else wall[r1][r2].count=2;
    }
    srand(time(NULL));
    for (int i=0; i<4; i++)
    {
        r1=rand()%5;
        r2=rand()%5;
        if (wall[r1][r2].count>1 || wall[r1][r2].count==0) i--;
        else wall[r1][r2].count=3;
    }
    break;

    case 3:
    int xstart=map.left, ystart=map.top, blength=94, bwidth=40;
    int spacing=5;
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            wall[i][j].left=xstart+(j+1)*spacing+j*blength;
            wall[i][j].top=ystart+(i+1)*spacing+i*bwidth;
            wall[i][j].right=blength+wall[i][j].left;
            wall[i][j].bottom=bwidth+wall[i][j].top;
            wall[i][j].count=0;
            if (i==0 && j==2)
                wall[i][j].count=1;
            if (i==1 && j==1 || i==1 && j==3)
                wall[i][j].count=1;
            if (i==2)
                wall[i][j].count=1;
            if (i==3 and j==0 or i==3 and j==4)
                wall[i][j].count=1;
            if (i==4 and j==0 or i==4 and j==4)
                wall[i][j].count=1;
        }
    }

    srand(time(NULL));
    int r1, r2;
    for (int i=0; i<2; i++)
    {
        r1=rand()%5;
        r2=rand()%5;
        if (wall[r1][r2].count>1 || wall[r1][r2].count==0) i--;
        else wall[r1][r2].count=2;
    }
    srand(time(NULL));
    for (int i=0; i<6; i++)
    {
        r1=rand()%5;
        r2=rand()%5;
        if (wall[r1][r2].count>1 || wall[r1][r2].count==0) i--;
        else wall[r1][r2].count=3;
    }
    break;
    }


int touchBrick(s_ball ball, s_brick wall[5][5])
{
    int state=0; //no collision
    for(int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            if (wall[i][j].count>0)
            {
                if (touchCorner(ball, wall[i][j].left, wall[i][j].top)==1 || touchCorner(ball, wall[i][j].right, wall[i][j].top )==1 ||
                        touchCorner(ball, wall[i][j].right, wall[i][j].bottom)==1 || touchCorner(ball, wall[i][j].left, wall[i][j].bottom)==1) //todo osszes sarok
                {
                    wall[i][j].count--;
                    state=1;          // touches any corner
                }
                else if (touchVerticalLine(ball, wall[i][j].left, wall[i][j].top, wall[i][j].left, wall[i][j].bottom)==1 ||
                         touchVerticalLine(ball, wall[i][j].right, wall[i][j].top, wall[i][j].right, wall[i][j].bottom)==1)
                {
                    wall[i][j].count--;
                    state=2;        // touches any vertical side of a brick
                }
                else if (touchHorizontalLine(ball, wall[i][j].left, wall[i][j].top, wall[i][j].right, wall[i][j].top)==1 ||
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
