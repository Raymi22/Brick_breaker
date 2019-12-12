#include <stdio.h>
#include <graphics.h>
#include "bball.h"
#include "bplatform.h"
#include "bmap.h"
#include "bscore.h"
#include "bbrick2.h"
#include "initwin.h"



using namespace std;
////////////////////////////////// Window parameters //////////////////////////////////
int wx=500, wy=600;
///////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// Object parameters ////////////////////////////////////
s_ball ball; //ball
s_platform platform ={wx/2-40, wy-5-25, wx/2+40, wy-5}; // platform
s_map map={0, 50, wx-1, wy};  // map
s_brick wall[4][5];
///////////////////////////////////////////////////////////////////////////////////////




int main()
{
    initwindow(wx,wy);
    char key='1';
    int page=0;
    int score=0;

    while(key!='x')
    {
        startscreen();
        initWall(map, wall, key-'0');
        initBall(&ball);
        score=0;
        key=getch();
        while (score!=26 and touchMap(map, ball)!=4)
        {
            // page buffering //
            setactivepage(page);
            cleardevice();
            setvisualpage(1-page);
            /////////////////////

            //get the score
            score=getScore(wall);

            //draw the objects
            drawMap(map);
            drawScoreboard(wall, score);
            drawBall(ball);
            drawWall(wall);
            drawPlatform(platform);

            //check for events and change direction of ball

            setSpeed(&ball, touchPlatform(ball, platform), touchMap(map, ball), touchBrick(ball, wall));

            // move objects
            moveBall(&ball);
            movePlatform(&platform, map);

            // page management //
            page=1-page;
            /////////////////////
            delay(10);
            //getch();
        }
        if (score==26) winScreen(score);
        else gameover(score);
        delay(1000);
        key=getch();
    }

    return 0;
}


