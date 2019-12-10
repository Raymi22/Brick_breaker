#include <stdio.h>
#include <graphics.h>
#include "bball.h"
#include "bplatform.h"
#include "bmap.h"
#include "bscore.h"
#include "bbrick2.h"



using namespace std;
////////////////////////////////// Window parameters //////////////////////////////////
int wx=500, wy=600;
///////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////// Object parameters ////////////////////////////////////
s_ball ball ={0, 0, 20, 1, -1}; //ball
s_platform platform ={wx/2-40, wy-5-25, wx/2+40, wy-5}; // platform
s_map map={0, 50, wx-1, wy};  // map
int ps=1; //steps
s_brick wall[4][5];
char mes[15]="Score: ";
///////////////////////////////////////////////////////////////////////////////////////




int main()
{

    initwindow(wx,wy);

    ball.x=getmaxx()/2;
    ball.y=400;

    char c=getch();
    initWall(map, wall);
    int page=0;

    while (c!='x')
    {
        // page management //
        setactivepage(page);
        cleardevice();
        setvisualpage(1-page);
        /////////////////////





        //draw the objects
        drawScoreboard(wall);
        drawMap(map);
        drawBall(ball);
        drawWall(wall);
        drawPlatform(platform);

        //check for events and change direction
        setSpeed(ball, touchPlatform(ball, platform), touchMap(map, ball), touchBrick(ball, wall));

        // move objects
        moveBall(ball);
        movePlatform(platform, map);

        // page management //
        page=1-page;
        /////////////////////

        delay(1);
        //getch();
    }

    return 0;
}


