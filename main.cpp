#include <stdio.h>
#include <graphics.h>
#include <string.h>

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
//////////////////////////////// Objects ////////////////////////////////////
s_ball ball; //ball
s_platform platform; // platform
s_map map; // map
s_brick wall[4][5];
///////////////////////////////////////////////////////////////////////////////////////

int main()
{
    initwindow(wx,wy);
    initMap(&map, wx, wy);
    char key='1';
    int page=0;
    int score=0;

    while(key!='x')
    {
        startscreen();
        initWall(map, wall, key-'0');
        initBall(&ball);
        initPlatform(&platform, wx, wy);
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
        }
        if (score==26) winScreen(score);
        else gameover(score);
        delay(1000);

        ////////////GETTING THEE RIGHT KEYBOARD VALUES//////////////
        char *result=NULL;
        char string[]="x123";
        do
        {
            key=getch();
            result=strchr(string, key);
        }
        while(result==NULL);
        /////////////////////////////////////////////////////////////
    }

    return 0;
}


