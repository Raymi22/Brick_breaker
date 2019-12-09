#include <stdio.h>
#include <graphics.h>
#include "bball.h"
#include "bplatform.h"
#include "bmap.h"
#include "bscore.h"
#include "bbrick.h"



using namespace std;
////////////////////////////////// Window parameters //////////////////////////////////
int wx=500, wy=600;
///////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////// Object parameters ////////////////////////////////////
s_ball ball ={0, 0, 20, 2, -2}; //ball
s_platform platform ={wx/2-40, wy-5-25, wx/2+40, wy-5}; // platform
s_map map={0, 50, wx-1, wy};  // map
int ps=2; //steps
s_brick wall[4][5];
char mes[15]="Score: ";
///////////////////////////////////////////////////////////////////////////////////////




int main()
{

    initwindow(wx,wy);

    ball.x=getmaxx()/2;
    ball.y=200;

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

        drawScoreboard(wall);
        drawMap(map);

        //draw the filled circle
        drawBall(ball);

        bar (platform.left, platform.top, platform.right, platform.bottom);


        //check for events and change direction
        setSpeed(ball, touchPlatform(ball, platform), touchMap(map, ball), touchBrick(ball, wall));

        // move the ball
        moveBall(ball);

        //moving the platform
        if (GetAsyncKeyState(VK_RIGHT)) {platform.left+=ps; platform.right+=ps;}
        if (GetAsyncKeyState(VK_LEFT)) {platform.left-=ps; platform.right-=ps;}



        // page management //
        page=1-page;
        /////////////////////

        delay(3);
    }

    return 0;
}


